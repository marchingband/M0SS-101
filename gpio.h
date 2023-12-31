#ifndef MUX_H
#define MUX_H

#define NUM_BUTTONS 26

#define BUTTON_NUM_SAVE 14
#define BUTTON_NUM_LOAD 17
#define BUTTON_NUM_ALT 22
#define BUTTON_NUM_LEARN 24

void buttons_init();
void poll_gpio();

uint8_t *get_button_states(void);
void cancel_button(int num);
uint8_t *get_button_pushes(void);
void clear_button_pushes(void);
bool alt_held(void);
int button_label(int num);

#endif