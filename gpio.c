#include <stdlib.h>
#include <stdint.h>

#include "bflb_gpio.h"

struct bflb_device_s *gpio;

#define NUM_BUTTONS 14 // save UART
// #define NUM_BUTTONS 15 // use uart as button

#define DEBOUNCE_TIME 1000 * 50 // 50 ms

const uint8_t button_pins[]   = { 0, 1, 3, 10, 12, 13, 15, 16, 17, 20, 27, 28, 29, 30, 21 }; // 21 is UART

uint8_t button_pushes[]       = { 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0  };
uint8_t button_state[]        = { 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0  };
uint64_t button_time[]        = { 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0  };

void gpio_init(void)
{
    gpio = bflb_device_get_by_name("gpio");
    for (int i =0; i< NUM_BUTTONS; i++)
    {
        bflb_gpio_init(gpio, button_pins[i], GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    }
}

void poll_gpio(void)
{
    for (int i =0; i< NUM_BUTTONS; i++)
    {
        bool state = bflb_gpio_read(gpio, button_pins[i]);
        if(button_pushes[i] == 0) // not pushed
        {
            if(state == 0) // maybe pushed
            {
                uint64_t now = bflb_mtimer_get_time_us();
                if( (now - button_time[i]) > DEBOUNCE_TIME ) // released
                {
                    button_pushes[i] = 1;
                    button_state[i] = 0;
                    button_time[i] = now;
                    printf("button %d pushed", i);
                }
            }
        }
        else if(button_pushes[i] == 1) // is pushed
        {
            if(state == 1) // maybe released
            {
                uint64_t now = bflb_mtimer_get_time_us();
                if( (now - button_time[i]) > DEBOUNCE_TIME ) // released
                {
                    button_pushes[i] = 0;
                    button_state[i] = 1;
                    button_time[i] = now;
                    printf("button %d released", i);
                }
            }
        }
    }
}

uint8_t *get_button_states(void)
{
    return button_state;
}

uint8_t *get_button_pushes(void)
{
    return button_pushes;
}

void clear_button_pushes(void)
{
    memset(button_pushes, 0, sizeof button_pushes); // clear it on every read
}
