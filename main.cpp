#include <iostream>
#include "motrice.h"

using namespace std;

int main() {
    MeniniDevice *device = new MeniniDevice;
    cout << "GENERATORE DI IMMAGINI SVG\n Menu:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
    char a;
    cin >> a;
    while (a != 'q'){
        switch (a)
        {
        case 'l':       //caricamento   
            break;
        case 'c':       //creazione
            break;
        case 's':       //salvataggio
            break;
        default:
            break;
        }
        cout << "GENERATORE DI IMMAGINI SVG\n Menu:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
        cin >> a;
    }
    return 0;
}
