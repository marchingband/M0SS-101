#ifndef FLASH_H
#define FLASH_H

#define NUM_PRESETS 14
#define NUM_CC_MAP 128

struct Config {
    bool empty[NUM_PRESETS];
    uint8_t cc_map[NUM_CC_MAP];
    uint8_t magic;
};

void flash_init(void);
void save(int slot);
void load(int slot);
int get_current_slot(void);
struct Config *get_config(void);

#endif