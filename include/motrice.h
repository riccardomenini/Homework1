#ifndef MOTRICE_H
#define MOTRICE_H
#include <string>

using namespace std;


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

MeniniDevice* menini_set(MeniniDevice*);

int menini_check_pianale_w(MeniniDevice*);

int menini_set_pianale_w(MeniniDevice*, float);

int menini_check_pianale_h(MeniniDevice*, int);

int menini_set_pianale_h(MeniniDevice*, float);

int menini_check_raggi(MeniniDevice*, int new_r);

int menini_set_raggi(MeniniDevice*, float);

int menini_check_ruotasx(MeniniDevice*, int);

int menini_set_ruotasx(MeniniDevice*, float);

int menini_check_ruotadx(MeniniDevice*, int);

int menini_set_ruotadx(MeniniDevice*, float);

string menini_to_svg (MeniniDevice*);

void menini_write_file(string);


#endif 
