#ifndef MUX_H
#define MUX_H

#define NUM_BUTTONS 27

#define BUTTON_NUM_SAVE 15
#define BUTTON_NUM_LOAD 18
#define BUTTON_NUM_ALT 23
#define BUTTON_NUM_LEARN 25

void buttons_init();
void poll_gpio();

uint8_t *get_button_states(void);
void cancel_button(int num);
uint8_t *get_button_pushes(void);
void clear_button_pushes(void);
bool alt_held(void);
int button_label(int num);

#endif