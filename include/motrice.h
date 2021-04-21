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
    MeniniPianale pianale;
    MeniniCabina cabina;
    MeniniVetro vetro;
    MeniniRuota ruotasx;
    MeniniRuota ruotadx;
    float w = 2 * marginess + pianale.w ;
    float h = 2 * marginess + cabina.w + pianale.w + ruotadx.r;
    float margineds = w / 10;
    float marginess = h / 10;
};


MeniniDevice* menini_init();

MeniniDevice* menini_reset(MeniniDevice*);

int menini_check(MeniniDevice*);

void menini_set_pianale_w(MeniniDevice*);

void menini_set_pianale_h(MeniniDevice*);

void menini_set_cabina_w(MeniniDevice*);

void menini_set_cabina_h(MeniniDevice*);

void menini_set_ruotasx(MeniniDevice*);

void menini_set_ruotadx(MeniniDevice*);

void menini_set_raggis(MeniniDevice*);

MeniniDevice* menini_set(MeniniDevice*);

//std::string menini_to_svg (MeniniDevice*);

#endif 
