#include <stdlib.h>
#include <stdint.h>
#include "bflb_gpio.h"

struct bflb_device_s *mux_gpio;

const uint8_t mux_code[8][3] = {
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},
    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};
const uint8_t mux_pins[24] = {
    // 2,1,0
    // {0,1,2},    // {16,6,13}
    // {3,4,5},    // {7,5,8}
    // {6,7,8},    // {17,9,15}
    // {9,10,11},  // {4,19,12}
    // {12,13,14}, // {20,11,3}
    // {15,16,17}, // {10,24,22}
    // {18,19,20}, // {18,21,1}
    // {21,22,23}  // {14,23,2}
    16,6,13,7,5,8,17,9,15,4,19,12,20,11,3,10,24,22,18,21,1,14,23,2
};

#define MUX_A0 27
#define MUX_A1 28
#define MUX_A2 29

#define MUX_1_DRAIN 30
#define MUX_2_DRAIN 0
#define MUX_3_DRAIN 1

void mux_gpio_init(void){
    mux_gpio = bflb_device_get_by_name("gpio");

    // drains need pullups
    bflb_gpio_init(mux_gpio, MUX_1_DRAIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(mux_gpio, MUX_2_DRAIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(mux_gpio, MUX_3_DRAIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);

    bflb_gpio_init(mux_gpio, MUX_A0, GPIO_OUTPUT | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(mux_gpio, MUX_A1, GPIO_OUTPUT | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(mux_gpio, MUX_A2, GPIO_OUTPUT | GPIO_SMT_EN | GPIO_DRV_0);
}

void debug_mux(void){
    for(int i=0; i<8; i++)
    {
        // set the mux
        for(int j=0; j<3; j++)
        {
            if(mux_code[i][j])
            {
                bflb_gpio_set(mux_gpio, MUX_A0 + j);
            }
            else
            {
                bflb_gpio_reset(mux_gpio, MUX_A0 + j);
            }
        }
        bflb_mtimer_delay_ms(1); // let it settle

        bool a0 = bflb_gpio_read(mux_gpio, MUX_1_DRAIN);
        bool a1 = bflb_gpio_read(mux_gpio, MUX_2_DRAIN);
        bool a2 = bflb_gpio_read(mux_gpio, MUX_3_DRAIN);

        if(!a0)
        {
            printf("%d\n", mux_pins[i]);
            // printf("%d\n", i);
        }
        if(!a1)
        {
            printf("%d\n", mux_pins[i + 8]);
            // printf("%d\n", i + 8);
        }
        if(!a2)
        {
            printf("%d\n", mux_pins[i + 16]);
            // printf("%d\n", i + 16);
        }
    }
}