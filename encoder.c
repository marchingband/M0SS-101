#include "stdbool.h"

#include <FreeRTOS.h>
#include "queue.h"
#include "portmacro.h"
#include "bflb_dma.h"
#include "bl616_glb_gpio.h"
#include "bl616_irq.h"
#include "bflb_mtimer.h"
#include "board.h"

#include "rotary_encoder.h"
#include "gpio.h"
#include "midi.h"
#include "rgb_led.h"

#define ROT_ENC_A_GPIO 16
#define ROT_ENC_B_GPIO 17
// #define ENABLE_HALF_STEPS true  // Set to true to enable tracking of rotary encoder at half step resolution
#define ENABLE_HALF_STEPS false  // Set to true to enable tracking of rotary encoder at half step resolution
#define RESET_AT          0      // Set to a positive non-zero number to reset the position if this value is exceeded
#define FLIP_DIRECTION    false  // Set to true to reverse the clockwise/counterclockwise sense

static ATTR_NOCACHE_NOINIT_RAM_SECTION rotary_encoder_info_t info = { 0 };
QueueHandle_t event_queue;

uint64_t last_click = 0;

#define CLICK_SLOW 100000
#define CLICK_MED  60000
#define CLICK_FAST 15000

extern bool encoder_pressed;

static void on_encoder(bool up){
    uint64_t now = bflb_mtimer_get_time_us();
    uint64_t passed = now - last_click;
    last_click = now;
    int click_multiplier = passed > 100000 ? 1 : passed > 50000 ? 4 : passed > 10000 ? 10 : 30;
    // printf("time %llu\n\r", passed);
    // printf("mul %d\n\r", click_multiplier);
    // uint8_t *button_states = get_button_states();
    struct Param param = get_param_selected();
    if(alt_held()){
        struct Sigs *sigs = get_signals();
        if(encoder_pressed){
            // 0 to 16,383
            float modifier = up ? click_multiplier * 10 : click_multiplier * -10;
            float next = *sigs->pitch_bend + modifier ;
            *sigs->pitch_bend = next > 16383 ? 16383 : next < 0 ? 0 : next;
        } else {
            *sigs->pitch = up ? *sigs->pitch + 1 : *sigs->pitch - 1;
        }
        return;
    }
    if(param.button == -1)
    {
        // printf("nothing selected\n\r");
        return;
    }

    if(param.alt)
    {
        struct Alt *Alts = get_alts();
        struct Alt alt = Alts[param.button];
        if(alt.p == 0)
        {
            // printf("got unknown Alt %d\n\r", param.button);
        }
        else
        {
            float cur = *alt.p;
            float step = alt.step * alt.mul * click_multiplier;
            float next = up ? cur + step : cur - step;
            float clamped = next > alt.max ? alt.max : next < alt.min ? alt.min : next;
            *alt.p = clamped;
            // printf("set led %f %f %f\n\r", clamped, alt.min, alt.max);
            set_led_display(clamped, alt.min, alt.max);
        }

    }
    else
    {
        struct Mod *Mods = get_mods();
        struct Mod mod = Mods[param.button];
        if(mod.p == 0)
        {
            // printf("got unknown Mod %d\n\r", param.button);
        }
        else
        {
            float cur = *mod.p;
            float step = mod.step * mod.mul * click_multiplier;
            float next = up ? cur + step : cur - step;
            float clamped = next > mod.max ? mod.max : next < mod.min ? mod.min : next;
            *mod.p = clamped;
            // printf("set led %f %f %f\n\r", clamped, mod.min, mod.max);
            set_led_display(clamped, mod.min, mod.max);
        }
    }
}
// static void on_encoder(bool up){
//     uint64_t now = bflb_mtimer_get_time_us();
//     uint64_t passed = now - last_click;
//     last_click = now;
//     int click_multiplier = passed > 100000 ? 1 : passed > 50000 ? 4 : 10;
//     // printf("%llu\n\r", passed);
//     printf("%d\n\r", click_multiplier);
//     uint8_t *button_states = get_button_states();
//     for(int i=0; i<NUM_BUTTONS; i++)
//     {
//         if(button_states[i] == 0) // button is pressed means 0
//         {
//             if(alt_held())
//             {
//                 struct Alt *Alts = get_alts();
//                 struct Alt alt = Alts[i];
//                 if(alt.p == 0)
//                 {
//                     printf("got unknown Alt %d\n\r", i);
//                 }
//                 else
//                 {
//                     float cur = *alt.p;
//                     float step = alt.step * alt.mul * click_multiplier;
//                     float next = up ? cur + step : cur - step;
//                     float clamped = next > alt.max ? alt.max : next < alt.min ? alt.min : next;
//                     *alt.p = clamped;
//                     set_led_display(clamped, alt.min, alt.max);
//                 }
//             }
//             else
//             {
//                 struct Mod *Mods = get_mods();
//                 struct Mod mod = Mods[i];
//                 if(mod.p == 0)
//                 {
//                     printf("got unknown Mod %d\n\r", i);
//                 }
//                 else
//                 {
//                     float cur = *mod.p;
//                     float step = mod.step * mod.mul * click_multiplier;
//                     float next = up ? cur + step : cur - step;
//                     float clamped = next > mod.max ? mod.max : next < mod.min ? mod.min : next;
//                     *mod.p = clamped;
//                     set_led_display(clamped, mod.min, mod.max);
//                 }
//             }
//         }
//     }
// }

static void encoder_task(void* arg)
{
    for(;;)
    {
        rotary_encoder_event_t event = { 0 };
        if (xQueueReceive(event_queue, &event, portMAX_DELAY))
        {
            on_encoder(event.state.direction == ROTARY_ENCODER_DIRECTION_CLOCKWISE);
            // printf("Event: position %d, direction %s\n\r", event.state.position,
            //          event.state.direction ? (event.state.direction == ROTARY_ENCODER_DIRECTION_CLOCKWISE ? "CW" : "CCW") : "NOT_SET");
        }    
    }
}

void encoder_init(void)
{
    rotary_encoder_init(&info, ROT_ENC_A_GPIO, ROT_ENC_B_GPIO);
    rotary_encoder_enable_half_steps(&info, ENABLE_HALF_STEPS);
#ifdef FLIP_DIRECTION
    rotary_encoder_flip_direction(&info);
#endif
    event_queue = rotary_encoder_create_queue();
    rotary_encoder_set_queue(&info, event_queue);
    xTaskCreate(encoder_task, "encoder_task", 2048, NULL, 2, NULL);
}
