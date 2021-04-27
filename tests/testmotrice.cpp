
#include "catch2/catch2.hpp"
#include "motrice.h"

TEST_CASE("init dovrebbe ritornare un puntatore a un device != NULL", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    REQUIRE( device != NULL);

    delete(device);    
}

TEST_CASE("init dovrebbe ritornare un puntatore a un device con w e h = 0", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    REQUIRE( device->w == 0);
    REQUIRE( device->h == 0);

    delete(device);    
}

TEST_CASE("menini_check_pianale_w dovrebbe ritornare 0 se w pianale rispetta la ruota sinistra, 1 altrimenti ", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->ruotasx.x = 10;
    device->ruotadx.x = 100;

    float new_w1 = 10;

    REQUIRE( menini_check_pianale_w(device, new_w1) == 1);

    new_w1 = 80;

    REQUIRE( menini_check_pianale_w(device, new_w1) == 0);

    delete(device);    
}

TEST_CASE("menini_check_pianale_w dovrebbe ritornare 0 se w pianale rispetta la ruota destra, 1 altrimenti ", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->ruotadx.x = 60;
    device->ruotasx.x = 0;

    float new_w2 = 180;

    REQUIRE( menini_check_pianale_w(device, new_w2) == 1);

    new_w2 = 80;

    REQUIRE( menini_check_pianale_w(device, new_w2) == 0);

    delete(device);    
}

TEST_CASE("menini_set_pianale_w dovrebbe ritornare 0 se i w pianale rispetta i la ruota sinistra, 1 altrimenti ", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->ruotasx.x = 30;
    float new_w = 20;

    REQUIRE( menini_set_pianale_w(device, new_w) == 1);

    new_w = 90;

    REQUIRE( menini_set_pianale_w(device, new_w) == 0);

    device->ruotadx.x = 60;
    new_w = 10;

    REQUIRE( menini_set_pianale_w(device, new_w) == 1);

    new_w = 70;

    REQUIRE( menini_set_pianale_w(device, new_w) == 0);

    delete(device);    
}

TEST_CASE("menini_set_pianale_w  dovrebbe ritornare 0 se il nuovo parametro viene settato", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->ruotadx.x = 60;
    device->ruotasx.x = 30;
    
    float new_w = 10;

    REQUIRE( menini_set_pianale_w(device, new_w) == 1);

    new_w = 90;

    REQUIRE( menini_set_pianale_w(device, new_w) == 0);
    REQUIRE( device->pianale.w == new_w);

    delete(device);    
}

TEST_CASE("menini_check_pianale_h dovrebbe ritornare 1 altrimenti se h pianale non rispetta i raggi", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->ruotadx.r = 20;
    float new_h = 10;

    REQUIRE( menini_check_pianale_h(device, new_h) == 1);

    delete(device);    
}


TEST_CASE("menini_check_pianale_h dovrebbe ritornare 0 se  h pianale rispetta i raggi", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->ruotadx.r = 20;
    float new_h = 25;

    REQUIRE( menini_check_pianale_h(device, new_h) == 0);

    delete(device);    
}

TEST_CASE("menini_set_pianale_h dovrebbe ritornare 1 se h pianale non rispetta i raggi", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->ruotadx.r = 20;
    float new_h = 10;

    REQUIRE( menini_set_pianale_h(device, new_h) == 1);

    delete(device);    
}

TEST_CASE("menini_set_pianale_h dovrebbe ritornare 0 se h pianale rispetta i raggi", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->ruotadx.r = 20;
    float new_h = 25;


    REQUIRE( menini_set_pianale_h(device, new_h) == 0);
    REQUIRE( device->pianale.h == new_h);

    delete(device);    
}

TEST_CASE("menini_check_raggi dovrebbe ritornare 1 se i raggi non rispettano l'altezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.h = 20;
    float new_r = 30;

    REQUIRE( menini_check_raggi(device, new_r) == 1);

    delete(device);    
}

TEST_CASE("menini_check_raggi dovrebbe ritornare 0 se i raggi rispettano l'altezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.h = 20;
    float new_r = 18;

    REQUIRE( menini_check_raggi(device, new_r) == 0);

    delete(device);    
}

TEST_CASE("menini_set_raggi dovrebbe ritornare 1 se i raggi non rispettano l'altezza", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.h = 20;
    float new_r = 30;

    REQUIRE( menini_set_raggi(device, new_r) == 1);

    delete(device);    
}

TEST_CASE("menini_set_raggi dovrebbe ritornare 0 se i raggi rispettano l'altezza", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.h = 20;
    float new_r = 18;

    REQUIRE( menini_set_raggi(device, new_r) == 0);
    REQUIRE( device->ruotadx.r == new_r);

    delete(device);    
}

