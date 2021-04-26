
#include "catch2/catch2.hpp"
#include "motrice.h"

/*
TEST_CASE("init should succeed with non-zero denominator", "[fraction]") {
        
    MyFraction* frac = my_init(3,1);
    REQUIRE( frac != NULL);

    REQUIRE( frac->a == 3);
    REQUIRE( frac->b == 1);

    my_destroy(frac);    
}


TEST_CASE("my_init on zero denominator should return NULL", "[fraction]") {
    
    REQUIRE( my_init(3,0) == NULL);        
}


TEST_CASE("my_square should return a new squared fraction", "[fraction]") {

    MyFraction* orig = my_init(2,3);

    MyFraction * squared = my_square(orig);
    
    REQUIRE(squared->a == 4);
    REQUIRE(squared->b == 9);

    REQUIRE(orig->a == 2);  // should preserve original
    REQUIRE(orig->b == 3);
    
    my_destroy(squared);
    my_destroy(orig);    
}

TEST_CASE("my_div should give fraction as double", "[fraction]") {
    MyFraction* frac = my_init(1,3);    
    REQUIRE(my_div(frac) == Approx(0.3333333333));
    my_destroy(frac);
    
}


#include "cxx_examples.h"
#include "catch2/catch2.hpp"


using namespace cxx_examples;

TEST_CASE("negative square_root should throw exception ", "[cxx_examples]") {
    

    // expects std::invalid_argument exception, if it is not thrown test fails        
    REQUIRE_THROWS_AS( square_root(-1.0), std::invalid_argument);

    REQUIRE(square_root(0.0) == Approx(0.0));
}


TEST_CASE("square_root >= 0 should give positive result ", "[cxx_examples]") {
                
    REQUIRE(square_root(4.0) == Approx(2.0));
}


TEST_CASE("say_hello should produce a string ", "[cxx_examples]") {
    
    REQUIRE( cxx_examples::say_hello("peppo") == std::string("hello peppo"));        
}



*/


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

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='200.000000mm' height='269.000000mm' viewBox='0 0 200.000000 269.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='10.000000' y='10.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='10.000000' y='12.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='10.000000' y='50.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    REQUIRE( menini_to_svg(device) == a);

    delete(device);    
}

TEST_CASE("menini_read_file dovrebbe ritornare la stringa letta", "[motrice]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='200.000000mm' height='269.000000mm' viewBox='0 0 200.000000 269.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='60.000000' height='40.000000' x='10.000000' y='10.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='30.000000' height='20.000000' x='10.000000' y='12.000000' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='180.000000' height='10.000000' x='10.000000' y='50.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='40.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='140.000000' cy='60.000000' rx='9.000000' ry='9.000000' />\n</g>\n</svg>\n";
    
    menini_write_file(a,"motrice.svg");

    REQUIRE( menini_read_file("motrice.svg") == a);   
}

/*TEST_CASE("menini_cerca dovrebbe ritornare la posizione della stringa cercata", "[motrice]") {

    int *partenza = 0;

    REQUIRE( menini_cerca("ciao", "i", partenza, "o") == (float)1);   
}*/

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

    REQUIRE( device->w == (float)200);
    REQUIRE( device->h == (float)269);   
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
    REQUIRE( device->cabina.x == (float)10);
    REQUIRE( device->cabina.y == (float)10); 
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
    REQUIRE( device->vetro.x == (float)10);
    REQUIRE( device->vetro.y == (float)12);  
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
    REQUIRE( device->pianale.x == (float)10);
    REQUIRE( device->pianale.y == (float)50);  
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
    REQUIRE( device->ruotasx.y == (float)60);
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
    REQUIRE( device->ruotadx.y == (float)60);
    REQUIRE( device->ruotadx.r == (float)9);  
}










//testare menini_reset
//testare menini_set
//testare menini_write_file
//finire menini_cerca
//menini_to_svg ha solo un test
//menini_read_file ha solo un test


