
#include "motrice.h"
#include "iostream"

using namespace std;

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */
int menini_init(MeniniDevice* device){
    int ret;
    ret = 0;
    if (device->cabina.w > device->pianale.w){
        cout << "ERRORE: La cabina deve essere lunga al massimo la metà del pianale\n";
        ret = 1;
    }
    if (device->ruotadx.r > device->pianale.h){
        cout << "ERRORE: Le ruote devono avere raggio inferiore all'altezza del pianale\n";
        ret = 1;
    }
    if (device->ruotasx.x > device->pianale.w / 3){
        cout << "ERRORE: La ruota di sinistra deve essare nel primo terzo del pianale\n";
        ret = 1;
    }
    if (device->ruotadx.x < 2 * device->pianale.w / 3){
        cout << "ERRORE: La ruota di sinistra deve essare nell'ultimo terzo del pianale\n";
        ret = 1;
    }
    return ret;
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @return un puntatore a device
 */

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

    if (menini_init(device) == 0){
        return device;
    }else{
        delete(device);
        return NULL;
    }
}

//std::string menini_to_svg (MeniniDevice* device){}