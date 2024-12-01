#include "bflb_i2s.h"
#include "bflb_gpio.h"
#include "bflb_dma.h"
#include "bl616_glb_gpio.h"
#include "bflb_l1c.h"
#include "bl616_irq.h"
#include "bflb_irq.h"
#include "board.h"
#include "rgb_led.h"
#include "midi.h"
#include "flash.h"
#include "global.h"
#include "spi_rgb.h"

#define PIXEL_SIZE 3 // each colour takes 4 bytes
#define NUM_LED 37

static ATTR_NOCACHE_NOINIT_RAM_SECTION uint32_t ping[128] __ALIGNED(4);
static ATTR_NOCACHE_NOINIT_RAM_SECTION uint32_t pong[128] __ALIGNED(4);
static volatile uint8_t dma_tc_flag0 = 0;
static struct bflb_device_s *dma0_ch1;

static const uint16_t bitpatterns[4] = {0x88, 0x8e, 0xe8, 0xee}; // original

static struct bflb_dma_channel_lli_pool_s tx_llipool_ping[1];
static struct bflb_dma_channel_lli_transfer_s tx_transfers_ping[1];
static struct bflb_dma_channel_lli_pool_s tx_llipool_pong[1];
static struct bflb_dma_channel_lli_transfer_s tx_transfers_pong[1];

struct bflb_device_s *i2s0;
struct pixel_t pixel_buf[NUM_LED] = {0};

static void refresh_dma(int ping_pong)
{
    if (ping_pong)
    {
        tx_transfers_pong[0].src_addr = (uint32_t)pong;
        tx_transfers_pong[0].dst_addr = (uint32_t)DMA_ADDR_I2S_TDR;
        tx_transfers_pong[0].nbytes = sizeof pong;
        bflb_l1c_dcache_clean_range(pong, sizeof pong);
        bflb_dma_channel_lli_reload(dma0_ch1, tx_llipool_pong, 1, tx_transfers_pong, 1);
        bflb_dma_channel_start(dma0_ch1);
    }
    else
    {
        tx_transfers_ping[0].src_addr = (uint32_t)ping;
        tx_transfers_ping[0].dst_addr = (uint32_t)DMA_ADDR_I2S_TDR;
        tx_transfers_ping[0].nbytes = sizeof ping;
        bflb_l1c_dcache_clean_range(ping, sizeof ping);
        bflb_dma_channel_lli_reload(dma0_ch1, tx_llipool_ping, 1, tx_transfers_ping, 1);
        bflb_dma_channel_start(dma0_ch1);
    }
}

void encode_rgb(uint32_t *buf){
    for (int i = 0; i < NUM_LED; i++) {
        int loc = i * PIXEL_SIZE;

        buf[loc]     = (bitpatterns[pixel_buf[i].green >> 6 & 0x03]  << 24) | 
                        (bitpatterns[pixel_buf[i].green >> 4 & 0x03] << 16) | 
                        (bitpatterns[pixel_buf[i].green >> 2 & 0x03] << 8)  | 
                         bitpatterns[pixel_buf[i].green & 0x03];

        buf[loc + 1] = (bitpatterns[pixel_buf[i].red >> 6 & 0x03]    << 24) | 
                        (bitpatterns[pixel_buf[i].red >> 4 & 0x03]   << 16) |
                        (bitpatterns[pixel_buf[i].red   >> 2 & 0x03] << 8)  | 
                         bitpatterns[pixel_buf[i].red & 0x03];
                         
        buf[loc + 2] = (bitpatterns[pixel_buf[i].blue >> 6 & 0x03]   << 24) | 
                        (bitpatterns[pixel_buf[i].blue >> 4 & 0x03]  << 16) |
                        (bitpatterns[pixel_buf[i].blue  >> 2 & 0x03] << 8)  |
                         bitpatterns[pixel_buf[i].blue & 0x03];
    }
}

static uint64_t times[100] = {0};
static size_t time_p = 0;

