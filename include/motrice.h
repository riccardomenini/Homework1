#ifndef MOTRICE_H
#define MOTRICE_H


struct meninipianale {
    float x;
    float y;
    float w;
    float h;
};

struct meninicabina {
    float x;
    float y;
    float w;
    float h;
};

struct meniniruota {
    float x;
    float y;
    float r;
};

struct meninivetro {
    float x;
    float y;
    float w;
    float h;
};

struct MeniniDevice{
    float w;
    float h;
    meninipianale pianale;
    meninicabina cabina;
    meninivetro vetro;
    meniniruota ruotasx;
    meniniruota ruotadx;
};



#endif 
