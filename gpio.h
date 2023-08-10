#ifndef GPIO_H
#define GPIO_H

// #define NUM_BUTTONS 14 // save UART
#define NUM_BUTTONS 15 // use uart as button

uint8_t *get_button_states(void);
uint8_t *get_button_pushes(void);
void clear_button_pushes(void);
void gpio_init(void);
void poll_gpio(void);

#endif