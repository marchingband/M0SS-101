#include "bflb_flash.h"
#include "bflb_mtimer.h"
#include "board.h"
#include "midi.h"
#include "gpio.h"
#include "flash.h"
#include "bl616_glb.h"

#define SECTOR_SIZE 0x1000 // 4096

/* From build/build_out/partition.bin:
 *   media   @ 0x378000, size 0x71000
 *   DATA    @ 0x3F3000, size 0x5000
 */
#define MEDIA_PART_BASE 0x378000
#define MEDIA_PART_SIZE 0x071000
#define DATA_PART_BASE  0x3F3000
#define DATA_PART_SIZE  0x005000

#define CONFIG_BASE DATA_PART_BASE
#define PRESET_BASE MEDIA_PART_BASE

#define CONFIG_SCHEMA_VERSION 2U
#define CONFIG_MAGIC_NORMAL 9
#define CONFIG_MAGIC_DUAL_ENV 10

#define NUM_MODS NUM_BUTTONS
#define NUM_ALTS NUM_BUTTONS
#define NUM_SELS NUM_BUTTONS
#define NUM_ALTSELS NUM_BUTTONS
#define NUM_ASBS NUM_BUTTONS

#define SCHEMA1_NORMAL_NUM_CC 44
#define SCHEMA1_DUAL_ENV_NUM_CC 54
#define SCHEMA1_PANEL_FLOATS (NUM_MODS + NUM_ALTS + NUM_SELS + NUM_ALTSELS + NUM_ASBS)

#define SCHEMA2_PARAM_VALUES 128
#define SCHEMA2_CC_MAP_OFFSET SCHEMA2_PARAM_VALUES
#define NUM_FLOATS (SCHEMA2_PARAM_VALUES + NUM_CC_MAP)
#define NUM_BYTES_PER_PRESET (NUM_FLOATS * sizeof(float))
#define PRESET_REGION_BYTES (SECTOR_SIZE * NUM_PRESETS)

#if (SECTOR_SIZE > DATA_PART_SIZE)
#error "Config sector does not fit in DATA partition"
#endif

#if (PRESET_REGION_BYTES > MEDIA_PART_SIZE)
#error "Preset sectors do not fit in media partition"
#endif

extern int cur_midi_chan;
extern bool is_initial_boot;

static float presets[NUM_PRESETS][NUM_FLOATS];

static int current_slot = -1;
static uint8_t runtime_cc_map[NUM_CC_MAP] = {0};
static bool midi_chan_persist_pending = false;
static uint64_t midi_chan_persist_due_us = 0;

#define MIDI_CHAN_PERSIST_DEBOUNCE_US (1000000ULL)

static struct Config default_config = {
    .empty = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true }, // 17
    .config_schema_version = { 2, 0, 0, 0 },
    .midi_chan = MIDI_CHANNEL_OMNI,
    .magic = CONFIG_MAGIC_DUAL_ENV,
};

static struct Config current_config;

static uint8_t buf[NUM_BYTES_PER_PRESET];
static uint8_t migration_buf[SECTOR_SIZE];
static float *floats_buf;

int get_current_slot(void)
{
    return current_slot;
}

struct Config *get_config(void)
{
    return &current_config;
}

uint8_t *get_cc_map(void)
{
    return &runtime_cc_map[0];
}

static int write_config_to_flash(void)
{
    int ret = bflb_flash_erase(CONFIG_BASE, SECTOR_SIZE);
    if(ret < 0)
    {
        return ret;
    }
    return bflb_flash_write(CONFIG_BASE, (uint8_t *)&current_config, sizeof(struct Config));
}

static uint32_t get_schema_version(const struct Config *cfg)
{
    return (uint32_t)cfg->config_schema_version[0]
        | ((uint32_t)cfg->config_schema_version[1] << 8)
        | ((uint32_t)cfg->config_schema_version[2] << 16)
        | ((uint32_t)cfg->config_schema_version[3] << 24);
}

static void set_schema_version(struct Config *cfg, uint32_t version)
{
    cfg->config_schema_version[0] = (uint8_t)(version & 0xFFu);
    cfg->config_schema_version[1] = (uint8_t)((version >> 8) & 0xFFu);
    cfg->config_schema_version[2] = (uint8_t)((version >> 16) & 0xFFu);
    cfg->config_schema_version[3] = (uint8_t)((version >> 24) & 0xFFu);
}

