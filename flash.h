#ifndef FLASH_H
#define FLASH_H

#include <stdint.h>

#define NUM_PRESETS 17
#define NUM_CC_MAP (128 + 1 + 1) // 128 CCs, plus velocity and aftertouch
#define CONFIG_SCHEMA_VERSION_BYTES 4

struct Config {
    uint8_t empty[NUM_PRESETS];
    /* Deprecated: kept only to preserve on-flash layout and magic offset. */
    uint8_t cc_map_deprecated[NUM_CC_MAP - 1 - CONFIG_SCHEMA_VERSION_BYTES];
    uint8_t config_schema_version[CONFIG_SCHEMA_VERSION_BYTES];
    uint8_t midi_chan;
    uint8_t magic;
};

void flash_init(void);
void save(int slot);
void load(int slot);
int get_current_slot(void);
struct Config *get_config(void);
uint8_t *get_cc_map(void);
void schedule_midi_chan_persist(void);
void flash_persist_poll(void);
void factory_reset(void);

void load_preset(int slot);
void load_all_presets_from_flash(void);

#endif
