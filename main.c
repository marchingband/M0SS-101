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

void dsp_run(int16_t *dest);
void dsp_init(size_t buf_size);
void uart_receive_init(void);
void poll_uart(void);
void usb_midi_init(void);
void usb_midi_start(void);

void test(void);
void print_bench(void);

/* ADC */
struct bflb_adc_channel_s chan[] = {
    {.pos_chan = ADC_CHANNEL_5,
     .neg_chan = ADC_CHANNEL_GND},
    {.pos_chan = ADC_CHANNEL_6,
     .neg_chan = ADC_CHANNEL_GND},
};

#define NUM_ADC_CHANNELS 2
struct bflb_device_s *adc;
int32_t adc_1 = 0;
int32_t adc_2 = 0;

static void adc_init(void)
{
    struct bflb_device_s *gpio;
    gpio = bflb_device_get_by_name("gpio");

    /* ADC_CH5 */
    bflb_gpio_init(gpio, GPIO_PIN_13, GPIO_ANALOG | GPIO_SMT_EN | GPIO_DRV_0);
    /* ADC_CH6 */
    bflb_gpio_init(gpio, GPIO_PIN_12, GPIO_ANALOG | GPIO_SMT_EN | GPIO_DRV_0);

    adc = bflb_device_get_by_name("adc");

    /* adc clock = XCLK / 2 / 32 */
    struct bflb_adc_config_s cfg;
    cfg.clk_div = ADC_CLK_DIV_32;
    cfg.scan_conv_mode = true;
    cfg.continuous_conv_mode = false;
    cfg.differential_mode = false;
    cfg.resolution = ADC_RESOLUTION_16B;
    cfg.vref = ADC_VREF_3P2V;

    bflb_adc_init(adc, &cfg);
    bflb_adc_channel_config(adc, chan, NUM_ADC_CHANNELS);
}

static void adc_read(void)
{
    bflb_adc_start_conversion(adc);

    while (bflb_adc_get_count(adc) < NUM_ADC_CHANNELS)
    {
        bflb_mtimer_delay_ms(1);
    }

    struct bflb_adc_result_s result;

    uint32_t raw_data = bflb_adc_read_raw(adc);
    bflb_adc_parse_result(adc, &raw_data, &result, 1);
    adc_1 = result.millivolt;

    raw_data = bflb_adc_read_raw(adc);
    bflb_adc_parse_result(adc, &raw_data, &result, 1);
    adc_2 = result.millivolt;
}

int main(void)
{
    /* board init */
    board_init();

    // encoder_init();
    // buttons_init();
    // dsp_init(BUF_SIZE);
    // rgb_led_init();
    // xTaskCreate(rgb_task, (char *)"rgb_task", 512, NULL, 2, NULL);

    // vTaskStartScheduler();

    /* load the config struct or initialize it */
    printf("flash_init\r\n");
    flash_init();

    /* setup button scanners */
    printf("gpio_init\r\n");
    buttons_init();

    /* start usb */
    printf("usbh_initialize\r\n");
    usbh_initialize();

    /* dsp init */
    printf("dsp_init\r\n");
    dsp_init(BUF_SIZE);

    /* audio dac init */
    printf("audio_dac_init\r\n");
    audio_dac_init();

    /* adc init */
    // adc_init();

    /* uart midi */
    printf("uart_receive_init\r\n");
    uart_receive_init();

    /* usb midi host */
    printf("usb_midi_init\r\n");
    usb_midi_init();

    /* start the LEDs */
    printf("rgb_led_init\r\n");
    rgb_led_init();

    /* setup encoder */
    printf("encoder_init\r\n");
    encoder_init();

    /* start rgb task */
    printf("start rgb_task\r\n");
    xTaskCreate(rgb_task, (char *)"rgb_task", 512, NULL, 2, NULL);
    // // printf("uart is irq %d with prio %d\n", uart_int_num, uart_prio);
    // // printf("audac is irq %d with prio %d\n", audac_int_num, audac_prio);
    // // int cnt = 0;
    // // bool bench = true;
        // bflb_mtimer_delay_ms(500);
        // printf("send blue\n");
    // rgb_set_color(pix_blue);
    // bflb_mtimer_delay_ms(500);
        // printf("send green\n");
    // rgb_set_color(pix_blue);
        // // rgb_set_color(pix_green);
        // bflb_mtimer_delay_ms(500);
        // printf("send red\n");
        // rgb_set_color(pix_blue);
        // rgb_set_color(pix_red);

    vTaskStartScheduler();
    /***************************/
    /*                         */
    // no code past here will run
    /*                         */
    /***************************/

    while (1)
    {
        bflb_mtimer_delay_ms(1000);
        printf("main loop");
        // uint64_t start = bflb_mtimer_get_time_us();x
        // if(bench && (cnt++ > 100000)){
        //     print_bench();
        //     bench = false;
        // }
        // poll_uart();
        // bflb_mtimer_delay_ms(1000);
        // printf("1000ms = %d us", (int)(bflb_mtimer_get_time_us() - start));
        // adc_read();
        // handle_pots();
        // printf("testing\n");
        // swgpio_send();
        // bflb_mtimer_delay_ms(500);
        // printf("send blue\n");
        // rgb_set_color(pix_blue);
        // bflb_mtimer_delay_ms(500);
        // printf("send green\n");
        // rgb_set_color(pix_green);
        // bflb_mtimer_delay_ms(500);
        // printf("send red\n");
        // rgb_set_color(pix_red);
        // bflb_mtimer_delay_ms(200);
    }
}

