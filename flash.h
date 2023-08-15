#ifndef FLASH_H
#define FLASH_H

void flash_init(void);
void save(int slot);
void load(int slot);

#endif