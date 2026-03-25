#include <stdlib.h>
#include <stdint.h>
#include <FreeRTOS.h>

#include "bflb_gpio.h"
#include "bl616_glb.h"

#include "rgb_led.h"
#include "midi.h"
#include "gpio.h"
#include "flash.h"

extern int alt_switch_state;
extern int cur_midi_chan;
extern int cur_disp_num;
extern bool test_mode;

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
#define BUTTON_NUM_SAVE 14
#define BUTTON_NUM_LOAD 17
#define BUTTON_NUM_ALT 22
#define BUTTON_NUM_LEARN 24
#define BUTTON_NUM_ENCODER 26
#define BUTTON_NUM_MIDI_CHAN 6

const uint8_t mux_drain_pins[] = { MUX_0_DRAIN_PIN, MUX_1_DRAIN_PIN, MUX_2_DRAIN_PIN };

uint8_t button_pushes[NUM_BUTTONS]    = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t button_state[NUM_BUTTONS]     = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
uint64_t button_time[NUM_BUTTONS]     = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct Param param_selected = {
    .button = -1,
    .alt = false
};

bool set_midi_chan_active = false;
bool asb_active = false;
int cur_asb = 0;
bool alt_consumed = false;

uint64_t reset_mode_started = 0;
bool test_button_pressed = false;

struct Param get_param_selected(void){
    return param_selected;
}

void set_param_selected(int num, bool alt)
{
    if(alt)
    {
        struct Alt *Alts = get_alts();
        struct Alt alt = Alts[num];
        if(alt.p == 0)
        {
            return;
        }
        // printf("set led %f %f %f\n\r", val, alt.min, alt.max);
        set_led_display(alt.p, alt.min, alt.max);
    }
    else
    {
        struct Mod *Mods = get_mods();
        struct Mod mod = Mods[num];
        if(mod.p == 0){
            return;
        }
        // printf("set led %f %f %f\n\r", val, mod.min, mod.max);
        set_led_display(mod.p, mod.min, mod.max);
    }
    // if we get here it is a valid Alt or Mod
    param_selected.button = num;
    param_selected.alt = alt;
}

