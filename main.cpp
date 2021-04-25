#include <iostream>
#include "motrice.h"
#include <string>

using namespace std;

int main() {
    cout << "GENERATORE DI IMMAGINI SVG\n Menu:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
    char a;
    string stringa;
    string testoletto;
    MeniniDevice *device = menini_init();
    cin >> a;
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
            cout << "Inserire nome file su cui salvare l'svg ";
            cin >> testoletto;
            stringa = menini_to_svg (device);
            menini_write_file(stringa, testoletto);
            break;
        default:
            break;
        }
        cout << "GENERATORE DI IMMAGINI SVG\n Menu:\n [l] - caricare svg da file\n [c] - creare un nuovo svg\n [s] - salvare svg su file\n [q] - quit\n\n Cosa si desidera fare? \n";
        cin >> a;
    }
    return 0;
}