TEST_CASE("menini_check_ruotasx dovrebbe ritornare 1 se la ruotasx non rispetta la larghezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.w = 20;
    float new_x = 40;

    REQUIRE( menini_check_ruotasx(device, new_x) == 1);

    delete(device);    
}

TEST_CASE("menini_check_ruotasx dovrebbe ritornare 0 se la ruotasx rispetta la larghezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.w = 20;
    float new_x = 5;

    REQUIRE( menini_check_ruotasx(device, new_x) == 0);

    delete(device);    
}

TEST_CASE("menini_set_ruotasx dovrebbe ritornare 1 se la ruotasx non rispetta la larghezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.w = 20;
    float new_x = 40;

    REQUIRE( menini_set_ruotasx(device, new_x) == 1);

    delete(device);    
}

TEST_CASE("menini_set_ruotasx dovrebbe ritornare 0 se la ruotasx rispetta la larghezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.w = 20;
    float new_x = 5;

    REQUIRE( menini_set_ruotasx(device, new_x) == 0);
    REQUIRE( device->ruotasx.x == new_x);

    delete(device);    
}

TEST_CASE("menini_check_ruotadx dovrebbe ritornare 1 se la ruotadx non rispetta la larghezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.w = 20;
    float new_x = 5;

    REQUIRE( menini_check_ruotadx(device, new_x) == 1);

    delete(device);    
}

TEST_CASE("menini_check_ruotadx dovrebbe ritornare 0 se la ruotadx rispetta la larghezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.w = 20;
    float new_x = 40;

    REQUIRE( menini_check_ruotadx(device, new_x) == 0);

    delete(device);    
}

TEST_CASE("menini_set_ruotadx dovrebbe ritornare 1 se la ruotadx non rispetta la larghezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.w = 20;
    float new_x = 5;

    REQUIRE( menini_set_ruotadx(device, new_x) == 1);

    delete(device);    
}

TEST_CASE("menini_set_ruotadx dovrebbe ritornare 0 se la ruotadx rispetta la larghezza del pianale", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    device->pianale.w = 20;
    float new_x = 40;

    REQUIRE( menini_set_ruotadx(device, new_x) == 0);
    REQUIRE( device->ruotadx.x == new_x);

    delete(device);    
}

TEST_CASE("menini_to_svg dovrebbe ritornare la stringa corrispondente", "[motrice]") {
        
    MeniniDevice* device = menini_init();
    
    device->pianale.w = (float)180;
    device->pianale.h = (float)10;

    device->ruotasx.x = (float)40;
    device->ruotasx.r = (float)9;

    device->ruotadx.x = (float)140;
    device->ruotadx.r = (float)9;

    menini_reset(device);

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='420.000000mm' height='219.000000mm' viewBox='0 0 420.000000 219.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='30.000000' y='30.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='30.000000' y='38.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='30.000000' y='70.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='80.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='80.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    REQUIRE( menini_to_svg(device, false) == a);

    delete(device);    
}

TEST_CASE("menini_to_svg dovrebbe ritornare la stringa corrispondente anche nel caso di presenza delle misure", "[motrice]") {
        
    MeniniDevice* device = menini_init();
    
    device->pianale.w = (float)180;
    device->pianale.h = (float)10;

    device->ruotasx.x = (float)40 + 30;
    device->ruotasx.r = (float)9;

    device->ruotadx.x = (float)140 + 30;
    device->ruotadx.r = (float)9;

    menini_reset(device);

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='420.000000mm' height='219.000000mm' viewBox='0 0 420.000000 219.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='30.000000' y='30.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='30.000000' y='38.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='30.000000' y='70.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='70.000000' cy='80.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='170.000000' cy='80.000000' rx='9.000000' ry='9.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect20' width='18.000000' height='1.000000' x='210.000000' y='70.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect21' width='18.000000' height='1.000000' x='210.000000' y='79.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect22' width='1.000000' height='10.000000' x='225.000000' y='70.000000' />\n<text xmlns='http://www.w3.org/2000/svg' x='228.000000' y='75.000000' fill='black' dominant-baseline='middle' text-anchor='start' font-size='8px' >10.000000</text><rect style='fill:#000000;stroke-width:0.310366' id='rect23' width='1.000000' height='13.500000' x='60.000000' y='80.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect24' width='1.000000' height='13.500000' x='70.000000' y='80.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect25' width='9.000000' height='1.000000' x='61.000000' y='92.000000' />\n<text xmlns='http://www.w3.org/2000/svg' x='65.500000' y='102.000000' fill='black' dominant-baseline='middle' text-anchor='middle' font-size='8px' >9.000000</text><rect style='fill:#000000;stroke-width:0.310366' id='rect26' width='1.000000' height='32.000000' x='30.000000' y='80.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect27' width='1.000000' height='32.000000' x='70.000000' y='80.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect28' width='40.000000' height='1.000000' x='30.000000' y='109.000000' />\n<text xmlns='http://www.w3.org/2000/svg' x='50.000000' y='119.000000' fill='black' dominant-baseline='middle' text-anchor='middle' font-size='8px' >70.000000</text><rect style='fill:#000000;stroke-width:0.310366' id='rect29' width='1.000000' height='49.000000' x='30.000000' y='80.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect30' width='1.000000' height='49.000000' x='170.000000' y='80.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect31' width='140.000000' height='1.000000' x='30.000000' y='126.000000' />\n<text xmlns='http://www.w3.org/2000/svg' x='100.000000' y='136.000000' fill='black' dominant-baseline='middle' text-anchor='middle' font-size='8px' >170.000000</text><rect style='fill:#000000;stroke-width:0.310366' id='rect32' width='1.000000' height='66.000000' x='30.000000' y='80.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect33' width='1.000000' height='66.000000' x='209.000000' y='80.000000' />\n<rect style='fill:#000000;stroke-width:0.310366' id='rect34' width='180.000000' height='1.000000' x='30.000000' y='143.000000' />\n<text xmlns='http://www.w3.org/2000/svg' x='120.000000' y='153.000000' fill='black' dominant-baseline='middle' text-anchor='middle' font-size='8px' >180.000000</text></g>\n</svg>\n";
    
    REQUIRE( menini_to_svg(device, true) == a);

    delete(device);    
}

