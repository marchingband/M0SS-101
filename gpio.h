#ifndef MUX_H
#define MUX_H

#define NUM_BUTTONS 27

#define BUTTON_NUM_SAVE 14
#define BUTTON_NUM_LOAD 17
#define BUTTON_NUM_ALT 22
#define BUTTON_NUM_LEARN 24

#define ONE_SECOND 1000000

struct Param {
    int button;
    bool alt;
};

void buttons_init();
void poll_gpio();

uint8_t *get_button_states(void);
uint8_t *get_button_pushes(void);
void clear_button_pushes(void);
bool alt_held(void);
int button_label(int num);
struct Param get_param_selected(void);

#endif