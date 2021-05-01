#include <iostream>
#include "motrice.h"
#include "machine.h"
#include "car_trailer.h"
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

    cout << "Quanto deve essere lungo il pianale? ";
    cin >> device->pianale.w; //Non può fallire in quanto non ho definito nessun altro parametro
    
    cout << "Quanto deve essere alto il pianale? ";
    cin >> device->pianale.h; //Non può fallire in quanto non ho definito nessun altro parametro
    
    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota anteriore? ";
    cin >> r;
    control = menini_set_ruotasx(device,r);
    while(control==1){
        cout << "ERRORE: La ruota di sinistra deve essere nella prima metà del pianale\n";
        cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota anteriore? ";
        cin >> r;
        control = menini_set_ruotasx(device,r);
    }

    cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota posteriore? ";
    cin >> r;
    control = menini_set_ruotadx(device,r);
    while(control==1){
        cout << "ERRORE: La ruota di destra deve essere nella seconda metà del pianale\n";
        cout << "A che distanza dalla linea fronale della cabina deve essere posizionata la ruota posteriore? ";
        cin >> r;
        control = menini_set_ruotadx(device,r);
    }

    device->ruotasx.x += device->margineds;
    device->ruotadx.x += device->margineds;

    cout << "Qual è il raggio delle ruote? ";
    cin >> r;
    control = menini_set_raggi(device,r);
    while(control==1){
        cout << "ERRORE: Le ruote devono avere raggio inferiore all'altezza del pianale\n";
        cout << "Qual è il raggio delle ruote? ";
        cin >> r;
        control = menini_set_raggi(device,r);
    }

    menini_reset(device);
    return device;
}

int main() {
    cout << "GENERATORE DI SVG\n Menu principale:\n [d] - operazioni su device\n [m] - operazioni su machine\n [q] - quit \n\n Cosa si desidera fare? \n";
    char r;
    cin >> r;
    cout << "\n\n";
    char a;
    string stringa;
    string testoletto;
    MeniniDevice *device = menini_init();
    MeniniMachine *machine = new MeniniMachine;
    machine->motrice = menini_init();
    while (r != 'q'){
        switch (r)
        {
        case 'd':
            cout << "Hai scelto: GENERATORE DI DEVICE SVG\n Menu interno:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
            cin >> a;
            cout << "\n\n";
            while (a != 'q'){
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
                    stringa = "";
                    cout << "Inserire nome file su cui salvare l'svg ";
                    cin >> testoletto;
                    int risposta;
                    cout << "Si desidera visializzare le misure? (Premere 1 per si, 0 per no) ";
                    cin >> risposta;
                    while(risposta != 1 && risposta != 0){
                        cout << "ERRORE: Inserire 1 o 0\n";
                        cout << "Si desidera visualizzare le misure? (Premere 1 per si, 0 per no) ";
                        cin >> risposta;
                    }
                    stringa += "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n";
                    stringa += "<svg xmlns='http://www.w3.org/2000/svg' style='background-color:white' width='";
                    stringa += to_string(device->w);
                    stringa += "' height='";
                    stringa += to_string(device->h);
                    stringa += "' viewBox='0 0 ";
                    stringa += to_string(device->w);
                    stringa += " ";
                    stringa += to_string(device->h);
                    stringa += "'>\n<g>\n";
                    stringa += menini_to_svg(device,risposta);
                    stringa += "</g>\n</svg>\n";
                    menini_write_file(stringa, testoletto);
                    break;
                default:
                    break;
                }
                cout << "Hai scelto: GENERATORE DI DEVICE SVG\n Menu interno:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
                cin >> a;
                cout << "\n\n";
            }
            break;
        case 'm':
            cout << "Hai scelto: GENERATORE DI MACHINE SVG\n Menu interno:\n [l] - caricare machine svg da file\n [c] - creare un nuovo machine svg\n [s] - salvare machine svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
            cin >> a;
            cout << "\n\n";
            while (a != 'q'){
                switch (a)
                {
                case 'l': //caricamento
                    /*cout << "Inserire file da cui si vuole leggere ";
                    cin >> stringa;
                    testoletto = menini_read_file(stringa);
                    device = menini_parse(testoletto);*/
                    break;
                case 'c'://creazione
                    cout << "Carrelli: \n";
                    cout << "Quanti carrelli si desidera inserire? \n";
                    cin >> machine->n;
                    menini_machine_create(machine);
                    break;
                case 's'://salvataggio
                    cout << "Inserire nome file su cui salvare l'svg ";
                    cin >> testoletto;
                    int risposta;
                    stringa = "";
                    stringa = menini_to_svg_machine (machine,machine->n,0);
                    menini_write_file(stringa, testoletto);
                    break;
                default:
                    break;
                }
                cout << "Hai scelto: GENERATORE DI MACHINE SVG\n Menu interno:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
                cin >> a;
                cout << "\n\n";
            }
            break;
        default:
            break;
        }
    cout << "GENERATORE DI SVG\n Menu principale:\n [d] - operazioni su device\n [m] - operazioni su machine\n [q] - quit \n\n Cosa si desidera fare? \n";
    cin >> r;
    cout << "\n\n";
    }
    delete [] device;
    delete [] machine->arr;
    delete [] machine;
    return 0;
}