static bool config_magic_is_supported(uint8_t magic)
{
    return magic == CONFIG_MAGIC_NORMAL || magic == CONFIG_MAGIC_DUAL_ENV;
}

static uint8_t schema1_num_cc_for_magic(uint8_t magic)
{
    return magic == CONFIG_MAGIC_DUAL_ENV ? SCHEMA1_DUAL_ENV_NUM_CC : SCHEMA1_NORMAL_NUM_CC;
}

static size_t schema1_num_floats(uint8_t num_cc)
{
    return (size_t)num_cc + SCHEMA1_PANEL_FLOATS + 1 + NUM_CC_MAP;
}

static void apply_preset_values(float *preset_values)
{
    struct CC *ccs = get_ccs();

    for(int i=0; i< NUM_CC; i++)
    {
        if(ccs[i].p == NULL)
        {
            continue;
        }
        *ccs[i].p = preset_values[i];
    }

    for(int i=0; i<NUM_CC_MAP; i++){
        runtime_cc_map[i] = (uint8_t)preset_values[SCHEMA2_CC_MAP_OFFSET + i];
    }
}

static int migrate_schema1_preset(int slot, uint8_t old_num_cc)
{
    uint32_t base = PRESET_BASE + (SECTOR_SIZE * slot);
    size_t old_num_floats = schema1_num_floats(old_num_cc);
    int ret = bflb_flash_read(base, migration_buf, old_num_floats * sizeof(float));
    if(ret < 0)
    {
        return ret;
    }

    memset(buf, 0, sizeof(buf));
    float *old_values = (float *)&migration_buf[0];
    float *new_values = (float *)&buf[0];

    for(int i=0; i<old_num_cc && i<SCHEMA2_PARAM_VALUES; i++)
    {
        new_values[i] = old_values[i];
    }

    size_t old_cc_map_offset = (size_t)old_num_cc + SCHEMA1_PANEL_FLOATS + 1;
    for(int i=0; i<NUM_CC_MAP; i++)
    {
        new_values[SCHEMA2_CC_MAP_OFFSET + i] = old_values[old_cc_map_offset + i];
    }

    ret = bflb_flash_erase(base, SECTOR_SIZE);
    if(ret < 0)
    {
        return ret;
    }
    return bflb_flash_write(base, buf, sizeof(buf));
}

static int migrate_schema1_presets(uint8_t old_num_cc)
{
    for(int slot=0; slot<NUM_PRESETS; slot++){
        if(current_config.empty[slot] == true)
        {
            continue;
        }

        int ret = migrate_schema1_preset(slot, old_num_cc);
        if(ret < 0)
        {
            return ret;
        }
    }

    return 0;
}

void flash_init(void)
{
    printf("initializing flash\n");
    struct Config conf;
    bflb_flash_read(CONFIG_BASE, (uint8_t *)&conf, sizeof(struct Config));
    uint32_t schema_version = get_schema_version(&conf);

    if(config_magic_is_supported(conf.magic) && (schema_version == 1 || schema_version == CONFIG_SCHEMA_VERSION))
    {
        printf("the magic number in flash was correct\n");
        current_config = conf;
        bool config_dirty = false;

        if(schema_version == 1) {
            uint8_t old_num_cc = schema1_num_cc_for_magic(current_config.magic);
            if(migrate_schema1_presets(old_num_cc) >= 0) {
                set_schema_version(&current_config, CONFIG_SCHEMA_VERSION);
                config_dirty = true;
            }
        } else if(schema_version != CONFIG_SCHEMA_VERSION) {
            set_schema_version(&current_config, CONFIG_SCHEMA_VERSION);
            config_dirty = true;
        }

        if(current_config.midi_chan < 1 || current_config.midi_chan > MIDI_CHANNEL_OMNI) {
            current_config.midi_chan = MIDI_CHANNEL_OMNI;
            config_dirty = true;
        }
        cur_midi_chan = current_config.midi_chan;
        if(config_dirty) {
            write_config_to_flash();
        }
    }
    else
    {
        printf("the magic number in flash was NOT correct\n");
        printf("initializing flash storage!\n");
        bflb_flash_erase(CONFIG_BASE, SECTOR_SIZE);
        bflb_flash_erase(PRESET_BASE, PRESET_REGION_BYTES);
        set_schema_version(&default_config, CONFIG_SCHEMA_VERSION);
        bflb_flash_write(CONFIG_BASE, (uint8_t *)&default_config, sizeof(struct Config));
        current_config = default_config;
        cur_midi_chan = current_config.midi_chan;
        is_initial_boot = true;
    }
    load_all_presets_from_flash();
}

