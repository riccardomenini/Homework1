#ifndef MOTRICE_H
#define MOTRICE_H


struct Menini_pianale {
    float x;
    float y;
    float w;
    float h;
};

struct Menini_cabina {
    float x;
    float y;
    float w;
    float h;
};

struct Menini_ruota {
    float x;
    float y;
    float r;
};

struct Menini_vetro {
    float x;
    float y;
    float w;
    float h;
};

struct Menini_Device{
    Menini_pianale pianale;
    Menini_cabina cabina;
    Menini_vetro vetro;
    Menini_ruota ruotasx;
    Menini_ruota ruotadx;
};

int Menini_init();



#endif 
