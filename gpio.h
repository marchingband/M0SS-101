#ifndef GPIO_H
#define GPIO_H

uint8_t *get_button_states(void);
uint8_t *get_button_pushes(void);
void clear_button_pushes(void);
void gpio_init(void);
void poll_gpio(void);

#endif