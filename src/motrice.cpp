#include "motrice.h"
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <cmath>

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
    device->cabina.w = device->pianale.w / 3;
    device->cabina.h = device->pianale.h * 4;
    

    device->vetro.x = device->margineds;
    device->vetro.y = device->cabina.w /5;
    device->vetro.w = device->cabina.w /2;
    device->vetro.h = device->cabina.h /2;

    device->pianale.x = device->margineds;
    device->pianale.y = device->marginess + device->cabina.h;
    
    device->ruotasx.y = device->pianale.y + device->pianale.h; 
    device->ruotadx.y = device->pianale.y + device->pianale.h; 

    device->w = 2 * device->marginess + device->pianale.w ;
    device->h = 2 * device->marginess + device->cabina.w + device->pianale.w + device->ruotadx.r;

    return device;
    
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_pianale_w(MeniniDevice* device, float new_w){
    if (device->ruotasx.x > new_w / 2 || device->ruotadx.x < new_w / 2){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_w è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_pianale_w(MeniniDevice* device, float new_w){
    if (menini_check_pianale_w(device, new_w)==1){
        return 1;
    }

    device->pianale.w = new_w;
    menini_reset(device);
    return 0;
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_pianale_h(MeniniDevice* device, float new_h){
    if (device->ruotadx.r > new_h){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_h è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_pianale_h(MeniniDevice* device, float new_h){
    if (menini_check_pianale_h(device, new_h)==1){
        return 1;
    }

    device->pianale.h = new_h;
    menini_reset(device);
    return 0;
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_raggi(MeniniDevice* device, float new_r){
    if (new_r > device->pianale.h){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_r è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_raggi(MeniniDevice* device, float new_r){
    if (menini_check_raggi(device, new_r)==1){
        return 1;
    }

    device->ruotadx.r = new_r;
    menini_reset(device);
    return 0;
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_ruotasx(MeniniDevice* device, float new_x){
    if (new_x > device->pianale.w / 2){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_x è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_ruotasx(MeniniDevice* device, float new_x){
    if (menini_check_ruotasx(device, new_x)==1){
        return 1;
    }

    device->ruotasx.x = new_x;
    menini_reset(device);
    return 0;
}

/**
 * Controlla i vincoli per il disegno.
 *
 * @param device struttura contenente i parametri dell'svg
 * @return 0 se i parametri rispettano i vicoli, 1 altrimenti
 */

int menini_check_ruotadx(MeniniDevice* device, float new_x){
    if (new_x < device->pianale.w / 2){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Setta le dimensioni dell'immagine
 *
 * @param device contiene i parametri dell'immagine
 * @param new_x è il nuovo parametro che si vuole inserire
 * @return 0 se il set è andato a buon fine, 1 altrimenti
 */

int menini_set_ruotadx(MeniniDevice* device, float new_x){
    if (menini_check_ruotadx(device, new_x)==1){
        return 1;
    }

    device->ruotadx.x = new_x;
    menini_reset(device);
    return 0;
}


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

/**
 * Crea e ritorna la stringa corrispondente al device creato
 *
 * @param device contiene i parametri dell'immagine
 * @return stringa da stampare
 */
string menini_to_svg (MeniniDevice* device){
    string a;
    a += "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n";
    a += "<svg xmlns='http://www.w3.org/2000/svg' width='";
    a += to_string(device->w);
    a += "mm' height='";
    a += to_string(device->h);
    a += "mm' viewBox='0 0 ";
    a += to_string(device->w);
    a += " ";
    a += to_string(device->h);
    a += "'>\n<g>\n";

    a += "<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='";
    a += to_string(device->cabina.w);
    a += "' height='";
    a += to_string(device->cabina.h);
    a += "' x='";
    a += to_string(device->cabina.x);
    a += "' y='";
    a += to_string(device->cabina.y);
    a += "' />\n";
    
    a += "<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='";
    a += to_string(device->vetro.w);
    a += "' height='";
    a += to_string(device->vetro.h);
    a += "' x='";
    a += to_string(device->vetro.x);
    a += "' y='";
    a += to_string(device->vetro.y);
    a += "' />\n";

    a += "<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='";
    a += to_string(device->pianale.w);
    a += "' height='";
    a += to_string(device->pianale.h);
    a += "' x='";
    a += to_string(device->pianale.x);
    a += "' y='";
    a += to_string(device->pianale.y);
    a += "' />\n";

    a += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='";
    a += to_string(device->ruotasx.x);
    a += "' cy='";
    a += to_string(device->ruotasx.y);
    a += "' rx='";
    a += to_string(device->ruotasx.r);
    a += "' ry='";
    a += to_string(device->ruotasx.r);
    a += "' />\n";

    a += "<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='";
    a += to_string(device->ruotadx.x);
    a += "' cy='";
    a += to_string(device->ruotadx.y);
    a += "' rx='";
    a += to_string(device->ruotadx.r);
    a += "' ry='";
    a += to_string(device->ruotadx.r);
    a += "' />\n";
    
    a += "</g>\n</svg>\n";
    return a;
}

/**
 * Scrive su file la stringa ricevuta in ingresso
 *
 * @param stringa contiene la tringa da scrivere
 */
void menini_write_file(string stringa, string nomefile){
    ofstream MyFile(nomefile);
    MyFile << stringa;
    MyFile.close();
};

/**
  * Legge da file
  *
  * @param filename
  * @return stringa stringa letta
  */
 string menini_read_file(string filename){
     ifstream t(filename);
     stringstream buffer;
     buffer << t.rdbuf();
     string s = buffer.str();
     return s;
 };

/**
  * Cerca un parametro nell'svg
  *
  * @param stringa contiene la stringa in cui cercare
  * @param cercata contiene la stringa da cercare
  * @param partenza la posizione da cui partire nella ricerca
  * @param fine contiene la stringa che segna la fine del numero
  * @return il device
  */
float menini_cerca(string stringa, string cercata, int & partenza, string fine){
    string numero;
    //cout << "partenza in cerca= " << partenza;
    size_t found = stringa.find(cercata, partenza);
    if (found != string::npos)
        found += cercata.length();
        size_t found1 = stringa.find(fine, found+1);
        for (found; found < found1; found++){
        //cout << "ciclo" << stringa[found] << "\n";
        numero += stringa[found];
        }
    //cout << "numero trovato: " << numero << "\n";
    partenza = found;
    return stof(numero);
}

 /**
  * Crea un device da una stringa svg
  *
  * @param stringa contiene la stringa da scrivere
  * @return il device
  */
 MeniniDevice* menini_parse(string stringa){
    MeniniDevice *device = menini_init();

    int partenza = 0;

    //width e height svg
    device->w = menini_cerca(stringa, "width='", partenza, "m");
    device->h = menini_cerca(stringa, "height='", partenza, "m");
    //cout << device->w << " " << device->h;

    //cabina
    device->cabina.w = menini_cerca(stringa, "width='", partenza, "'");
    device->cabina.h = menini_cerca(stringa, "height='", partenza, "'");
    device->cabina.x = menini_cerca(stringa, "x='", partenza, "'");
    device->cabina.y = menini_cerca(stringa, "y='", partenza, "'");
    
    //vetro
    device->vetro.w = menini_cerca(stringa, "width='", partenza, "'");
    device->vetro.h = menini_cerca(stringa, "height='", partenza, "'");
    device->vetro.x = menini_cerca(stringa, "x='", partenza, "'");
    device->vetro.y = menini_cerca(stringa, "y='", partenza, "'");
    
    //pianale
    device->pianale.w = menini_cerca(stringa, "width='", partenza, "'");
    device->pianale.h = menini_cerca(stringa, "height='", partenza, "'");
    device->pianale.x = menini_cerca(stringa, "x='", partenza, "'");
    device->pianale.y = menini_cerca(stringa, "y='", partenza, "'");
    
    //ruotasx
    device->ruotasx.x = menini_cerca(stringa, "cx='", partenza, "'");
    device->ruotasx.y = menini_cerca(stringa, "cy='", partenza, "'");
    device->ruotasx.r = menini_cerca(stringa, "rx='", partenza, "'");
    
    //ruotadx

    device->ruotadx.x = menini_cerca(stringa, "cx='", partenza, "'");
    device->ruotadx.y = menini_cerca(stringa, "cy='", partenza, "'");
    device->ruotadx.r = menini_cerca(stringa, "rx='", partenza, "'");
    //cout << device->ruotadx.x << " " << device->ruotadx.y << " " << device->ruotadx.r << " \n";
    return device;
 }
