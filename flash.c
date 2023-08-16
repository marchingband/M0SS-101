#include "bflb_flash.h"
#include "board.h"
#include "midi.h"
#include "gpio.h"

#define NUM_PRESETS 14
#define CONFIG_BASE 0x20000
#define PRESET_BASE 0x20100

#define NUM_FLOATS (NUM_CC + NUM_BUTTONS + NUM_BUTTONS + NUM_SEL)
#define NUM_BYTES_PER_PRESET (NUM_FLOATS * sizeof(float))
#define TOTAL_BYTES (NUM_BYTES_PER_PRESET * NUM_PRESETS)

struct Config {
    bool empty[NUM_PRESETS];
    uint8_t magic;
};

struct Config default_config = {
    .empty = {false, false, false, false, false, false, false, false, false, false, false, false, false, false},
    .magic = 123,
};

struct Config current_config;

void flash_init(void)
{
    printf("initializing flash\n");
    struct Config conf;
    bflb_flash_read(CONFIG_BASE, &conf, sizeof(struct Config));
    if(conf.magic == default_config.magic)
    {
        printf("the magic number in flash was correct\n");
        current_config = conf;
        return 0;
    }
    else
    {
        printf("the magic number in flash was NOT correct\n");
        printf("initializing flash storage!\n");
        bflb_flash_erase(CONFIG_BASE, sizeof(struct Config));
        bflb_flash_erase(PRESET_BASE, TOTAL_BYTES);
        bflb_flash_write(CONFIG_BASE, &default_config, sizeof(struct Config));
        current_config = default_config;
    }
}

static uint8_t buf[NUM_BYTES_PER_PRESET];
float *floats_buf;

void save(int slot)
{
    printf("save %d\n", slot);
    int ret;
    uint32_t base = PRESET_BASE + (NUM_BYTES_PER_PRESET * slot);

    floats_buf = (float *)&buf[0];

    struct CC *ccs = get_ccs();
    struct Mod *mods = get_mods();
    struct Alt *alts = get_alts();
    struct Sel *sels = get_sels();

    int idx = 0;

    for(int i=0; i< NUM_CC; i++)
    {
        float val = ccs[i].p ? *ccs[i].p : 0.0;
        printf("writing %f to cc %d\n", val, i);
        floats_buf[idx++] = val;
    }

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        float val = mods[i].p ? *mods[i].p : 0.0;
        printf("writing %f to mods %d\n", val, i);
        floats_buf[idx++] = val;
    }

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        float val = alts[i].p ? *alts[i].p : 0.0;
        printf("writing %f to alts %d\n", val, i);
        floats_buf[idx++] = val;
    }

    for(int i=0; i< NUM_SEL; i++)
    {
        float val = sels[i].p ? *sels[i].p : 0.0;
        printf("writing %f to sels %d\n", val, i);
        floats_buf[idx++] = val;
    }

    printf("write buf\n");
    ret = bflb_flash_write(base, buf, sizeof(buf));
    if(ret < 0)
    {
        printf("bflb_flash_write returned %d\n", ret);
    }

    printf("write config\n");
    current_config.empty[slot] = false;
    ret = bflb_flash_write(CONFIG_BASE, &current_config, sizeof(struct Config));
    if(ret < 0)
    {
        printf("bflb_flash_write returned %d\n", ret);
    }
}

void load(int slot)
{
    if(current_config.empty[slot] == true)
    {
        printf("memory slot %d is empty\n", slot);
        return;
    }

    printf("loading slot %d\n", slot);
    int ret;
    uint32_t base = PRESET_BASE + (NUM_BYTES_PER_PRESET * slot);

    struct CC *ccs = get_ccs();
    struct Mod *mods = get_mods();
    struct Alt *alts = get_alts();
    struct Sel *sels = get_sels();

    ret = bflb_flash_read(base, buf, sizeof(buf));
    if(ret < 0)
    {
        printf("bflb_flash_read returned %d\n", ret);
    }
    floats_buf = (float *) &buf[0];

    int idx = 0;

    for(int i=0; i< NUM_CC; i++)
    {
        printf("load cc %d\n", i);
        if(ccs[i].p == NULL)
        {
            printf("cc %d is null\n", i);
            idx++;
            continue;
        }
        float val = floats_buf[idx++];
        printf("writing %f to cc %d\n", val, i);
        *ccs[i].p = val;
    }

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        printf("load mod %d\n", i);
        if(mods[i].p == 0)
        {
            printf("mod %d is null\n", i);
            idx++;
            continue;
        }
        float val = floats_buf[idx++];
        printf("writing %f to mod %d\n", val, i);
        *mods[i].p = val;
    }

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        printf("load alt %d\n", i);
        if(alts[i].p == 0)
        {
            printf("alt %d is null\n", i);
            idx++;
            continue;
        }
        float val = floats_buf[idx++];
        printf("writing %f to alts %d\n", val, i);
        *alts[i].p = val;
    }

    for(int i=0; i< NUM_SEL; i++)
    {
        printf("load sel %d\n", i);
        if(sels[i].p == 0)
        {
            printf("sel %d is null\n", i);
            idx++;
            continue;
        }
        float val = floats_buf[idx++];
        printf("writing %f to sels %d\n", val, i);
        *sels[i].p = val;
    }
}