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
        bflb_mtimer_delay_ms(5); // let it settle

        bool a0 = bflb_gpio_read(mux_gpio, MUX_1_DRAIN);
        bool a1 = bflb_gpio_read(mux_gpio, MUX_2_DRAIN);
        bool a2 = bflb_gpio_read(mux_gpio, MUX_3_DRAIN);

        if(a0 == false || a1 == false || a2 == false)
        {
            printf("%d -> %d | %d | %d\n", i, a0, a1, a2);
        }
        else
        {
            printf(".");
        }
    }
}