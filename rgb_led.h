#ifndef RGB_LED_H
#define REG_LED_H

struct pixel_t {
  uint8_t green;
  uint8_t red;
  uint8_t blue;
};

void rgb_led_init();
void rgb_set_color(struct pixel_t *pixels);
void render_lights(void);
void rgb_task(void *pvParameters);

#endif