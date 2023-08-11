#ifndef MIDI_H
#define MIDI_H

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

struct Sel *get_sels(void);

#endif