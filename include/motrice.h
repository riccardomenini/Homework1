#ifndef MOTRICE_H
#define MOTRICE_H
#include <string>


struct MeniniPianale {
    float x;
    float y;
    float w;
    float h;
};

struct MeniniCabina {
    float x;
    float y;
    float w;
    float h;
};

struct MeniniRuota {
    float x;
    float y;
    float r;
};

struct MeniniVetro {
    float x;
    float y;
    float w;
    float h;
};

struct MeniniDevice{
    float w;
    float h;
    MeniniPianale pianale;
    MeniniCabina cabina;
    MeniniVetro vetro;
    MeniniRuota ruotasx;
    MeniniRuota ruotadx;
};

MeniniDevice* menini_set(MeniniDevice*);

//std::string menini_to_svg (MeniniDevice*);

int menini_init(MeniniDevice*);

#endif 
