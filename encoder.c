#include <FreeRTOS.h>
#include "queue.h"
#include "portmacro.h"

#include "stdbool.h"

#include "rotary_encoder.h"

#define ROT_ENC_A_GPIO 16
#define ROT_ENC_B_GPIO 17
#define ENABLE_HALF_STEPS false  // Set to true to enable tracking of rotary encoder at half step resolution
#define RESET_AT          0      // Set to a positive non-zero number to reset the position if this value is exceeded
#define FLIP_DIRECTION    false  // Set to true to reverse the clockwise/counterclockwise sense

static ATTR_NOCACHE_NOINIT_RAM_SECTION rotary_encoder_info_t info = { 0 };
QueueHandle_t event_queue;

static void encoder_task(void* arg)
{
    for(;;)
    {
        rotary_encoder_event_t event = { 0 };
        if (xQueueReceive(event_queue, &event, portMAX_DELAY))
        {
            // on_encoder(event.state.direction == ROTARY_ENCODER_DIRECTION_CLOCKWISE);
            printf("Event: position %d, direction %s", event.state.position,
                     event.state.direction ? (event.state.direction == ROTARY_ENCODER_DIRECTION_CLOCKWISE ? "CW" : "CCW") : "NOT_SET");
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
