#include "bflb_i2s.h"
#include "bflb_gpio.h"
#include "bflb_dma.h"
#include "bl616_glb_gpio.h"
#include "bl616_irq.h"
#include "board.h"
#include "rgb_led.h"
#include "midi.h"

// #define PIXEL_SIZE 12 // each colour takes 4 bytes
#define PIXEL_SIZE 6 // each colour takes 4 bytes
#define NUM_LED 26

bool rgb_rendering = false;

void rgb_task(void *pvParameters)
{
    while (1) {
        if(!rgb_rendering)
        {
            rgb_rendering = true;
            render_lights();
        }
        vTaskDelay(1000);
    }
    vTaskDelete(NULL);
}

static void i2s_gpio_init()
{
    struct bflb_device_s *gpio;
    gpio = bflb_device_get_by_name("gpio");
    bflb_gpio_init(gpio, GPIO_PIN_16, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    // bflb_gpio_init(gpio, GPIO_PIN_17, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, GPIO_PIN_10, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, GPIO_PIN_11, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
}

static ATTR_NOCACHE_NOINIT_RAM_SECTION uint16_t tx_buffer[256] __ALIGNED(4);
static volatile uint8_t dma_tc_flag0 = 0;
static struct bflb_device_s *dma0_ch1;
static struct bflb_dma_channel_lli_pool_s tx_llipool[1];
static struct bflb_dma_channel_lli_transfer_s tx_transfers[1];

void dma0_ch1_isr(void *arg)
{
    dma_tc_flag0++;
    bflb_dma_channel_stop(dma0_ch1);
    rgb_rendering = false;
}

void rgb_led_init(){
    struct bflb_device_s *i2s0;
    i2s_gpio_init();

    struct bflb_i2s_config_s i2s_cfg = {
        // .bclk_freq_hz = 130000 * 16 * 2, /* bclk = Sampling_rate * frame_width * channel_num */
        .bclk_freq_hz = 93750 * 16 * 2, /* bclk = Sampling_rate * frame_width * channel_num */
        .role = I2S_ROLE_MASTER,
        .format_mode = I2S_MODE_LEFT_JUSTIFIED,
        .channel_mode = I2S_CHANNEL_MODE_NUM_2,
        .frame_width = I2S_SLOT_WIDTH_16,
        .data_width = I2S_SLOT_WIDTH_16,
        .fs_offset_cycle = 0,
        .tx_fifo_threshold = 0,
        .rx_fifo_threshold = 0,
    };

    struct bflb_dma_channel_config_s tx_config = {
        .direction = DMA_MEMORY_TO_PERIPH,
        .src_req = DMA_REQUEST_NONE,
        .dst_req = DMA_REQUEST_I2S_TX,
        .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE,
        .dst_addr_inc = DMA_ADDR_INCREMENT_DISABLE,
        .src_burst_count = DMA_BURST_INCR1,
        .dst_burst_count = DMA_BURST_INCR1,
        .src_width = DMA_DATA_WIDTH_16BIT,
        .dst_width = DMA_DATA_WIDTH_16BIT,
    };

    struct bflb_dma_channel_config_s rx_config = {
        .direction = DMA_PERIPH_TO_MEMORY,
        .src_req = DMA_REQUEST_I2S_RX,
        .dst_req = DMA_REQUEST_NONE,
        .src_addr_inc = DMA_ADDR_INCREMENT_DISABLE,
        .dst_addr_inc = DMA_ADDR_INCREMENT_ENABLE,
        .src_burst_count = DMA_BURST_INCR1,
        .dst_burst_count = DMA_BURST_INCR1,
        .src_width = DMA_DATA_WIDTH_16BIT,
        .dst_width = DMA_DATA_WIDTH_16BIT,
    };

    i2s0 = bflb_device_get_by_name("i2s0");
    bflb_i2s_init(i2s0, &i2s_cfg);
    bflb_i2s_link_txdma(i2s0, true);

    printf("\n\ri2s dma test\n\r");
    dma0_ch1 = bflb_device_get_by_name("dma0_ch1");
    bflb_dma_channel_init(dma0_ch1, &tx_config);
    bflb_dma_channel_irq_attach(dma0_ch1, dma0_ch1_isr, NULL);

    bflb_i2s_feature_control(i2s0, I2S_CMD_DATA_ENABLE, I2S_CMD_DATA_ENABLE_TX | I2S_CMD_DATA_ENABLE_RX);
    printf("rgb setup done\n");
}

void i2s_send(void)
{
    tx_transfers[0].src_addr = (uint32_t)tx_buffer;
    tx_transfers[0].dst_addr = (uint32_t)DMA_ADDR_I2S_TDR;
    tx_transfers[0].nbytes = sizeof(tx_buffer);

    bflb_dma_channel_lli_reload(dma0_ch1, tx_llipool, 1, tx_transfers, 1);
    bflb_dma_channel_start(dma0_ch1);
}

static const uint16_t bitpatterns[4] = {0x88, 0x8e, 0xe8, 0xee};
static uint8_t out_buffer[NUM_LED * PIXEL_SIZE] = {0};

void rgb_set_color(struct pixel_t *pixels){
    memset(tx_buffer, 0, sizeof tx_buffer);
    for (uint16_t i = 0; i < NUM_LED; i++) {
        int loc = i * PIXEL_SIZE;

        tx_buffer[loc]     = (bitpatterns[pixels[i].green >> 6 & 0x03] << 8) | bitpatterns[pixels[i].green >> 4 & 0x03];
        tx_buffer[loc + 1] = (bitpatterns[pixels[i].green >> 2 & 0x03] << 8) | bitpatterns[pixels[i].green & 0x03];

        tx_buffer[loc + 2] = (bitpatterns[pixels[i].red   >> 6 & 0x03] << 8) | bitpatterns[pixels[i].red >> 4 & 0x03];
        tx_buffer[loc + 3] = (bitpatterns[pixels[i].red   >> 2 & 0x03] << 8) | bitpatterns[pixels[i].red & 0x03];

        tx_buffer[loc + 4] = (bitpatterns[pixels[i].blue  >> 6 & 0x03] << 8) | bitpatterns[pixels[i].blue >> 4 & 0x03];
        tx_buffer[loc + 5] = (bitpatterns[pixels[i].blue  >> 2 & 0x03] << 8) | bitpatterns[pixels[i].blue & 0x03];
    }
    i2s_send();
}

struct pixel_t pixel_buf[NUM_LED];

const struct pixel_t pixel_red = { // moss green (div by 15)
    .red = 1,
    .green = 0,
    .blue = 0
};

const struct pixel_t pixel_green = { // moss green (div by 15)
    .red = 0,
    .green = 1,
    .blue = 0
};

const struct pixel_t pixel_blue = { // moss green (div by 15)
    .red = 0,
    .green = 0,
    .blue = 1
};

const struct pixel_t pixel_on = { // moss green (div by 15)
    .red = 2,
    .green = 1,
    .blue = 0
};

const struct pixel_t pixel_off = { // moss green (div by 15)
    .red = 0,
    .green = 0,
    .blue = 0
};

const uint8_t number_select_lights = { 0, 2, 5, 7, 18, 10, 20, 21, 19, 13, 23, 16, 24, 25 };
int ui_mode = { UI_MODE_PLAY }

void set_ui_mode(int mode)
{
    ui_mode = mode;
}

int get_ui_mode(void)
{
    return ui_mode;
}

void render_lights(void)
{
    struct Sel *sels = get_sels();
    int current_slot = get_current_slot();
    struct Config *config = get_config();

    switch(ui_mode){
        case UI_MODE_PLAY:
            pixel_buf[0] = *(sels[0].p)   == 0 ? pixel_on : pixel_off; // o1sqr
            pixel_buf[1] = *(sels[0].p)   == 1 ? pixel_on : pixel_off;  // o1saw
            pixel_buf[2] = *(sels[1].p)   == 0 ? pixel_on : pixel_off;  // o1oct0
            pixel_buf[3] = *(sels[1].p)   == 1 ? pixel_on : pixel_off;  // o1oct-1
            pixel_buf[4] = *(sels[1].p)   == 2 ? pixel_on : pixel_off;  // o1oct-2

            pixel_buf[5] = *(sels[2].p)   == 0 ? pixel_on : pixel_off;  // o2sqr
            pixel_buf[6] = *(sels[2].p)   == 1 ? pixel_on : pixel_off;  // o2saw
            pixel_buf[7] = *(sels[3].p)   == 0 ? pixel_on : pixel_off;  // o2oct0
            pixel_buf[8] = *(sels[3].p)   == 1 ? pixel_on : pixel_off;  // o2oct-1
            pixel_buf[9] = *(sels[3].p)   == 2 ? pixel_on : pixel_off;  // o2oct-2

            pixel_buf[10] = *(sels[5].p)  == 0 ? pixel_on : pixel_off; // lfotri
            pixel_buf[11] = *(sels[5].p)  == 1 ? pixel_on : pixel_off; // lfosqr
            pixel_buf[12] = *(sels[5].p)  == 2 ? pixel_on : pixel_off; // lfornd

            pixel_buf[13] = *(sels[9].p)  == 0 ? pixel_on : pixel_off; // vcfhp
            pixel_buf[14] = *(sels[9].p)  == 1 ? pixel_on : pixel_off; // vcflp
            pixel_buf[15] = *(sels[9].p)  == 2 ? pixel_on : pixel_off; // vcfbp

            pixel_buf[16] = *(sels[11].p) == 0 ? pixel_on : pixel_off; // envasr
            pixel_buf[17] = *(sels[11].p) == 1 ? pixel_on : pixel_off; // envar

            pixel_buf[18] = pixel_off; // lfo.osc
            pixel_buf[19] = pixel_off; // lfo.vcf
            pixel_buf[20] = pixel_off; // lfo.vcA
            pixel_buf[21] = pixel_off; // lfo.env

            pixel_buf[22] = pixel_off; // vca

            pixel_buf[23] = pixel_off; // env.vca
            pixel_buf[24] = pixel_off; // env.vcf
            pixel_buf[25] = pixel_off; // env.osc
            break;
        case UI_MODE_SAVE:
        case UI_MODE_LOAD:
        {
            for(int i=0; i<NUM_LED; i++)
            {
                pixel_buf[i] = pixel_off; 
            }

            for(int i=0; i<sizeof(number_select_lights); i++)
            {
                if(i == current_slot)
                {
                    pixel_buf[i] = pixel_blue;
                }
                else if(config->empty[i])
                {
                    pixel_buf[i] = pixel_green;
                }
                else
                {
                    pixel_buf[i] = pixel_red;
                }
            }
            break;
        }
        default: break;
    }

    rgb_set_color(pixel_buf);
}