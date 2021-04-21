
#include "motrice.h"
#include "iostream"

using namespace std;

/**
 *Inizializza.
 *
 * @return puntatore a device
 */

MeniniDevice* menini_init(){
    MeniniDevice *device = new MeniniDevice;
    device->w = 0;
    device->h = 0;
    return device;
}

/**
 * resetta le dimensioni dell'immagine.Da usare in caso di modifica di un parametro: fa in modo che le misure tornino compatibili
 *
 * @param device contiene i parametri dell'immagine
 * @return un puntatore a device
 */

MeniniDevice* menini_reset(MeniniDevice* device){
    device->ruotasx.r = device->ruotadx.r;

    device->cabina.x = device->margineds;
    device->cabina.y = device->marginess;

    device->vetro.x = device->margineds;
    device->vetro.y = device->marginess;
    device->vetro.w = device->cabina.w /2;
    device->vetro.h = device->cabina.h /3;

    device->pianale.x = device->margineds;
    device->pianale.y = device->marginess + device->cabina.h;
    
    device->ruotasx.y = device->pianale.y + device->pianale.h; 
    device->ruotadx.y = device->pianale.y + device->pianale.h; 

    return device;
    
}


/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */
int menini_check(MeniniDevice* device){
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

    if (ret == 0){
        return 0;
        menini_reset(device);
    }else{
        return 1;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 */

void menini_set_pianale_w(MeniniDevice* device){
    cout << "Quanto deve essere lungo il pianale?";
    cin >> device->pianale.w;

    menini_check(device);
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 */

void menini_set_pianale_h(MeniniDevice* device){
    cout << "Quanto deve essere alto il pianale?";
    cin >> device->pianale.h;
    
    menini_check(device);
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 */

void menini_set_cabina_w(MeniniDevice* device){
    cout << "Quanto deve essere larga la cabina?";
    cin >> device->cabina.w;
    
    menini_check(device);
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 */

void menini_set_cabina_h(MeniniDevice* device){
    cout << "Quanto deve essere alta la cabina?";
    cin >> device->cabina.h;
    
    menini_check(device);
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 */

void menini_set_ruotasx(MeniniDevice* device){
    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota anteriore?";
    cin >> device->ruotasx.x;
    
    menini_check(device);
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 */

void menini_set_ruotadx(MeniniDevice* device){
    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota posteriore?";
    cin >> device->ruotadx.x;
    
    menini_check(device);
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 */

void menini_set_raggi(MeniniDevice* device){
    cout << "Qual è il raggio delle ruote?";
    cin >> device->ruotadx.r;
    
    menini_check(device);
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

    device->cabina.x = device->margineds;
    device->cabina.y = device->marginess;

    device->vetro.x = device->margineds;
    device->vetro.y = device->marginess;
    device->vetro.w = device->cabina.w /2;
    device->vetro.h = device->cabina.h /3;

    device->pianale.x = device->margineds;
    device->pianale.y = device->marginess + device->cabina.h;
    
    device->ruotasx.y = device->pianale.y + device->pianale.h; 
    device->ruotadx.y = device->pianale.y + device->pianale.h; 
    
    return device;
}
//std::string menini_to_svg (MeniniDevice* device){}