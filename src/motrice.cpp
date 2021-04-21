
#include "motrice.h"
#include "iostream"

using namespace std;

/*
 *  
 *
 */

int menini_init(MeniniDevice* device){
    int ret;
    ret = 0;
    if (device->cabina.w > device->pianale.w){
        cout << "ERRORE: La cabina deve essere lunga al massimo la metà del pianale";
        ret = 1;
    }
    if (device->ruotadx.r > device->pianale.h){
        cout << "ERRORE: Le ruote devono avere raggio inferiore all'altezza del pianale";
        ret = 1;
    }
    if (device->ruotasx.x > device->pianale.w / 3){
        cout << "ERRORE: La ruota di sinistra deve essare nel primo terzo del pianale";
        ret = 1;
    }
    if (device->ruotadx.x > 2 * device->pianale.w / 3){
        cout << "ERRORE: La ruota di sinistra deve essare nell'ultimo terzo del pianale";
        ret = 1;
    }
    return ret;
}

MeniniDevice* menini_set(MeniniDevice* device){
    cout << "Creazione di un nuovo Device: \n";
    cout << "Quanto deve essere lungo il pianale?";
    cin >> device->pianale.w;
    cout << "Quanto deve essere alto il pianale?";
    cin >> device->pianale.h;
    cout << "Quanto deve essere larga la cabina?";
    cin >> device->cabina.w;
    cout << "Quanto deve essere alta la cabina?";
    cin >> device->cabina.h;
    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota anteriore?";
    cin >> device->ruotasx.x;
    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota posteriore?";
    cin >> device->ruotadx.x;
    cout << "Qual è il raggio delle ruote?";
    cin >> device->ruotadx.r;
    device->ruotasx.r = device->ruotadx.r;

    //Aggiunta margini
    float margineds = device->w / 10;
    float marginess = device->w / 10;

    device->cabina.x = margineds;
    device->cabina.y = marginess;

    device->vetro.x = margineds;
    device->vetro.y = marginess;
    device->vetro.w = device->cabina.w /2;
    device->vetro.h = device->cabina.h /3;

    device->pianale.x = margineds;
    device->pianale.y = marginess + device->cabina.h;
    
    device->ruotasx.y = device->pianale.y + device->pianale.h; 
    device->ruotadx.y = device->pianale.y + device->pianale.h; 

    device->w = 2 * marginess + device->cabina.w + device->pianale.w + device->ruotadx.r;
}