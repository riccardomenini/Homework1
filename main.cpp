#include <iostream>
#include "motrice.h"
#include <string>

using namespace std;

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @return un puntatore a device
 */

MeniniDevice* menini_set(MeniniDevice* device){
    cout << "Creazione di un nuovo Device: \n";
    float r = 0;
    int control;

    cout << "Quanto deve essere lungo il pianale?";
    cin >> device->pianale.w; //Non può fallire in quanto non ho definito nessun altro parametro
    
    cout << "Quanto deve essere alto il pianale?";
    cin >> device->pianale.h; //Non può fallire in quanto non ho definito nessun altro parametro
    
    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota anteriore?";
    cin >> r;
    control = menini_set_ruotasx(device,r);
    while(control==1){
        cout << "ERRORE: La ruota di sinistra deve essere nel primo terzo del pianale\n";
        cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota anteriore?";
        cin >> r;
        control = menini_set_ruotasx(device,r);
    }

    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota posteriore?";
    cin >> r;
    control = menini_set_ruotadx(device,r);
    while(control==1){
        cout << "ERRORE: La ruota di destra deve essere nell'ultimo terzo del pianale\n";
        cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota posteriore?";
        cin >> r;
        control = menini_set_ruotadx(device,r);
    }

    cout << "Qual è il raggio delle ruote?";
    cin >> r;
    control = menini_set_raggi(device,r);
    while(control==1){
        cout << "ERRORE: Le ruote devono avere raggio inferiore all'altezza del pianale\n";
        cout << "Qual è il raggio delle ruote?";
        cin >> r;
        control = menini_set_raggi(device,r);
    }

    menini_reset(device);
    return device;
}

int main() {
    //cout << "GENERATORE DI IMMAGINI SVG\n Menu:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
    //char a;
    string stringa;
    string testoletto;
    MeniniDevice *device = menini_init();
    //cin >> a;

    testoletto = menini_read_file("../motrice.svg");
    device = menini_parse(testoletto);
    stringa = menini_to_svg (device,true);
    menini_write_file(stringa, "../prova.svg");

    /*while (a != 'q'){
        switch (a)
        {
        case 'l': //caricamento
             cout << "Inserire file da cui si vuole leggere ";
             cin >> stringa;
             testoletto = menini_read_file(stringa);
             device = menini_parse(testoletto);
             break;
        case 'c'://creazione
            menini_set (device);
            break;
        case 's'://salvataggio
            cout << "Inserire nome file su cui salvare l'svg ";
            cin >> testoletto;
            stringa = menini_to_svg (device,true);
            menini_write_file(stringa, testoletto);
            break;
        default:
            break;
        }
        cout << "GENERATORE DI IMMAGINI SVG\n Menu:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
        cin >> a;
    }*/
    return 0;
}
