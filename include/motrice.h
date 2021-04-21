#ifndef MOTRICE_H
#define MOTRICE_H


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



#endif 
