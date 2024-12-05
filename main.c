#include "bflb_uart.h"
#include <math.h>
#include <stdlib.h>

#include "bflb_mtimer.h"
#include "bflb_adc.h"
#include "bflb_audac.h"
#include "bflb_gpio.h"
#include "bflb_dma.h"
#include "bflb_uart.h"

#include "bl616_glb.h"
#include "bflb_i2s.h"
#include "bl616_glb_gpio.h"
#include "bl616_irq.h"
#include "board.h"

#include "bflb_core.h"

#include "usbh_core.h"
#include <FreeRTOS.h>

#include "rgb_led.h"
#include "gpio.h"
#include "flash.h"
#include "encoder.h"
#include "audac.h"
#include "spi_rgb.h"
#include "midi.h"
#include "dsp.h"

int main(void)
{
    /* board init */
    board_init();

    /* load the config struct or initialize it */
    // printf("flash_init\r\n");
    flash_init();

    /* setup button scanners */
    // printf("gpio_init\r\n");
    buttons_init();

    /* start usb */
    // printf("usbh_initialize\r\n");
    usbh_initialize();

    /* dsp init */
    // printf("dsp_init\r\n");
    dsp_init(BUF_SIZE);

    /* audio dac init */
    // printf("audio_dac_init\r\n");
    audio_dac_init();

    /* uart midi */
    // printf("uart_receive_init\r\n");
    uart_receive_init();

    /* start the LEDs */
    // printf("rgb_led_init\r\n");
    spi_rgb_init();

    /* setup encoder */
    // printf("encoder_init\r\n");
    encoder_init();

    vTaskStartScheduler();

    /***************************/
    /*                         */
    // no code past here will run
    /*                         */
    /***************************/

    while (1){
        bflb_mtimer_delay_ms(1000);
    }
}

