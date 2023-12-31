#include <stdlib.h>
#include <stdint.h>
#include <FreeRTOS.h>
#include "bflb_gpio.h"

#include "midi.h"
#include "gpio.h"

struct bflb_device_s *b_gpio;

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
    15,5,12,6,4,7,16,8,14,3,18,11,19,10,2,9,23,21,17,20,0,13,22,1
};

#define MUX_A0_PIN 27
#define MUX_A1_PIN 28
#define MUX_A2_PIN 29

#define MUX_0_DRAIN_PIN 30
#define MUX_1_DRAIN_PIN 0
#define MUX_2_DRAIN_PIN 1

#define ENCODER_BUTTON_PIN 20
#define BUTTON_25_PIN 12
#define BUTTON_26_PIN 13

#define DEBOUNCE_TIME 1000 * 50 // 50 ms

// button roles
#define BUTTON_NUM_SAVE 15
#define BUTTON_NUM_LOAD 18
#define BUTTON_NUM_ALT 23
#define BUTTON_NUM_LEARN 25

uint8_t button_pushes[NUM_BUTTONS]    = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
uint8_t button_cancelled[NUM_BUTTONS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
uint8_t button_state[NUM_BUTTONS]     = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
uint64_t button_time[NUM_BUTTONS]     = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static void mux_gpio_init(void){
    b_gpio = bflb_device_get_by_name("gpio");

    // drains need pullups
    bflb_gpio_init(b_gpio, MUX_0_DRAIN_PIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(b_gpio, MUX_1_DRAIN_PIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(b_gpio, MUX_2_DRAIN_PIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);

    bflb_gpio_init(b_gpio, MUX_A0_PIN, GPIO_OUTPUT | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(b_gpio, MUX_A1_PIN, GPIO_OUTPUT | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(b_gpio, MUX_A2_PIN, GPIO_OUTPUT | GPIO_SMT_EN | GPIO_DRV_0);
}

static void connected_buttons_init(){
    bflb_gpio_init(b_gpio, ENCODER_BUTTON_PIN, GPIO_INPUT | GPIO_FLOAT | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(b_gpio, BUTTON_25_PIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(b_gpio, BUTTON_26_PIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
}

const uint8_t mux_drain_pins[] = { MUX_0_DRAIN_PIN, MUX_1_DRAIN_PIN, MUX_2_DRAIN_PIN };

static void read_buttons(){
    // poll mux
    for(int i=0; i<8; i++) // 8 pins per mux
    {
        // set the mux bits
        for(int j=0; j<3; j++)
        {
            if(mux_code[i][j])
                bflb_gpio_set(b_gpio, MUX_A0_PIN + j);
            else
                bflb_gpio_reset(b_gpio, MUX_A0_PIN + j);
        }
        
        bflb_mtimer_delay_us(2); // let it settle

        // read the pins
        for(int k=0; k<3; k++)
            button_state[mux_pins[i + (k * 8)]] = bflb_gpio_read(b_gpio, mux_drain_pins[k]);
    }
    button_state[24] = bflb_gpio_read(b_gpio, BUTTON_25_PIN);
    button_state[25] = bflb_gpio_read(b_gpio, BUTTON_26_PIN);
    button_state[26] = bflb_gpio_read(b_gpio, ENCODER_BUTTON_PIN);
}

bool alt_held(void)
{
    return button_state[BUTTON_NUM_ALT] == 0;
}

static void process_buttons(){
    for (int i =0; i< NUM_BUTTONS; i++)
    {
        bool state = button_state[i];
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
                    if(alt_held())
                    {
                        if(i == BUTTON_NUM_ALT) // its the alt button
                        {
                            handle_button_press(i);
                        }
                        else if((i != BUTTON_NUM_LOAD) && (i != BUTTON_NUM_SAVE) && (i != BUTTON_NUM_LEARN)) // load / save / learn
                        {
                            button_cancelled[i] = 1;
                        }
                    }
                    printf("button %d pushed\n", i);
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
                    printf("button %d released\n", i);
                    if(button_cancelled[i])
                    {
                        button_cancelled[i] = 0;
                    }
                    else if(i == BUTTON_NUM_ALT) // its the alt button
                    {
                        continue;
                    }
                    else
                    {
                        handle_button_press(i); // trigger event on release
                    }
                }
            }
        }
    }
}

uint8_t *get_button_states(void)
{
    return button_state;
}

void cancel_button(int num)
{
    button_cancelled[num] = 1;
}

uint8_t *get_button_pushes(void)
{
    return button_pushes;
}

void clear_button_pushes(void)
{
    memset(button_pushes, 0, sizeof button_pushes); // clear it on every read
}

void poll_gpio(){
    read_buttons();
    process_buttons();
}

static void button_task(void* arg){
    while(1)
    {
        poll_gpio();
        vTaskDelay(10);
    }
}

void buttons_init(){
    mux_gpio_init();
    connected_buttons_init();
    // xTaskCreate(button_task, "button_task", 2048, NULL, 2, NULL);
}