void update_leds(void)
{
    render_lights();
    encode_rgb(ping);
    // spi_rgb_start(ping, 128);
    spi_rgb_send(ping, 128);
}
// void update_leds(void)
// {
//     static int ping_pong = 1;
//     refresh_dma(ping_pong);
//     render_lights();
//     encode_rgb(ping_pong == 0 ? pong : ping);
//     ping_pong = ping_pong == 0 ? 1 : 0;
// }

static void i2s_gpio_init()
{
    struct bflb_device_s *gpio;
    gpio = bflb_device_get_by_name("gpio");
    bflb_gpio_init(gpio, GPIO_PIN_16, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, GPIO_PIN_17, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, GPIO_PIN_10, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, GPIO_PIN_11, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
}

static struct bflb_i2s_config_s i2s_cfg = {
    .bclk_freq_hz = 93750 * 16 * 2, // bclk = Sampling_rate * frame_width * channel_num original
    .role = I2S_ROLE_MASTER,
    .format_mode = I2S_MODE_LEFT_JUSTIFIED,
    .channel_mode = I2S_CHANNEL_MODE_NUM_2,
    .frame_width = I2S_SLOT_WIDTH_32,
    .data_width = I2S_SLOT_WIDTH_32,
    .fs_offset_cycle = 0,
    .tx_fifo_threshold = 0,
    .rx_fifo_threshold = 0,
};

static struct bflb_dma_channel_config_s tx_config = {
    .direction = DMA_MEMORY_TO_PERIPH,
    .src_req = DMA_REQUEST_NONE,
    .dst_req = DMA_REQUEST_I2S_TX,
    .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE,
    .dst_addr_inc = DMA_ADDR_INCREMENT_DISABLE,
    .src_burst_count = DMA_BURST_INCR1,
    .dst_burst_count = DMA_BURST_INCR1,
    .src_width = DMA_DATA_WIDTH_32BIT,
    .dst_width = DMA_DATA_WIDTH_32BIT,
};

void rgb_led_init(){
    i2s_gpio_init();
    i2s0 = bflb_device_get_by_name("i2s0");
    dma0_ch1 = bflb_device_get_by_name("dma0_ch1");

    bflb_i2s_init(i2s0, &i2s_cfg);
    bflb_i2s_link_txdma(i2s0, true);
    bflb_dma_channel_init(dma0_ch1, &tx_config);
    // bflb_dma_channel_irq_attach(dma0_ch1, dma0_ch1_isr, NULL);
    bflb_i2s_feature_control(i2s0, I2S_CMD_DATA_ENABLE, I2S_CMD_DATA_ENABLE_TX);

    memset(ping, 0, sizeof ping);
    memset(pong, 0, sizeof pong);

    tx_transfers_ping[0].src_addr = (uint32_t)ping;
    tx_transfers_ping[0].dst_addr = (uint32_t)DMA_ADDR_I2S_TDR;
    tx_transfers_ping[0].nbytes = sizeof ping;

    bflb_l1c_dcache_clean_range(ping, sizeof ping);
    bflb_dma_channel_lli_reload(dma0_ch1, tx_llipool_ping, 1, tx_transfers_ping, 1);
    bflb_dma_channel_start(dma0_ch1);
    // bflb_irq_set_priority(dma0_ch1->irq_num, IRQ_PRIO_RGB, 0);
    // bflb_irq_set_priority(i2s0->irq_num, IRQ_PRIO_RGB, 0);
}




//******************
//******************
//******************
//******************
//******************

// // #define PIXEL_SIZE 12 // each colour takes 4 bytes
// #define PIXEL_SIZE 3 // each colour takes 4 bytes
// // #define PIXEL_SIZE 6 // each colour takes 4 bytes
// // #define NUM_LED 3
// // #define NUM_LED 26 // Original
// #define NUM_LED 37

// struct bflb_device_s *i2s0;

// bool rgb_rendering = false;

// struct pixel_t pixel_buf[NUM_LED] = {0};

// void rgb_task(void *pvParameters)
// {
//     while (1) {
//         if(!rgb_rendering)
//         {
//             // rgb_rendering = true;
//             render_lights();
//             // test_rgb_lights();
//             // rgb_set_color(NULL);
//         }
//         // vTaskDelay(10);
//         vTaskDelay(100);
//         // vTaskDelay(1000);
//     }
//     vTaskDelete(NULL);
// }

// static void i2s_gpio_init()
// {
//     struct bflb_device_s *gpio;
//     gpio = bflb_device_get_by_name("gpio");
//     bflb_gpio_init(gpio, GPIO_PIN_16, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
//     bflb_gpio_init(gpio, GPIO_PIN_17, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
//     bflb_gpio_init(gpio, GPIO_PIN_10, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
//     bflb_gpio_init(gpio, GPIO_PIN_11, GPIO_FUNC_I2S | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
// }

// static ATTR_NOCACHE_NOINIT_RAM_SECTION uint32_t tx_buffer_a[128] __ALIGNED(4);
// static ATTR_NOCACHE_NOINIT_RAM_SECTION uint32_t tx_buffer_b[128] __ALIGNED(4);
// // static ATTR_NOCACHE_NOINIT_RAM_SECTION uint16_t tx_buffer_a[256] __ALIGNED(4);
// // static ATTR_NOCACHE_NOINIT_RAM_SECTION uint16_t tx_buffer_b[256] __ALIGNED(4);
// static uint8_t ping_pong = 0;
// static volatile uint8_t dma_tc_flag0 = 0;
// static struct bflb_device_s *dma0_ch1;
// static struct bflb_dma_channel_lli_pool_s tx_llipool[1];
// static struct bflb_dma_channel_lli_transfer_s tx_transfers[1];

// void dma0_ch1_isr(void *arg)
// {
//     // dma_tc_flag0++;
//     // bflb_dma_channel_stop(dma0_ch1);
//     // rgb_rendering = false;
//     // bflb_i2s_feature_control(i2s0, I2S_CMD_DATA_ENABLE, false);
//     bflb_i2s_deinit(i2s0);
// }

// static struct bflb_i2s_config_s i2s_cfg = {
//     // .bclk_freq_hz = 130000 * 16 * 2, /* bclk = Sampling_rate * frame_width * channel_num */
//     // .bclk_freq_hz = 8000 * 32, /* bclk = Sampling_rate * frame_width */
//     // .bclk_freq_hz = 93750 * 32 * 2, /* bclk = Sampling_rate * frame_width * channel_num */
//     .bclk_freq_hz = 93750 * 16 * 2, // bclk = Sampling_rate * frame_width * channel_num original
//     .role = I2S_ROLE_MASTER,
//     .format_mode = I2S_MODE_LEFT_JUSTIFIED,
//     // .channel_mode = I2S_CHANNEL_MODE_NUM_1,
//     .channel_mode = I2S_CHANNEL_MODE_NUM_2,
//     .frame_width = I2S_SLOT_WIDTH_32,
//     .data_width = I2S_SLOT_WIDTH_32,
//     // .frame_width = I2S_SLOT_WIDTH_16,
//     // .data_width = I2S_SLOT_WIDTH_16,
//     .fs_offset_cycle = 0,
//     .tx_fifo_threshold = 0,
//     .rx_fifo_threshold = 0,
// };

// static struct bflb_dma_channel_config_s tx_config = {
//     .direction = DMA_MEMORY_TO_PERIPH,
//     .src_req = DMA_REQUEST_NONE,
//     .dst_req = DMA_REQUEST_I2S_TX,
//     .src_addr_inc = DMA_ADDR_INCREMENT_ENABLE,
//     .dst_addr_inc = DMA_ADDR_INCREMENT_DISABLE,
//     .src_burst_count = DMA_BURST_INCR1,
//     .dst_burst_count = DMA_BURST_INCR1,
//     .src_width = DMA_DATA_WIDTH_32BIT,
//     .dst_width = DMA_DATA_WIDTH_32BIT,
// };

// void rgb_led_start(){
//     bflb_i2s_init(i2s0, &i2s_cfg);
//     bflb_i2s_link_txdma(i2s0, true);

//     bflb_dma_channel_init(dma0_ch1, &tx_config);
//     // bflb_dma_channel_irq_attach(dma0_ch1, dma0_ch1_isr, NULL);
//     // bflb_irq_set_priority(dma0_ch1->irq_num, 15, 0);
//     bflb_irq_set_priority(i2s0->irq_num, 15, 0);
//     bflb_i2s_feature_control(i2s0, I2S_CMD_DATA_ENABLE, I2S_CMD_DATA_ENABLE_TX);
//     // printf("rgb setup done\n");
// }

// void rgb_led_init(){
//     i2s_gpio_init();
//     i2s0 = bflb_device_get_by_name("i2s0");
//     dma0_ch1 = bflb_device_get_by_name("dma0_ch2");
//     rgb_led_start();
// }

// void i2s_send(void)
// {
//     // rgb_led_start();
//     // bflb_i2s_feature_control(i2s0, I2S_CMD_DATA_ENABLE, I2S_CMD_DATA_ENABLE_TX);
//     // bflb_i2s_feature_control(i2s0, I2S_CMD_CLEAR_TX_FIFO, true);
//     // uint32_t *buf = ping_pong == 0 ? tx_buffer_a : tx_buffer_b;
//     // uint16_t *buf = ping_pong == 0 ? tx_buffer_a : tx_buffer_b;
//     uint32_t src_addr = ping_pong == 0 ? tx_buffer_a : tx_buffer_b;
//     // tx_transfers[0].src_addr = ping_pong == 0 ? (uint32_t)tx_buffer_a : (uint32_t)tx_buffer_b;
//     tx_transfers[0].src_addr = src_addr;
//     tx_transfers[0].dst_addr = (uint32_t)DMA_ADDR_I2S_TDR;
//     tx_transfers[0].nbytes = sizeof(tx_buffer_a);
//     bflb_l1c_dcache_clean_range(src_addr, sizeof src_addr);
//     bflb_dma_channel_lli_reload(dma0_ch1, tx_llipool, 1, tx_transfers, 1);
//     bflb_dma_channel_start(dma0_ch1);
//     ping_pong = ping_pong == 0 ? 1 : 0;
// }

// static const uint16_t bitpatterns[4] = {0x88, 0x8e, 0xe8, 0xee}; // original
// static const uint16_t bitpatterns[4] = {0x88, 0x8c, 0xc8, 0xcc};

// // uint8_t one = 0b110
// // uint8_t two = 0b100

// uint32_t onezero1 = 0xC03E0C03;
// uint32_t onezero2 = 0xE0C03E0C;
// uint32_t onezero3 = 0x03E0C03E;
// uint32_t onezero4 = 0x0C03E0C0;
// uint32_t onezero5 = 0x3E0C03E0;

// void rgb_set_color(struct pixel_t *pixels){
//     // printf("rgb set color");
//     uint32_t *buf = ping_pong == 0 ? tx_buffer_a : tx_buffer_b;
//     // uint16_t *buf = ping_pong == 0 ? tx_buffer_a : tx_buffer_b;
//     memset(buf, 0, sizeof tx_buffer_a);
//     // buf[0] = onezero1;
//     // buf[1] = onezero2;
//     // buf[2] = onezero3;
//     // buf[3] = onezero4;
//     // buf[4] = onezero5;
//     // buf[5] = onezero1;
//     // buf[6] = onezero2;
//     // buf[7] = onezero3;
//     // buf[8] = onezero4;
//     // buf[9] = onezero5;
//     // buf[10] = onezero1;
//     // buf[11] = onezero2;
//     // buf[12] = onezero3;
//     // buf[13] = onezero4;
//     // buf[14] = onezero5;
//     // buf[15] = onezero1;
//     // buf[16] = onezero2;
//     // buf[17] = onezero3;
//     // buf[18] = onezero4;
//     // buf[19] = onezero5;
//     // buf[20] = onezero1;
//     // buf[21] = onezero2;
//     // buf[22] = onezero3;
//     // buf[23] = onezero4;
//     // buf[24] = onezero5;
//     // buf[25] = onezero1;
//     // buf[26] = onezero2;
//     // buf[27] = onezero3;
//     // buf[28] = onezero4;
//     // buf[29] = onezero5;
//     // buf[30] = onezero1;
//     // buf[31] = onezero2;
//     // buf[32] = onezero3;
//     // buf[33] = onezero4;
//     // buf[34] = onezero5;
//     // buf[35] = onezero1;
//     // buf[36] = onezero2;
//     // buf[37] = onezero3;
//     // buf[38] = onezero4;
//     // buf[39] = onezero5;



//     for (int i = 0; i < NUM_LED; i++) {
//         int loc = i * PIXEL_SIZE;

//         buf[loc]     = (bitpatterns[pixels[i].green >> 6 & 0x03]  << 24) | 
//                         (bitpatterns[pixels[i].green >> 4 & 0x03] << 16) | 
//                         (bitpatterns[pixels[i].green >> 2 & 0x03] << 8)  | 
//                          bitpatterns[pixels[i].green & 0x03];

//         buf[loc + 1] = (bitpatterns[pixels[i].red >> 6 & 0x03]    << 24) | 
//                         (bitpatterns[pixels[i].red >> 4 & 0x03]   << 16) |
//                         (bitpatterns[pixels[i].red   >> 2 & 0x03] << 8)  | 
//                          bitpatterns[pixels[i].red & 0x03];
                         
//         buf[loc + 2] = (bitpatterns[pixels[i].blue >> 6 & 0x03]   << 24) | 
//                         (bitpatterns[pixels[i].blue >> 4 & 0x03]  << 16) |
//                         (bitpatterns[pixels[i].blue  >> 2 & 0x03] << 8)  |
//                          bitpatterns[pixels[i].blue & 0x03];
//         // buf[loc]     = (bitpatterns[pixels[i].green >> 6 & 0x03] << 8) | bitpatterns[pixels[i].green >> 4 & 0x03];
//         // buf[loc + 1] = (bitpatterns[pixels[i].green >> 2 & 0x03] << 8) | bitpatterns[pixels[i].green & 0x03];

//         // buf[loc + 2] = (bitpatterns[pixels[i].red   >> 6 & 0x03] << 8) | bitpatterns[pixels[i].red >> 4 & 0x03];
//         // buf[loc + 3] = (bitpatterns[pixels[i].red   >> 2 & 0x03] << 8) | bitpatterns[pixels[i].red & 0x03];

//         // buf[loc + 4] = (bitpatterns[pixels[i].blue  >> 6 & 0x03] << 8) | bitpatterns[pixels[i].blue >> 4 & 0x03];
//         // buf[loc + 5] = (bitpatterns[pixels[i].blue  >> 2 & 0x03] << 8) | bitpatterns[pixels[i].blue & 0x03];
//     }
//     i2s_send();
// }

// struct pixel_t pixel_buf[NUM_LED];

const struct pixel_t pixel_red = {
    .red = 1,
    .green = 0,
    .blue = 0
};

const struct pixel_t pixel_green = {
    .red = 0,
    .green = 1,
    .blue = 0
};

const struct pixel_t pixel_blue = {
    .red = 0,
    .green = 0,
    .blue = 1
};

const struct pixel_t pixel_on = {
    .red = 4,
    .green = 3,
    .blue = 1
    // .red = 5,
    // .green = 30,
    // .blue = 0
    // .red = 2,
    // .green = 1,
    // .blue = 0
};

const struct pixel_t pixel_off = {
    .red = 0,
    .green = 0,
    .blue = 0
};

const struct pixel_t p1 = {
    .red = 1,
    .green = 1,
    .blue = 0
};
const struct pixel_t light_blue = {
    .red = 0,
    .green = 1,
    .blue = 1
};
const struct pixel_t light_pink = {
    .red = 2,
    .green = 1,
    .blue = 1
};
const struct pixel_t light_green = {
    .red = 1,
    .green = 2,
    .blue = 0
};

const uint8_t number_select_lights[NUM_PRESETS] = { 0, 2, 7, 6, 17, 10, 13, 14, 15, 16, 12, 23, 18 };
int ui_mode = UI_MODE_PLAY;

void set_ui_mode(int mode)
{
    ui_mode = mode;
}

int get_ui_mode(void)
{
    return ui_mode;
}

struct pixel_t pixel_def(float val){
    struct pixel_t pixel = {
        .red = (uint8_t)(10.0 * val),
        .green = (uint8_t)(150.0 * val),
        .blue = (uint8_t)(50.0 * val)
    };
    return pixel;
}

float led_display[10] = {0};

void set_led_display(float val, float min, float max){
    val -= min;
    max -= min;
    float out = val / max * 10;
    for(int i=0; i<11; i++)
    {
        if(out > (i + 1))
        {
            led_display[i] = 1;
        }
        else if(out < i)
        {
            led_display[i] = 0;
        }
        else
        {
            led_display[i] = out - i; // just the fractional part
        }
    }
}

void render_lights(void){

    int current_slot = get_current_slot();
    struct Sel *sels = get_sels();
    struct Mod *mods = get_mods();
    struct Sigs *sigs = get_signals();
    struct Config *config = get_config();

    switch(ui_mode){
        case UI_MODE_PLAY:
            pixel_buf[0] = ((*(sels[0].p) == 0) || (*(sels[0].p) == 2)) ? pixel_on : pixel_off; // o1sqr
            pixel_buf[1] = ((*(sels[0].p) == 1) || (*(sels[0].p) == 2)) ? pixel_on : pixel_off;  // o1saw

            pixel_buf[2] = *(sels[1].p)   == 0 ? pixel_on : pixel_off;  // o1oct0
            pixel_buf[3] = *(sels[1].p)   == 1 ? pixel_on : pixel_off;  // o1oct-1
            pixel_buf[4] = *(sels[1].p)   == 2 ? pixel_on : pixel_off;  // o1oct-2

            pixel_buf[7] = *(sels[2].p)   == 0 ? pixel_on : pixel_off;  // o2oct0
            pixel_buf[8] = *(sels[2].p)   == 1 ? pixel_on : pixel_off;  // o2oct-1
            pixel_buf[9] = *(sels[2].p)   == 2 ? pixel_on : pixel_off;  // o2oct-2

            pixel_buf[6] = ((*(sels[3].p) == 0) || (*(sels[3].p) == 2)) ? pixel_on : pixel_off;  // o2sqr
            pixel_buf[5] = ((*(sels[3].p) == 1) || (*(sels[3].p) == 2)) ? pixel_on : pixel_off;  // o2saw


            pixel_buf[10] = *(sels[7].p)  == 0 ? pixel_on : pixel_off; // lfotri
            pixel_buf[11] = *(sels[7].p)  == 1 ? pixel_on : pixel_off; // lfosqr
            pixel_buf[12] = *(sels[7].p)  == 2 ? pixel_on : pixel_off; // lfornd
            pixel_buf[14] = *(sels[9].p)  == 1 ? pixel_on : pixel_off; // lfornd

            pixel_buf[23] = *(sels[13].p)  == 0 ? pixel_on : pixel_off; // vcfhp
            pixel_buf[24] = *(sels[13].p)  == 1 ? pixel_on : pixel_off; // vcflp
            pixel_buf[25] = *(sels[13].p)  == 2 ? pixel_on : pixel_off; // vcfbp

            // pixel_buf[16] = *(sels[11].p) == 0 ? pixel_on : pixel_off; // envasr
            // pixel_buf[17] = *(sels[11].p) == 1 ? pixel_on : pixel_off; // envar

            pixel_buf[17] = pixel_def((*sigs->lfo) * (*mods[6].p));     // lfo.pwm
            pixel_buf[15] = pixel_def((*sigs->lfo) * (*mods[10].p));    // lfo.osc
            pixel_buf[16] = pixel_def((*sigs->lfo) * (*mods[11].p));    // lfo.vcf
            pixel_buf[13] = pixel_def((*sigs->lfo) * (*mods[8].p));     // lfo.vca


            pixel_buf[20] = pixel_def((*(sigs->env)) * (*mods[18].p)); // env.vcf
            pixel_buf[19] = pixel_def((*(sigs->env)) * (*mods[15].p)); // env.vca
            pixel_buf[21] = pixel_def((*(sigs->env)) * (*mods[20].p)); // env.osc
            pixel_buf[22] = pixel_def((*(sigs->env)) * (*mods[24].p)); // env.pwm

            // pixel_buf[22] = pixel_off; // vca
            pixel_buf[18] = pixel_def(*(sigs->vca)); // vca
            // pixel_buf[18] = pixel_def((*(sigs->env)) * (*mods[15].p)); // vca

            pixel_buf[36] = pixel_on;
            pixel_buf[35] = led_display[0] == 1 ? pixel_on : led_display[0] == 0 ? pixel_off : pixel_def(led_display[0]);
            pixel_buf[34] = led_display[1] == 1 ? pixel_on : led_display[1] == 0 ? pixel_off : pixel_def(led_display[1]); 
            pixel_buf[33] = led_display[2] == 1 ? pixel_on : led_display[2] == 0 ? pixel_off : pixel_def(led_display[2]); 
            pixel_buf[32] = led_display[3] == 1 ? pixel_on : led_display[3] == 0 ? pixel_off : pixel_def(led_display[3]); 
            pixel_buf[31] = led_display[4] == 1 ? pixel_on : led_display[4] == 0 ? pixel_off : pixel_def(led_display[4]); 
            pixel_buf[30] = led_display[5] == 1 ? pixel_on : led_display[5] == 0 ? pixel_off : pixel_def(led_display[5]); 
            pixel_buf[29] = led_display[6] == 1 ? pixel_on : led_display[6] == 0 ? pixel_off : pixel_def(led_display[6]); 
            pixel_buf[28] = led_display[7] == 1 ? pixel_on : led_display[7] == 0 ? pixel_off : pixel_def(led_display[7]); 
            pixel_buf[27] = led_display[8] == 1 ? pixel_on : led_display[8] == 0 ? pixel_off : pixel_def(led_display[8]); 
            pixel_buf[26] = led_display[9] == 1 ? pixel_on : led_display[9] == 0 ? pixel_off : pixel_def(led_display[9]); 

            break;
        case UI_MODE_SAVE:
        {
            for(int i=0; i<NUM_LED; i++)
            {
                pixel_buf[i] = pixel_off; 
            }

            for(int i=0; i<NUM_PRESETS; i++)
            {
                uint8_t light_num = number_select_lights[i];
                if(i == current_slot)
                {
                    pixel_buf[light_num] = light_blue;
                }
                else if(config->empty[i])
                {
                    pixel_buf[light_num] = light_green;
                }
                else
                {
                    pixel_buf[light_num] = light_pink;
                }
            }
            break;
        }
        case UI_MODE_LOAD:
        {
            for(int i=0; i<NUM_LED; i++)
            {
                pixel_buf[i] = pixel_off; 
            }

            for(int i=0; i<NUM_PRESETS; i++)
            {
                uint8_t light_num = number_select_lights[i];
                if(i == current_slot)
                {
                    pixel_buf[light_num] = light_blue;
                }
                else if(!config->empty[i])
                {
                    pixel_buf[light_num] = light_green;
                }
            }
            break;
        }
        case UI_MODE_LEARN:
        {
            int current = get_mode_learn_current_cc();
            for(int i=0; i<NUM_LED; i++)
            {
                pixel_buf[i] = pixel_off; 
            }

            for(int i=0; i < (NUM_CC - 1); i++)
            {
                uint8_t light_num = number_select_lights[i];
                int cc = i + 1;
                if(cc == current)
                {
                    pixel_buf[light_num] = light_blue;
                }
                else
                {
                    pixel_buf[light_num] = light_green;
                }
            }
            break;
        }
        default: break;
    }

    // rgb_set_color(pixel_buf);
}

// void test_rgb_lights(){
//     for(int i=0; i<NUM_LED; i++)
//     {
//         pixel_buf[i] = pixel_on;
//     }
//     // pixel_buf[0]  = pixel_on;
//     // pixel_buf[1]  = pixel_on;
//     // pixel_buf[2]  = pixel_on;
//     rgb_set_color(pixel_buf);
// }
