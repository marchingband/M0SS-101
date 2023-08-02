#include "bflb_i2s.h"
#include "bflb_gpio.h"
#include "bflb_dma.h"
#include "bl616_glb_gpio.h"
#include "bl616_irq.h"
#include "board.h"
#include "rgb_led.h"

// #define PIXEL_SIZE 12 // each colour takes 4 bytes
#define PIXEL_SIZE 6 // each colour takes 4 bytes
#define LED_NUMBER 5

static void i2s_gpio_init()
{
    struct bflb_device_s *gpio;
    gpio = bflb_device_get_by_name("gpio");
    bflb_gpio_init(gpio, GPIO_PIN_16, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, GPIO_PIN_17, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
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
    printf("tc done\r\n");
    bflb_dma_channel_stop(dma0_ch1);
}


void rgb_led_init(){

    i2s_gpio_init();

    struct bflb_device_s *i2s0;

    // tx_buffer[0] = 0b1101101101101101;
    // tx_buffer[1] = 0b1011011011011011;
    // tx_buffer[2] = 0b0110110110110110;
    // tx_buffer[3] = 0b0110110110110110;
    // tx_buffer[4] = 0b0110110110000000;
    
    // for (int i=5; i < 256; i++) {
    //     tx_buffer[i] = 0;
    // }

    // tx_buffer[256] = 0b1001001001001001;
    // tx_buffer[257] = 0b0010010010010010;
    // tx_buffer[258] = 0b0100100100100100;
    // tx_buffer[259] = 0b1001001001001001;
    // tx_buffer[260] = 0b0010010000000000;

    // for (int i=261; i < 512; i++) {
    //     tx_buffer[i] = 0;
    // }

    struct bflb_i2s_config_s i2s_cfg = {
        .bclk_freq_hz = 130000 * 16 * 2, /* bclk = Sampling_rate * frame_width * channel_num */
        // .bclk_freq_hz = 93750 * 16 * 2, /* bclk = Sampling_rate * frame_width * channel_num */
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

    // board_i2s_gpio_init();

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
static uint8_t out_buffer[LED_NUMBER * PIXEL_SIZE] = {0};

void rgb_set_color(struct pixel_t *pixels){
    memset(tx_buffer, 0, sizeof tx_buffer);
    for (uint16_t i = 0; i < LED_NUMBER; i++) {
        int loc = i * PIXEL_SIZE;

        // out_buffer[loc] = bitpatterns[pixels[i].green >> 6 & 0x03];
        // out_buffer[loc + 1] = bitpatterns[pixels[i].green >> 4 & 0x03];
        // out_buffer[loc + 2] = bitpatterns[pixels[i].green >> 2 & 0x03];
        // out_buffer[loc + 3] = bitpatterns[pixels[i].green & 0x03];

        // out_buffer[loc + 4] = bitpatterns[pixels[i].red >> 6 & 0x03];
        // out_buffer[loc + 5] = bitpatterns[pixels[i].red >> 4 & 0x03];
        // out_buffer[loc + 6] = bitpatterns[pixels[i].red >> 2 & 0x03];
        // out_buffer[loc + 7] = bitpatterns[pixels[i].red & 0x03];

        // out_buffer[loc + 8] = bitpatterns[pixels[i].blue >> 6 & 0x03];
        // out_buffer[loc + 9] = bitpatterns[pixels[i].blue >> 4 & 0x03];
        // out_buffer[loc + 10] = bitpatterns[pixels[i].blue >> 2 & 0x03];
        // out_buffer[loc + 11] = bitpatterns[pixels[i].blue & 0x03];

        tx_buffer[loc]     = (bitpatterns[pixels[i].green >> 6 & 0x03] << 8) | bitpatterns[pixels[i].green >> 4 & 0x03];
        tx_buffer[loc + 1] = (bitpatterns[pixels[i].green >> 2 & 0x03] << 8) | bitpatterns[pixels[i].green & 0x03];

        tx_buffer[loc + 2] = (bitpatterns[pixels[i].red   >> 6 & 0x03] << 8) | bitpatterns[pixels[i].red >> 4 & 0x03];
        tx_buffer[loc + 3] = (bitpatterns[pixels[i].red   >> 2 & 0x03] << 8) | bitpatterns[pixels[i].red & 0x03];

        tx_buffer[loc + 4] = (bitpatterns[pixels[i].blue  >> 6 & 0x03] << 8) | bitpatterns[pixels[i].blue >> 4 & 0x03];
        tx_buffer[loc + 5] = (bitpatterns[pixels[i].blue  >> 2 & 0x03] << 8) | bitpatterns[pixels[i].blue & 0x03];
    }
    i2s_send();
}



void rgb_led_white(){
    i2s_send();
}