void schedule_midi_chan_persist(void)
{
    uint8_t chan = (uint8_t)cur_midi_chan;
    if(current_config.midi_chan == chan && !midi_chan_persist_pending)
    {
        return;
    }
    current_config.midi_chan = chan;
    midi_chan_persist_pending = true;
    midi_chan_persist_due_us = bflb_mtimer_get_time_us() + MIDI_CHAN_PERSIST_DEBOUNCE_US;
}

void flash_persist_poll(void)
{
    if(!midi_chan_persist_pending)
    {
        return;
    }

    uint64_t now = bflb_mtimer_get_time_us();
    if(now < midi_chan_persist_due_us)
    {
        return;
    }

    if(write_config_to_flash() >= 0)
    {
        midi_chan_persist_pending = false;
    }
}

void save(int slot)
{
    // printf("saving slot %d\n", slot);
    current_slot = slot;
    int ret;
    uint32_t base = PRESET_BASE + (SECTOR_SIZE * slot);

    floats_buf = (float *)&buf[0];

    struct CC *ccs   = get_ccs();

    if(current_config.empty[slot] == false)
    {
        ret = bflb_flash_read(base, buf, sizeof(buf));
        if(ret < 0)
        {
            memset(buf, 0, sizeof(buf));
        }
    }
    else
    {
        memset(buf, 0, sizeof(buf));
    }

    for(int i=0; i< NUM_CC && i<SCHEMA2_PARAM_VALUES; i++)
    {
        if(ccs[i].p)
        {
            floats_buf[i] = *ccs[i].p;
        }
    }

    for(int i=0; i<NUM_CC_MAP; i++){
        floats_buf[SCHEMA2_CC_MAP_OFFSET + i] = runtime_cc_map[i];
    }

    // save to ram presets
    memcpy(&presets[slot], buf, NUM_BYTES_PER_PRESET);

    // printf("erase slot\n");
    ret = bflb_flash_erase(base, SECTOR_SIZE);
    if(ret < 0)
    {
        // printf("bflb_flash_erase returned %d\n", ret);
        return;
    }
    // printf("write buf\n");
    ret = bflb_flash_write(base, buf, sizeof(buf));
    if(ret < 0)
    {
        // printf("bflb_flash_write returned %d\n", ret);
        return;
    }

    current_config.empty[slot] = false;
    current_config.midi_chan = (uint8_t)cur_midi_chan;
    ret = write_config_to_flash();
    if(ret < 0)
    {
        // printf("bflb_flash_write returned %d\n", ret);
        return;
    }
    midi_chan_persist_pending = false;
}

void load(int slot)
{
    if(current_config.empty[slot] == true)
    {
        // printf("memory slot %d is empty\n", slot);
        return;
    }

    current_slot = slot;

    // printf("loading slot %d\n", slot);
    int ret;
    uint32_t base = PRESET_BASE + (SECTOR_SIZE * slot);

    ret = bflb_flash_read(base, buf, sizeof(buf));

    if(ret < 0)
    {
        // printf("bflb_flash_read returned %d\n", ret);
        return;
    }

    floats_buf = (float *) &buf[0];
    apply_preset_values(floats_buf);
}

void load_all_presets_from_flash(void){
    for(int slot=0; slot<NUM_PRESETS; slot++){
        if(current_config.empty[slot] == true)
        {
            printf("memory slot %d is empty\n", slot);
            continue;
        }
    
        uint32_t flash_addr = PRESET_BASE + (SECTOR_SIZE * slot);
        float *preset_start = &presets[slot][0];
        uint8_t *dest = (uint8_t *)preset_start;
        int ret = bflb_flash_read(flash_addr, dest, NUM_BYTES_PER_PRESET);
        if(ret < 0)
        {
            printf("bflb_flash_read returned %d\n", ret);
            continue;
        }
    }
}

void load_preset(int slot){
    if(current_config.empty[slot] == true)
    {
        printf("memory slot %d is empty\n", slot);
        return;
    }

    current_slot = slot;

    // printf("loading slot %d\n", slot);
    // int ret;
    // uint32_t base = PRESET_BASE + (SECTOR_SIZE * slot);

    floats_buf = &presets[slot][0];
    apply_preset_values(floats_buf);
}

void factory_reset(void){
    bflb_flash_erase(CONFIG_BASE, SECTOR_SIZE);
    GLB_SW_System_Reset();
}
