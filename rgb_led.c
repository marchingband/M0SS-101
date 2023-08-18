#include "bflb_i2s.h"
#include "bflb_gpio.h"
#include "bflb_dma.h"
#include "bl616_glb_gpio.h"
#include "bl616_irq.h"
#include "board.h"
#include "rgb_led.h"
#include "midi.h"
#include "flash.h"

// #define PIXEL_SIZE 12 // each colour takes 4 bytes
#define PIXEL_SIZE 6 // each colour takes 4 bytes
#define NUM_LED 26

struct bflb_device_s *i2s0;

bool rgb_rendering = false;

void rgb_task(void *pvParameters)
{
    while (1) {
        if(!rgb_rendering)
        {
            rgb_rendering = true;
            render_lights();
        }
        vTaskDelay(10);
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

static ATTR_NOCACHE_NOINIT_RAM_SECTION uint16_t tx_buffer_a[256] __ALIGNED(4);
static ATTR_NOCACHE_NOINIT_RAM_SECTION uint16_t tx_buffer_b[256] __ALIGNED(4);
static uint8_t ping_pong = 0;
static volatile uint8_t dma_tc_flag0 = 0;
static struct bflb_device_s *dma0_ch1;
static struct bflb_dma_channel_lli_pool_s tx_llipool[1];
static struct bflb_dma_channel_lli_transfer_s tx_transfers[1];

void dma0_ch1_isr(void *arg)
{
    // dma_tc_flag0++;
    // bflb_dma_channel_stop(dma0_ch1);
    rgb_rendering = false;
    // bflb_i2s_feature_control(i2s0, I2S_CMD_DATA_ENABLE, false);
}

void rgb_led_init(){
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

    dma0_ch1 = bflb_device_get_by_name("dma0_ch2");
    bflb_dma_channel_init(dma0_ch1, &tx_config);
    bflb_dma_channel_irq_attach(dma0_ch1, dma0_ch1_isr, NULL);
    bflb_i2s_feature_control(i2s0, I2S_CMD_DATA_ENABLE, I2S_CMD_DATA_ENABLE_TX);
    printf("rgb setup done\n");
}

void i2s_send(void)
{
    // bflb_i2s_feature_control(i2s0, I2S_CMD_DATA_ENABLE, I2S_CMD_DATA_ENABLE_TX);
    bflb_i2s_feature_control(i2s0, I2S_CMD_CLEAR_TX_FIFO, true);
    uint16_t *buf = ping_pong == 0 ? tx_buffer_a : tx_buffer_b;
    tx_transfers[0].src_addr = ping_pong == 0 ? (uint32_t)tx_buffer_a : (uint32_t)tx_buffer_b;
    tx_transfers[0].dst_addr = (uint32_t)DMA_ADDR_I2S_TDR;
    tx_transfers[0].nbytes = sizeof(tx_buffer_a);
    bflb_dma_channel_lli_reload(dma0_ch1, tx_llipool, 1, tx_transfers, 1);
    bflb_dma_channel_start(dma0_ch1);

    if(buf[0] == 0)
    {
        printf("fuck\n");
    }
    else if ((buf[0] & 0xF0) == 0)
    {
        printf("1/2 fuck\n");
    }

    ping_pong = ping_pong == 0 ? 1 : 0;
}

static const uint16_t bitpatterns[4] = {0x88, 0x8e, 0xe8, 0xee};
static uint8_t out_buffer[NUM_LED * PIXEL_SIZE] = {0};

void rgb_set_color(struct pixel_t *pixels){
    uint16_t *buf = ping_pong == 0 ? tx_buffer_a : tx_buffer_b;
    memset(buf, 0, sizeof tx_buffer_a);
    for (uint16_t i = 0; i < NUM_LED; i++) {
        int loc = i * PIXEL_SIZE;

        buf[loc]     = (bitpatterns[pixels[i].green >> 6 & 0x03] << 8) | bitpatterns[pixels[i].green >> 4 & 0x03];
        buf[loc + 1] = (bitpatterns[pixels[i].green >> 2 & 0x03] << 8) | bitpatterns[pixels[i].green & 0x03];

        buf[loc + 2] = (bitpatterns[pixels[i].red   >> 6 & 0x03] << 8) | bitpatterns[pixels[i].red >> 4 & 0x03];
        buf[loc + 3] = (bitpatterns[pixels[i].red   >> 2 & 0x03] << 8) | bitpatterns[pixels[i].red & 0x03];

        buf[loc + 4] = (bitpatterns[pixels[i].blue  >> 6 & 0x03] << 8) | bitpatterns[pixels[i].blue >> 4 & 0x03];
        buf[loc + 5] = (bitpatterns[pixels[i].blue  >> 2 & 0x03] << 8) | bitpatterns[pixels[i].blue & 0x03];
    }
    i2s_send();
}

struct pixel_t pixel_buf[NUM_LED];

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
    .red = 2,
    .green = 1,
    .blue = 0
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
const struct pixel_t p3 = {
    .red = 1,
    .green = 0,
    .blue = 1
};
const struct pixel_t p4 = {
    .red = 1,
    .green = 1,
    .blue = 1
};
const struct pixel_t light_pink = {
    .red = 2,
    .green = 1,
    .blue = 1
};
const struct pixel_t p6 = {
    .red = 2,
    .green = 0,
    .blue = 1
};
const struct pixel_t p7 = {
    .red = 2,
    .green = 1,
    .blue = 0
};
const struct pixel_t p8 = {
    .red = 1,
    .green = 2,
    .blue = 1
};
const struct pixel_t light_green = {
    .red = 1,
    .green = 2,
    .blue = 0
};
const struct pixel_t p10 = {
    .red = 0,
    .green = 2,
    .blue = 1
};
const struct pixel_t p11 = {
    .red = 1,
    .green = 1,
    .blue = 2
};
const struct pixel_t p12 = {
    .red = 1,
    .green = 0,
    .blue = 2
};
const struct pixel_t p13 = {
    .red = 0,
    .green = 1,
    .blue = 2
};

const uint8_t number_select_lights[NUM_PRESETS] = { 0, 2, 5, 7, 18, 10, 20, 21, 19, 13, 23, 16, 24, 25 };
int ui_mode = UI_MODE_PLAY;

void set_ui_mode(int mode)
{
    ui_mode = mode;
}

int get_ui_mode(void)
{
    return ui_mode;
}

// lfo2pitch    = hslider("lfo-to-osc[mod:4]",     0, 0, 1, 0.001) <: attach(vbargraph("lfo-to-osc-led[led-lfo:18]", 0 , 1));   // button 4    // GPIO 16
// lfo2vca      = hslider("lfo-to-vca[mod:6]",     0, 0, 1, 0.001) <: attach(vbargraph("lfo-to-vca-led[led-lfo:20]", 0 , 1));   // button 6    // GPIO 12
// lfo2env      = hslider("lfo-to-env[mod:7]",     0, 0, 1, 1)     <: attach(vbargraph("lfo-to-env-led[led-lfo:21]", 0 , 1));   // button 7    // GPIO 10 
// lfo2vcf      = hslider("lfo-to-vcf[mod:8]",     0, 0, 1, 0.001) <: attach(vbargraph("lfo-to-vcf-led[led-lfo:19]", 0 , 1));   // button 8    // GPIO 13
// env2volume   = hslider("env-to-vca[mod:10]",    1, 0, 1, 0.001) <: attach(vbargraph("env-to-vca-led[led-env:23]", 0 , 1));   // button 10   // GPIO 3
// env2cutoff   = hslider("env-to-vcf[mod:12]",    0, 0, 1, 0.001) <: attach(vbargraph("env-to-vcf-led[led-env:24]", 0 , 1));   // button 12   // GPIO 1
// env2pitch    = hslider("env-to-osc[mod:13]",    0, 0, 1, 0.001) <: attach(vbargraph("env-to-osc-led[led-env:25]", 0 , 1));   // button 13   // GPIO 0


void render_lights(void)
{
    int current_slot = get_current_slot();
    struct Sel *sels = get_sels();
    struct Mod *mods = get_mods();
    struct Sigs *sigs = get_signals();
    struct Config *config = get_config();

    switch(ui_mode){
        case UI_MODE_PLAY:
            // pixel_buf[0] = p1;
            // pixel_buf[1] = p2;
            // pixel_buf[2] = p3;
            // pixel_buf[3] = p4;
            // pixel_buf[4] = p5;
            // pixel_buf[5] = p6;
            // pixel_buf[6] = p7;
            // pixel_buf[7] = p8;
            // pixel_buf[8] = p9;
            // pixel_buf[9] = p10;
            // pixel_buf[10] =p11;
            // pixel_buf[11] =p12;
            // pixel_buf[12] =p13;
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

            pixel_buf[18] = ( (*(sigs->lfo)  < 0.5) || (*mods[4].p == 0) ) ? pixel_off : light_green; // lfo.osc
            pixel_buf[19] = ( (*(sigs->lfo)  < 0.5) || (*mods[8].p == 0) ) ? pixel_off : light_green; // lfo.osc
            pixel_buf[20] = ( (*(sigs->lfo)  < 0.5) || (*mods[6].p == 0) ) ? pixel_off : light_green; // lfo.osc
            pixel_buf[21] = ( (*(sigs->lfo)  < 0.5) || (*mods[7].p == 0) ) ? pixel_off : light_green; // lfo.osc

            pixel_buf[22] = pixel_off; // vca

            pixel_buf[23] = ( (*(sigs->env)  < 0.5) || (*mods[10].p == 0) ) ? pixel_off : light_pink; // lfo.osc
            pixel_buf[24] = ( (*(sigs->env)  < 0.5) || (*mods[12].p == 0) ) ? pixel_off : light_pink; // lfo.osc
            pixel_buf[25] = ( (*(sigs->env)  < 0.5) || (*mods[13].p == 0) ) ? pixel_off : light_pink; // lfo.osc

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

    rgb_set_color(pixel_buf);
}