#ifndef MIDI_H
#define MIDI_H

#define NUM_CC 54 // must be the highest CC value + 1, CC's are 1 indexed.
#define CC_MAP_VELOCITY_IDX     128
#define CC_MAP_AFTERTOUCH_IDX   129

#define LEARN_MODE_READY 0
#define LEARN_MODE_SELECTED 1
#define LEARN_MODE_LEARNED 2

#define ALT_SWITCH_STATE_NONE 0
#define ALT_SWITCH_STATE_ON 1
#define ALT_SWITCH_STATE_OFF 2

#define MIDI_CHANNEL_OMNI 17

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

#define EnvIIMod Mod
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

#define EnvIISel Sel
struct AltSel {
    float *p;
    float min;
    float max;
    float init;
    char name[20];
};

#define EnvIIAltSel AltSel
struct Asb {
    float *p;
    float min;
    float max;
    float init;
    float step;
    float mul;
    char name[20];
};

struct Sigs {
    float *pitch;
    float *gate;
    float *lfo;
    float *env;
    float *envII;
    float *pitch_bend;
    float *vca;
    float *fine_tune;
    float *transpose;
};

struct Sel *get_sels(void);
struct AltSel *get_alt_sels(void);
struct Asb *get_asbs(void);
struct Mod *get_mods(void);
struct Alt *get_alts(void);
struct EnvIIMod *get_envIImods(void);
struct EnvIIAltSel *get_EnvIIalt_sels(void);
struct EnvIISel *get_envIIsels(void);
struct CC *get_ccs(void);
struct Sigs *get_signals(void);
int get_mode_learn_current_cc(void);
void reset_params(void);
bool check_env_II(int num);

void handle_button_press(int num);
void uart_receive_init(void);

#endif