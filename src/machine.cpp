#include "machine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <cmath>

using namespace std;

/**
 * trasforma la machine in un svg
 *
 * @param machine contiene i parametri dell'immagine
 * @param n contiene il numero dei carrelli
 * @param with_measures indica se si vogliono le misue nell'immagine o no (per menini to svg)
 * @return la stringa per l'svg
 */
string menini_to_svg_machine (MeniniMachine* machine, int n){
    if (machine != NULL){
        string a;
        a += "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n";
        a += "<svg xmlns='http://www.w3.org/2000/svg' style='background-color:white' width='";
        a += to_string((machine->arr[0]->abslength + 50*2*n + machine->motrice->h)*2);
        a += "' height='";
        a += to_string((machine->arr[0]->param.height)*2);
        a += "' viewBox='0 0 ";
        a += to_string((machine->arr[0]->abslength + 50*2*n + machine->motrice->h)*2);
        a += " ";
        a += to_string((machine->arr[0]->param.height)*2);
        a += "'>\n<g>\n";

        a += menini_to_svg(machine->motrice,0);

        a += "<!--" + to_string(n) + "-->\n";

        a += "<!-- <?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='" + to_string(machine->arr[0]->param.svgheight) + " '  height='" + to_string(machine->arr[0]->param.svgheight) + "' >\n<g>\n-->";

        for (int count = 0; count < n; count++){
            oselin_to_svg(machine->arr[count], false, false);
            a += machine->arr[count]->svg;
            if (count == 0){
                a += "\n<!-- FINEPRIMOCARRELLO -->";
            }
        }
        
        a += "</g>\n</svg>\n";
        return a;
    }else{
        return "ERRORE";
    }
    
}

/**
 * crea la motrice basandosi sulle misure scelte per i carrelli
 *
 * @param machine contiene i parametri dell'immagine
 * @return un puntatore a motrice
 */
MeniniDevice* menini_set_motrice_in_machine(MeniniMachine* machine){
    float r = 0;
    int control;
    if (machine != NULL){
        machine->motrice->pianale.w = machine->arr[0]->downfloor.width; //Non può fallire in quanto non ho definito nessun altro parametro 
        machine->motrice->pianale.h = (machine->arr[0]->param.height + machine->arr[0]->downfloor.height) / 5; //Non può fallire in quanto non ho definito nessun altro parametro
        machine->motrice->ruotasx.x = machine->motrice->pianale.w / 5;
        machine->motrice->ruotadx.x = 4 * machine->motrice->pianale.w / 5; 
        machine->motrice->ruotasx.x += machine->motrice->margineds;
        machine->motrice->ruotadx.x += machine->motrice->margineds;
        r = machine->arr[0]->downfloor.height / 40 * 2 * machine->arr[0]->param.radius;
        control = menini_set_raggi(machine->motrice,r);
        menini_reset(machine->motrice);
        return machine->motrice;
    }else{
        return NULL;
    }
    
}

/**
 * crea la machine
 *
 * @param machine contiene i parametri dell'immagine
 * @return un puntatore a motrice
 */
MeniniMachine* menini_machine_create(MeniniMachine* machine){
    machine->arr = new OselinDevice* [machine->n];   // notare asterisco dopo MyDevice
    machine->arr[0] = new OselinDevice;
    create(machine->arr[0]);
    machine->arr[0]->offset = machine->motrice->margineds + machine->arr[0]->downfloor.width + DOWNOFFSET;
    for (int count = 1; count < machine->n; count++){
        machine->arr[count] = new OselinDevice;
        machine->arr[count] = oselin_init_acopyof(machine->arr[0]);
        machine->arr[count]->offset = (count) * machine->arr[0]->abslength + machine->motrice->margineds + machine->arr[0]->downfloor.width + DOWNOFFSET;

    }
    menini_set_motrice_in_machine (machine);
    machine->motrice->ruotasx.y = machine->arr[0]->frontwheel.y;//aggiusto ruote
    machine->motrice->ruotadx.y = machine->arr[0]->frontwheel.y;//aggiusto ruote     
    return machine;            
}