int button_label(int num){
    switch(num){
        case 0: return 1;
        case 1: return 2;
        case 2: return 3;
        case 3: return 4;
        case 6: return 5;
        case 7: return 6;
        case 8: return 7;
        case 9: return 8;
        case 10: return 9;
        case 11: return 10;
        case 12: return 11;
        case 13: return 12;
        case 15: return 13;
        case 18: return 14;
        case 20: return 15;
        case 24: return 16;
        case 23: return 17;
        default: return 0;
    }
    return 0;
}

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
    bflb_gpio_init(b_gpio, BUTTON_25_PIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(b_gpio, BUTTON_26_PIN, GPIO_INPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_0);
    bflb_gpio_init(b_gpio, ENCODER_BUTTON_PIN, GPIO_INPUT | GPIO_FLOAT | GPIO_SMT_EN | GPIO_DRV_0);
}

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
        
        bflb_mtimer_delay_us(5); // let it settle
        // bflb_mtimer_delay_us(2); // let it settle

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
    bool test_pressed = false;
    for (int i =0; i< NUM_BUTTONS; i++)
    {
        if(test_mode)
        {
            if(button_state[i] == 0)
            {
                test_pressed = true;
            }
            continue;
        }

        bool state = button_state[i];
        int ui_mode = get_ui_mode();
        uint64_t now = bflb_mtimer_get_time_us();

        // check params reset logic
        if(ui_mode == UI_MODE_RST){
            if(button_state[BUTTON_NUM_ALT] || button_state[9] || button_state[BUTTON_NUM_ENCODER]) // one was released
            {
                set_ui_mode(UI_MODE_PLAY);
            }
            if(now - reset_mode_started > ONE_SECOND)
            {
                if(button_state[0] == 0 && button_state[3] == 0){ // factory reset
                    set_ui_mode(UI_MODE_FACTORY_RST);
                } else if (button_state[3] == 0){
                    set_ui_mode(UI_MODE_CC_RST);
                } else {
                    set_ui_mode(UI_MODE_PANIC_RST);
                }
            }
            return;
        } else if(ui_mode == UI_MODE_FACTORY_RST || ui_mode == UI_MODE_PANIC_RST || ui_mode == UI_MODE_CC_RST){ // wait for a button release to do the factory reset
            if(button_state[BUTTON_NUM_ALT] || button_state[9] || button_state[BUTTON_NUM_ENCODER]) // one was released
            {
                bflb_mtimer_delay_ms(500); // short delay for user to release all the buttons
                if(ui_mode == UI_MODE_FACTORY_RST){
                    factory_reset();
                } else if (ui_mode == UI_MODE_PANIC_RST){
                    GLB_SW_System_Reset();
                } else {
                    reset_ccs();
                    set_ui_mode(UI_MODE_PLAY);
                }
            }
            return;
        }

        // check for presses
        if(button_pushes[i] == 0) // was not pushed
        {
            if(state == 0) // maybe pushed ( 0 is low so maybe pressed )
            {
                if( (now - button_time[i]) > DEBOUNCE_TIME ) // pressed
                {
                    button_pushes[i] = 1;
                    button_state[i] = 0;
                    button_time[i] = now;
                    if( i == BUTTON_NUM_ENCODER ){
                        // check for reset command
                        if(button_state[BUTTON_NUM_ALT] == 0 && button_state[9] == 0) // alt and lfo-env are held
                        {
                            set_ui_mode(UI_MODE_RST);
                            reset_mode_started = bflb_mtimer_get_time_us();
                        } else {
                            handle_encoder_press(true);
                        }
                    } else if( i == BUTTON_NUM_ALT ){
                        // handle_button_press(i);
                        alt_consumed = false;
                    } else if( alt_held() && get_asbs()[i].p != 0 ){
                        // its an asb
                        // printf("got asb on button %d\n", i);
                        cur_asb = i;
                        asb_active = true;
                        cur_disp_num = (int)*get_asbs()[i].p;
                        set_ui_mode(UI_MODE_DISP_NUM);
                    } else if( alt_held() && i == BUTTON_NUM_MIDI_CHAN ){
                        set_midi_chan_active = true;
                        cur_disp_num = cur_midi_chan;
                        set_ui_mode(UI_MODE_DISP_NUM);
                    } else if( ui_mode == UI_MODE_PLAY ){
                        set_param_selected(i, alt_held());
                    }
                    // printf("button %d pushed\n\r", i);
                }
            }
        }

        // check for releases
        else if(button_pushes[i] == 1) // was pushed
        {
            if(state == 1) // maybe released ( 1 is high so released)
            {
                uint64_t now = bflb_mtimer_get_time_us();
                if( (now - button_time[i]) > DEBOUNCE_TIME ) // released
                {
                    button_pushes[i] = 0;
                    button_state[i] = 1;
                    button_time[i] = now;
                    // printf("button %d released\n\r", i);
                    // chack for assignable events

                    if(asb_active && i == cur_asb)
                    {
                        asb_active = false;
                        set_ui_mode(UI_MODE_PLAY);
                    } 
                    else if(set_midi_chan_active && i == BUTTON_NUM_MIDI_CHAN)
                    {
                        set_midi_chan_active = false;
                        set_ui_mode(UI_MODE_PLAY);
                    } 
                    else if(i == BUTTON_NUM_ENCODER)
                    {
                        handle_encoder_press(false);
                    }
                    else if(i == BUTTON_NUM_ALT){
                        alt_switch_state = ALT_SWITCH_STATE_NONE;
                        if(!alt_consumed){
                            handle_button_press(i); // trigger alt event on release
                        }
                        asb_active = false;
                    }
                    else
                    {
                        alt_consumed = true;
                        handle_button_press(i); // trigger event on release
                    }
                }
            }
        }
    }
    test_button_pressed = test_pressed;
}

uint8_t *get_button_states(void)
{
    return button_state;
}

uint8_t *get_button_pushes(void)
{
    return button_pushes;
}

// void clear_button_pushes(void)
// {
//     memset(button_pushes, 0, sizeof button_pushes); // clear it on every read
// }

void poll_gpio(){
    read_buttons();
    process_buttons();
}

bool check_test_mode(void)
{
    read_buttons();
    return (button_state[23] == 0 && alt_held());
}

void buttons_init(){
    mux_gpio_init();
    connected_buttons_init();
}