TEST_CASE("menini_read_file dovrebbe ritornare la stringa letta", "[motrice]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='200.000000mm' height='269.000000mm' viewBox='0 0 200.000000 269.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='10.000000' y='10.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='10.000000' y='12.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='10.000000' y='50.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    menini_write_file(a,"motrice.svg");

    REQUIRE( menini_read_file("motrice.svg") == a);   
}

TEST_CASE("menini_parse dovrebbe ritornare il device creato dalla stringa letta", "[motrice]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='200.000000mm' height='269.000000mm' viewBox='0 0 200.000000 269.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='10.000000' y='10.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='10.000000' y='12.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='10.000000' y='50.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    MeniniDevice *device = menini_parse(a);

    REQUIRE( device->w == (float)200);
    REQUIRE( device->h == (float)269);   
}

TEST_CASE("menini_parse dovrebbe ritornare la cabina creata dalla stringa letta", "[motrice]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='200.000000mm' height='269.000000mm' viewBox='0 0 200.000000 269.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='10.000000' y='10.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='10.000000' y='12.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='10.000000' y='50.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    MeniniDevice *device = menini_parse(a);

    REQUIRE( device->cabina.w == (float)60);
    REQUIRE( device->cabina.h == (float)40); 
    REQUIRE( device->cabina.x == (float)10);
    REQUIRE( device->cabina.y == (float)10);  
}

TEST_CASE("menini_parse dovrebbe ritornare il vetro creato dalla stringa letta", "[motrice]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='200.000000mm' height='269.000000mm' viewBox='0 0 200.000000 269.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='10.000000' y='10.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='10.000000' y='12.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='10.000000' y='50.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    MeniniDevice *device = menini_parse(a);

    REQUIRE( device->vetro.w == (float)30);
    REQUIRE( device->vetro.h == (float)20); 
    REQUIRE( device->vetro.x == (float)10);
    REQUIRE( device->vetro.y == (float)12);  
}

TEST_CASE("menini_parse dovrebbe ritornare il pianale creato dalla stringa letta", "[motrice]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='200.000000mm' height='269.000000mm' viewBox='0 0 200.000000 269.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='10.000000' y='10.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='10.000000' y='12.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='10.000000' y='50.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    MeniniDevice *device = menini_parse(a);

    REQUIRE( device->pianale.w == (float)180);
    REQUIRE( device->pianale.h == (float)10); 
    REQUIRE( device->pianale.x == (float)10);
    REQUIRE( device->pianale.y == (float)50);  
}

TEST_CASE("menini_parse dovrebbe ritornare la ruota sx dalla stringa letta", "[motrice]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='200.000000mm' height='269.000000mm' viewBox='0 0 200.000000 269.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='10.000000' y='10.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='10.000000' y='12.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='10.000000' y='50.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    MeniniDevice *device = menini_parse(a);
 
    REQUIRE( device->ruotasx.x == (float)40);
    REQUIRE( device->ruotasx.y == (float)60);
    REQUIRE( device->ruotasx.r == (float)9);  
}

