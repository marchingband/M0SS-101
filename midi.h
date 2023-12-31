#ifndef MIDI_H
#define MIDI_H

#define NUM_SEL 27
#define NUM_CC 27

struct CC {
    float *p;
    float min;
    float max;
    float init;
    float step;
    float mul;
    char name[20];
};

struct Mod {
    float *p;
    float min;
    float max;
    float init;
    float step;
    float mul;
    char name[20];
};

struct Alt {
    float *p;
    float min;
    float max;
    float init;
    float step;
    float mul;
    char name[20];
};

struct Sel {
    float *p;
    float min;
    float max;
    float init;
    char name[20];
};

struct Sigs {
    float *pitch;
    float *gate;
    float *lfo;
    float *env;
    float *pitch_bend;
};

struct Sel *get_sels(void);
struct Mod *get_mods(void);
struct Alt *get_alts(void);
struct CC *get_ccs(void);
struct Sigs *get_signals(void);
uint8_t *get_cc_map(void);
int get_mode_learn_current_cc(void);

void handle_button_press(int num);

#endif