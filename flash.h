#ifndef FLASH_H
#define FLASH_H

#define NUM_PRESETS 14

struct Config {
    bool empty[NUM_PRESETS];
    uint8_t magic;
};

void flash_init(void);
void save(int slot);
void load(int slot);
int get_current_slot(void);

#endif