#include "bflb_flash.h"
#include "board.h"
#include "midi.h"
#include "gpio.h"
#include "flash.h"

#define CONFIG_BASE 0x30000
#define PRESET_BASE 0x20000

#define NUM_FLOATS (NUM_CC + NUM_BUTTONS + NUM_BUTTONS + NUM_SEL)
#define NUM_BYTES_PER_PRESET (NUM_FLOATS * sizeof(float))
#define TOTAL_BYTES (NUM_BYTES_PER_PRESET * NUM_PRESETS)

void test_flash(void)
{
    int ret;
    uint32_t base = 0x10000;
    uint8_t read_buf[512 * 4];
    uint8_t write_buf[512];
    for(int i=0; i< 512; i++){write_buf[i] = 0;}

    ret = bflb_flash_erase(base, 512 * 2);
    if(ret < 0){printf("1 %d", ret);}

    ret = bflb_flash_write(base, write_buf, 512);
    if(ret < 0){printf("2 %d", ret);}

    ret = bflb_flash_write(base + 512, write_buf, 512);
    if(ret < 0){printf("3 %d", ret);}

    ret = bflb_flash_write(base + 512 * 2, write_buf, 512);
    if(ret < 0){printf("4 %d", ret);}

    ret = bflb_flash_write(base + 512 * 3, write_buf, 512);
    if(ret < 0){printf("5 %d", ret);}

    ret = bflb_flash_read(base, read_buf, 512 * 4);
    if(ret < 0){printf("55 %d", ret);}

    printf("0:%d\n", read_buf[0]);
    printf("512:%d\n", read_buf[512]);
    printf("512:%d\n", read_buf[512 * 2]);
    printf("768:%d\n", read_buf[512 * 3]);

    ret = bflb_flash_erase(base, 1);
    if(ret < 0){printf("6 %d", ret);}

    ret = bflb_flash_read(base, read_buf, 512 * 4);
    if(ret < 0){printf("7 %d", ret);}

    printf("0:%d\n", read_buf[0]);
    printf("512:%d\n", read_buf[512]);
    printf("1024:%d\n", read_buf[512 * 2]);
    printf("1536:%d\n", read_buf[512 * 3]);

    ret = bflb_flash_erase(base, 2);
    if(ret < 0){printf("8 %d", ret);}

    ret = bflb_flash_read(base, read_buf, 512 * 4);
    if(ret < 0){printf("9 %d", ret);}

    printf("0:%d\n", read_buf[0]);
    printf("512:%d\n", read_buf[512]);
    printf("1024:%d\n", read_buf[512 * 2]);
    printf("1536:%d\n", read_buf[512 * 3]);

    ret = bflb_flash_erase(base, 512);
    if(ret < 0){printf("10 %d", ret);}

    ret = bflb_flash_read(base, read_buf, 512 * 4);
    if(ret < 0){printf("11 %d", ret);}

    printf("0:%d\n", read_buf[0]);
    printf("512:%d\n", read_buf[512]);
    printf("1024:%d\n", read_buf[512 * 2]);
    printf("1536:%d\n", read_buf[512 * 3]);

    ret = bflb_flash_erase(base, 512 * 2);
    if(ret < 0){printf("12 %d", ret);}

    ret = bflb_flash_read(base, read_buf, 512 * 4);
    if(ret < 0){printf("13 %d", ret);}

    printf("0:%d\n", read_buf[0]);
    printf("512:%d\n", read_buf[512]);
    printf("1024:%d\n", read_buf[512 * 2]);
    printf("1536:%d\n", read_buf[512 * 3]);


}

static int current_slot = -1;

static struct Config default_config = {
    .empty = { true, true, true, true, true, true, true, true, true, true, true, true, true, true },
    .cc_map = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 },
    .magic = 124,
};

static struct Config current_config;

static uint8_t buf[NUM_BYTES_PER_PRESET];
static float *floats_buf;

int get_current_slot(void)
{
    return current_slot;
}

struct Config *get_config(void)
{
    return &current_config;
}

void flash_init(void)
{
    printf("initializing flash\n");
    struct Config conf;
    bflb_flash_read(CONFIG_BASE, &conf, sizeof(struct Config));
    if(conf.magic == default_config.magic)
    {
        printf("the magic number in flash was correct\n");
        current_config = conf;
        for(int i=0; i< 127; i++)
        {
            printf("%d : %d\n", i, current_config.cc_map[i]);
        }
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

void save(int slot)
{
    printf("saving slot %d\n", slot);
    current_slot = slot;
    int ret;
    uint32_t base = PRESET_BASE + (NUM_BYTES_PER_PRESET * slot);

    floats_buf = (float *)&buf[0];

    struct CC *ccs   = get_ccs();
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
    // ret = bflb_flash_erase(base, sizeof(buf));
    ret = bflb_flash_write(base, buf, sizeof(buf));
    if(ret < 0)
    {
        printf("bflb_flash_write returned %d\n", ret);
        return;
    }

    printf("write config\n");
    current_config.empty[slot] = false;
    ret = bflb_flash_write(CONFIG_BASE, &current_config, sizeof(struct Config));
    if(ret < 0)
    {
        printf("bflb_flash_write returned %d\n", ret);
        return;
    }
}

void load(int slot)
{
    if(current_config.empty[slot] == true)
    {
        printf("memory slot %d is empty\n", slot);
        return;
    }

    current_slot = slot;

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
        return;
    }

    floats_buf = (float *) &buf[0];

    int idx = 0;

    for(int i=0; i< NUM_CC; i++)
    {
        if(ccs[i].p == NULL)
        {
            printf("cc %d is null\n", i);
            idx++;
            continue;
        }
        float val = floats_buf[idx++];
        printf("reading %f to cc %d\n", val, i);
        *ccs[i].p = val;
    }

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        if(mods[i].p == 0)
        {
            printf("mod %d is null\n", i);
            idx++;
            continue;
        }
        float val = floats_buf[idx++];
        printf("reading %f to mod %d\n", val, i);
        *mods[i].p = val;
    }

    for(int i=0; i< NUM_BUTTONS; i++)
    {
        if(alts[i].p == 0)
        {
            printf("alt %d is null\n", i);
            idx++;
            continue;
        }
        float val = floats_buf[idx++];
        printf("reading %f to alts %d\n", val, i);
        *alts[i].p = val;
    }

    for(int i=0; i< NUM_SEL; i++)
    {
        if(sels[i].p == 0)
        {
            printf("sel %d is null\n", i);
            idx++;
            continue;
        }
        float val = floats_buf[idx++];
        printf("reading %f to sels %d\n", val, i);
        *sels[i].p = val;
    }
}