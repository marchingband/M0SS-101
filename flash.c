#include "bflb_flash.h"
#include "board.h"
#include "midi.h"
#include "gpio.h"

#define NUM_PRESETS 14
#define CONFIG_BASE 0x20100
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
    printf("initializing flash");
    struct Config conf;
    bflb_flash_read(CONFIG_BASE, &conf, sizeof(struct Config));
    if(conf.magic == default_config.magic)
    {
        printf("the magic number in flash was correct");
        current_config = conf;
        return 0;
    }
    else
    {
        printf("the magic number in flash was NOT correct");
        printf("initializing flash storage!");
        bflb_flash_erase(CONFIG_BASE, sizeof(struct Config));
        bflb_flash_erase(PRESET_BASE, TOTAL_BYTES);
        bflb_flash_write(CONFIG_BASE, &default_config, sizeof(struct Config));
        current_config = default_config;
    }
}

void save(int slot)
{
    printf("save %d", slot);
    uint32_t base = PRESET_BASE + (NUM_BYTES_PER_PRESET * slot);

    struct CC *ccs = get_ccs();
    struct Mod *mods = get_mods();
    struct Alt *alts = get_alts();
    struct Sel *sels = get_sels();

    for(int i=0; i< NUM_CC; i++)
    {
        printf("write cc %d", i);
        uint32_t addr = base + ( i * sizeof(float));
        float val = *ccs[i].p;
        bflb_flash_write(addr, &val, sizeof(float));
    }
    base += ( NUM_CC * sizeof(float) );

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        printf("write mod %d", i);
        uint32_t addr = base + ( i * sizeof(float));
        float val = *mods[i].p;
        bflb_flash_write(addr, &val, sizeof(float));
    }
    base += ( NUM_BUTTONS * sizeof(float) );

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        printf("write alt %d", i);
        uint32_t addr = base + ( i * sizeof(float));
        float val = *alts[i].p;
        bflb_flash_write(addr, &val, sizeof(float));
    }
    base += ( NUM_BUTTONS * sizeof(float) );

    for(int i=0; i< NUM_SEL; i++)
    {
        printf("write sel %d", i);
        uint32_t addr = base + ( i * sizeof(float));
        float val = *sels[i].p;
        bflb_flash_write(addr, &val, sizeof(float));
    }

    printf("write config");
    current_config.empty[slot] = false;
    bflb_flash_write(CONFIG_BASE, &current_config, sizeof(struct Config));
}

void load(int slot)
{
    if(current_config.empty[slot] = true)
    {
        printf("memory slot %d is empty", slot);
        return;
    }

    uint32_t base = PRESET_BASE + (NUM_BYTES_PER_PRESET * slot);

    struct CC *ccs = get_ccs();
    struct Mod *mods = get_mods();
    struct Alt *alts = get_alts();
    struct Sel *sels = get_sels();

    for(int i=0; i< NUM_CC; i++)
    {
        uint32_t addr = base + ( i * sizeof(float));
        float *val = ccs[i].p;
        bflb_flash_read(addr, val, sizeof(float));
    }
    base += ( NUM_CC * sizeof(float) );

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        uint32_t addr = base + ( i * sizeof(float));
        float *val = mods[i].p;
        bflb_flash_read(addr, val, sizeof(float));
    }
    base += ( NUM_BUTTONS * sizeof(float) );

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        uint32_t addr = base + ( i * sizeof(float));
        float *val = alts[i].p;
        bflb_flash_read(addr, val, sizeof(float));
    }
    base += ( NUM_BUTTONS * sizeof(float) );

    for(int i=0; i< NUM_SEL; i++)
    {
        uint32_t addr = base + ( i * sizeof(float));
        float *val = sels[i].p;
        bflb_flash_read(addr, val, sizeof(float));
    }
}