string questions[] = {"SVG width: ", "SVG height: ","Car lenght: ","Car height: ", "Wheel radius [16,17,18]: ","Cars-per-trailer [1,2]: ","Number of floors [1,2]: "};



/**
 * Create OselinDevice from scratch. It can work with graphical menu 
 * @param dev a Oselin device
 * @return a string
 **/
string create(OselinDevice *dev){

    float parameters[5];
    Parameters p;

        try{
            for (int i=0; i<7; i++){
                cout << questions[i];
                if (i==0) cin >> p.svgwidth;
                else if (i==1) cin >> p.svgheight;
                else cin >> parameters[i-2];
            }}
        catch(const exception& e){
            return errors(8);

        }

        p.length    = parameters[0];
        p.height    = parameters[1];
        p.radius    = parameters[2];
        p.ncars     = (int)parameters[3];
        p.nfloors   = (int)parameters[4];
        //p.margin;
    
    (*dev) = (*oselin_init(p));
    if (dev!=NULL){
        oselin_trigonometry(dev,false);
        return "Created successfully";
    }
    return "Something went wrong";
}

MeniniMachine* menini_parse_machine (string a){
    if (a == ""){
        return NULL; 
    }
    string inizio;
    string motrice;
    string carrello;
    string fine;
    size_t intestazione = a.find("<g>", 8) + 2;
    inizio = a.substr(0, intestazione);
    fine = "</g>\n</svg>";

    motrice = inizio;
    motrice += a.substr(intestazione, a.find("<!--", 0)-intestazione); 
    motrice += fine;

    //carrello = inizio;
    intestazione = a.find("<?xml", 10);
    size_t fineintestazione = a.find("-->", intestazione);
    carrello += a.substr(intestazione, fineintestazione-intestazione);
    carrello += a.substr(fineintestazione + 4, (a.find("<!-- FINEPRIMOCARRELLO -->", 0)) - (fineintestazione + 4));
    carrello += fine;

    size_t numerocarrelli = a.find("<!--") + 4;
    size_t numerocarrellifine = a.find("-->",numerocarrelli);
    int n = stof(a.substr(numerocarrelli, numerocarrellifine - numerocarrelli));

    MeniniMachine* machine = new MeniniMachine;
    machine->motrice = new MeniniDevice;
    machine->arr = new OselinDevice* [n];
    machine->arr[0] = new OselinDevice;
    machine->motrice = menini_parse(motrice);
    oselin_parsing(machine->arr[0], carrello);
    machine->n = n;
    for (int count = 1; count < machine->n; count++){
        machine->arr[count] = new OselinDevice;
        machine->arr[count] = oselin_init_acopyof(machine->arr[0]);
        machine->arr[count]->offset = (count) * machine->arr[0]->abslength + machine->motrice->margineds + machine->arr[0]->downfloor.width + DOWNOFFSET;

    }
    return machine;


}

bool menini_are_equal(MeniniMachine* machine1, MeniniMachine* machine2){
    if (machine1 == NULL || machine2 == NULL){
        return true;
    }
    /*int m = 1;
    if (machine1->motrice->pianale.w == machine2->motrice->pianale.w) m = 0;
    if (machine1->motrice->pianale.h == machine2->motrice->pianale.h) m = 0;
    if (machine1->motrice->ruotasx.x == machine2->motrice->ruotasx.x) m = 0;
    if (machine1->motrice->ruotadx.x == machine2->motrice->ruotadx.x) m = 0;
    if (machine1->motrice->ruotasx.r == machine2->motrice->ruotasx.r) m = 0;

    int c = 1;*/

    string str1 = menini_to_svg_machine(machine1, machine1->n);
    string str2 = menini_to_svg_machine(machine2, machine2->n);

    if (str1.compare(str2) == 0){
        return true;
    }
    return false;

}

void menini_delete (MeniniMachine * machine, MeniniDevice * device, bool m){
    
    delete [] device;
    delete [] machine->motrice;
    if (m){
        /*for (int count = 1; count < machine->n; count++){
            delete [] machine->arr[count];
        }*/
        delete [] machine->arr;
    }
    delete [] machine;
}