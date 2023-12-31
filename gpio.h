#ifndef MUX_H
#define MUX_H

#define NUM_BUTTONS 27

void buttons_init();
void poll_buttons();

uint8_t *get_button_states(void);
void cancel_button(int num);
uint8_t *get_button_pushes(void);
void clear_button_pushes(void);
bool alt_held(void);

#endif