TEST_CASE("menini_parse dovrebbe ritornare la ruota dx dalla stringa letta", "[motrice]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='200.000000mm' height='269.000000mm' viewBox='0 0 200.000000 269.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='10.000000' y='10.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='10.000000' y='12.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='10.000000' y='50.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    MeniniDevice *device = menini_parse(a);
 
    REQUIRE( device->ruotadx.x == (float)140);
    REQUIRE( device->ruotadx.y == (float)60);
    REQUIRE( device->ruotadx.r == (float)9);  
}

TEST_CASE("menini_reset dovrebbe settare tutte le dimensioni del device non richieste in input", "[motrice]") {

    MeniniDevice *device = menini_init();

    device->pianale.w = (float)180;
    device->pianale.h = (float)10;

    device->ruotasx.x = (float)40;
    device->ruotasx.r = (float)9;

    device->ruotadx.x = (float)140;
    device->ruotadx.r = (float)9; 

    menini_reset(device);

    REQUIRE( device->w == (float)(2 * 180 + 2 * device->margineds));
    REQUIRE( device->h == (float)(2 * device->marginess + 40 + 10 + 9 + 100));   
}


TEST_CASE("menini_reset dovrebbe settare tutte le dimensioni della cabina non richieste in input", "[motrice]") {

    MeniniDevice *device = menini_init();

    device->pianale.w = (float)180;
    device->pianale.h = (float)10;

    device->ruotasx.x = (float)40;
    device->ruotasx.r = (float)9;

    device->ruotadx.x = (float)140;
    device->ruotadx.r = (float)9; 

    menini_reset(device); 

    REQUIRE( device->cabina.w == (float)60);
    REQUIRE( device->cabina.h == (float)40); 
    REQUIRE( device->cabina.x == (float)device->margineds);
    REQUIRE( device->cabina.y == (float)device->marginess); 
}

TEST_CASE("menini_reset dovrebbe settare tutte le dimensioni del vetro non richieste in input", "[motrice]") {

    MeniniDevice *device = menini_init();

    device->pianale.w = (float)180;
    device->pianale.h = (float)10;

    device->ruotasx.x = (float)40;
    device->ruotasx.r = (float)9;

    device->ruotadx.x = (float)140;
    device->ruotadx.r = (float)9; 

    menini_reset(device); 

    REQUIRE( device->vetro.w == (float)30);
    REQUIRE( device->vetro.h == (float)20); 
    REQUIRE( device->vetro.x == (float)device->margineds);
    REQUIRE( device->vetro.y == (float)device->marginess + 8);  
}

TEST_CASE("menini_reset dovrebbe settare tutte le dimensioni del pianale non richieste in input", "[motrice]") {

    MeniniDevice *device = menini_init();

    device->pianale.w = (float)180;
    device->pianale.h = (float)10;

    device->ruotasx.x = (float)40;
    device->ruotasx.r = (float)9;

    device->ruotadx.x = (float)140;
    device->ruotadx.r = (float)9; 

    menini_reset(device); 

    REQUIRE( device->pianale.w == (float)180);
    REQUIRE( device->pianale.h == (float)10); 
    REQUIRE( device->pianale.x == (float)device->margineds);
    REQUIRE( device->pianale.y == (float)device->marginess + 40);  
}

TEST_CASE("menini_reset dovrebbe settare tutte le dimensioni della ruotasx non richieste in input", "[motrice]") {

    MeniniDevice *device = menini_init();

    device->pianale.w = (float)180;
    device->pianale.h = (float)10;

    device->ruotasx.x = (float)40;
    device->ruotasx.r = (float)9;

    device->ruotadx.x = (float)140;
    device->ruotadx.r = (float)9; 

    menini_reset(device); 
 
    REQUIRE( device->ruotasx.x == (float)40);
    REQUIRE( device->ruotasx.y == (float)device->marginess + 40 +10);
    REQUIRE( device->ruotasx.r == (float)9);  
}

TEST_CASE("menini_reset dovrebbe settare tutte le dimensioni della ruota dx non richieste in input", "[motrice]") {

    MeniniDevice *device = menini_init();

    device->pianale.w = (float)180;
    device->pianale.h = (float)10;

    device->ruotasx.x = (float)40;
    device->ruotasx.r = (float)9;

    device->ruotadx.x = (float)140;
    device->ruotadx.r = (float)9; 

    menini_reset(device); 
 
    REQUIRE( device->ruotadx.x == (float)140);
    REQUIRE( device->ruotadx.y == (float)device->marginess + 40 +10);
    REQUIRE( device->ruotadx.r == (float)9);  
}

/*TEST_CASE("menini_cerca dovrebbe ritornare la posizione della stringa cercata", "[motrice]") {

    int *partenza = 0;

    REQUIRE( menini_cerca("ciao", "i", partenza, "o") == (float)1);   
}*/







//da aggiungere:
//testare menini_write_file
//testare menini_cerca
//menini_to_svg ha solo un test
//menini_read_file ha solo un test


