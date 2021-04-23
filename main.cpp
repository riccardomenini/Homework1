#include <iostream>
#include "motrice.h"
#include <string>

using namespace std;

int main() {
    cout << "GENERATORE DI IMMAGINI SVG\n Menu:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
    char a;
    string stringa;
    MeniniDevice *device = menini_init();
    cin >> a;
    while (a != 'q'){
        switch (a)
        {
        case 'l':       //caricamento 
            break;
        case 'c':       //creazione
            menini_set (device);
            break;
        case 's':       //salvataggio
            stringa = menini_to_svg (device);
            menini_write_file(stringa);
            break;
        default:
            break;
        }
        cout << "GENERATORE DI IMMAGINI SVG\n Menu:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
        cin >> a;
    }
    return 0;
}
