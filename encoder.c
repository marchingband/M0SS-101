#include <FreeRTOS.h>
#include "queue.h"
#include "portmacro.h"
#include "bflb_dma.h"
#include "bl616_glb_gpio.h"
#include "bl616_irq.h"
#include "board.h"

#include "stdbool.h"

#include "rotary_encoder.h"
#include "gpio.h"
#include "midi.h"

#define ROT_ENC_A_GPIO 16
#define ROT_ENC_B_GPIO 17
#define ENABLE_HALF_STEPS false  // Set to true to enable tracking of rotary encoder at half step resolution
#define RESET_AT          0      // Set to a positive non-zero number to reset the position if this value is exceeded
#define FLIP_DIRECTION    false  // Set to true to reverse the clockwise/counterclockwise sense

static ATTR_NOCACHE_NOINIT_RAM_SECTION rotary_encoder_info_t info = { 0 };
QueueHandle_t event_queue;

int encoder_state = 0;

static void on_encoder(bool up){
    // encoder_state = up ? encoder_state + 1 : encoder_state - 1;
    // printf("encoder -> %d\n", encoder_state);

    uint8_t *button_states = get_button_states();
    for(int i=0; i<NUM_BUTTONS; i++)
    {
        if(button_states[i] == 0) // button is pressed means 0
        {
            if(alt_held())
            {
                struct Alt *Alts = get_alts();
                struct Alt alt = Alts[i];
                if(alt.p == 0)
                {
                    printf("got unknown Alt %d\n", i);
                }
                else
                {
                    float cur = *alt.p;
                    float step = alt.step * alt.mul;
                    float next = up ? cur + step : cur - step;
                    float clamped = next > alt.max ? alt.max : next < alt.min ? alt.min : next;
                    *alt.p = clamped;

                    // float steps = alt.mul * (float)cc_val;
                    // int whole_steps = round(steps);
                    // float val = (alt.step * whole_steps) + alt.min;
                    // *alt.p = val;
                }
            }
            else
            {
                struct Mod *Mods = get_mods();
                struct Mod mod = Mods[i];
                if(mod.p == 0)
                {
                    printf("got unknown Mod %d\n", i);
                }
                else
                {
                    float cur = *mod.p;
                    float step = mod.step * mod.mul;
                    float next = up ? cur + step : cur - step;
                    float clamped = next > mod.max ? mod.max : next < mod.min ? mod.min : next;
                    *mod.p = clamped;

                    // float steps = mod.mul * (float)cc_val;
                    // int whole_steps = round(steps);
                    // float val = (mod.step * whole_steps) + mod.min;
                    // *mod.p = val;
                }
            }
        }
    }
}

static void encoder_task(void* arg)
{
    for(;;)
    {
        rotary_encoder_event_t event = { 0 };
        if (xQueueReceive(event_queue, &event, portMAX_DELAY))
        {
            on_encoder(event.state.direction == ROTARY_ENCODER_DIRECTION_CLOCKWISE);
            // printf("Event: position %d, direction %s\n", event.state.position,
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
