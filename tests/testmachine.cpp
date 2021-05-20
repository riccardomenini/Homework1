#include "catch2/catch2.hpp"
#include "motrice.h"
#include "machine.h"


TEST_CASE("menini_to_svg_machine dovrebbe ritornare la stringa desiderata", "[machine]") {

    MeniniMachine* machine = new MeniniMachine;
    machine->motrice = new MeniniDevice;
    machine->n = 2;
    machine->arr = new OselinDevice* [machine->n];   // notare asterisco dopo MyDevice
    machine->arr[0] = new OselinDevice;

    Parameters p;
    p.svgwidth = 800;
    p.svgheight = 600;    
    p.length    = 100;
    p.height    = 50;
    p.radius    = 18;
    p.ncars     = 2;
    p.nfloors   = 2;
    (*machine->arr[0]) = (*oselin_init(p));
    if (machine->arr[0] != NULL){
        oselin_trigonometry(machine->arr[0],false);
    }

    machine->arr[0]->offset = machine->motrice->margineds + machine->arr[0]->downfloor.width + DOWNOFFSET;
    for (int count = 1; count < machine->n; count++){
        machine->arr[count] = new OselinDevice;
        machine->arr[count] = oselin_init_acopyof(machine->arr[0]);
        machine->arr[count]->offset = (count) * machine->arr[0]->abslength + machine->motrice->margineds + machine->arr[0]->downfloor.width + DOWNOFFSET;

    }
    menini_set_motrice_in_machine (machine);
    machine->motrice->ruotasx.y = machine->arr[0]->frontwheel.y;
    machine->motrice->ruotadx.y = machine->arr[0]->frontwheel.y;    
    
    REQUIRE( menini_to_svg_machine (machine, machine->n) == "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' style='background-color:white' width='2260.000000' height='400.000000' viewBox='0 0 2260.000000 400.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='150.000000' height='184.000000' x='30.000000' y='30.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='75.000000' height='92.000000' x='30.000000' y='66.800003' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='450.000000' height='46.000000' x='30.000000' y='214.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='120.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='390.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<!--2-->\n<!-- <?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='600.000000 '  height='600.000000' >\n<g>\n-->\n<!--#1-->\n\n<rect  x='480.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='480.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='980.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='530.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='942.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='942.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='567.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='567.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='530.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,690.000000,145.000000)'>\n<rect  x='680.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='690.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='690.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,840.000000,145.000000)'>\n<rect  x='830.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='840.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='840.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!-- FINEPRIMOCARRELLO -->\n<!--#1-->\n\n<rect  x='1030.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='1530.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1580.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='1080.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='1492.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1492.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='1117.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1117.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='1080.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,1240.000000,145.000000)'>\n<rect  x='1230.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1240.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1240.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,1390.000000,145.000000)'>\n<rect  x='1380.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1390.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1390.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g></g>\n</svg>\n");

    menini_delete(machine, NULL, true);
}

TEST_CASE("menini_to_svg_machine dovrebbe ritornare ERRORE se passo una machine = NULL", "[machine]") {
    
    REQUIRE( menini_to_svg_machine (NULL, 2) == "ERRORE");
}

TEST_CASE("menini_set_motrice_in_machine dovrebbe settare la motrice", "[machine]") {

    MeniniMachine* machine = new MeniniMachine;
    machine->motrice = new MeniniDevice;
    machine->n = 2;
    machine->arr = new OselinDevice* [machine->n];
    machine->arr[0] = new OselinDevice;
    
    Parameters p;
    p.svgwidth = 800;
    p.svgheight = 600;    
    p.length    = 100;
    p.height    = 50;
    p.radius    = 18;
    p.ncars     = 2;
    p.nfloors   = 2;
    (*machine->arr[0]) = (*oselin_init(p));
    if (machine->arr[0] != NULL){
        oselin_trigonometry(machine->arr[0],false);
    }

    machine->arr[0]->offset = machine->motrice->margineds + machine->arr[0]->downfloor.width + DOWNOFFSET;
    for (int count = 1; count < machine->n; count++){
        machine->arr[count] = new OselinDevice;
        machine->arr[count] = oselin_init_acopyof(machine->arr[0]);
        machine->arr[count]->offset = (count) * machine->arr[0]->abslength + machine->motrice->margineds + machine->arr[0]->downfloor.width + DOWNOFFSET;

    }
    menini_set_motrice_in_machine (machine);

    REQUIRE (machine->motrice->pianale.w == (float) 450); //Non può fallire in quanto non ho definito nessun altro parametro 
    REQUIRE (machine->motrice->pianale.h == (float) 46); //Non può fallire in quanto non ho definito nessun altro parametro
    REQUIRE (machine->motrice->ruotasx.x == (float) 120);
    REQUIRE (machine->motrice->ruotadx.x == (float) 390);
    REQUIRE (machine->motrice->ruotadx.r == (float) 27);   

    menini_delete(machine, NULL, true);
}

TEST_CASE("menini_set_motrice_in_machine dovrebbe tornare NULL se machine == NULL", "[machine]") {

    
    menini_set_motrice_in_machine (NULL);

    REQUIRE (menini_set_motrice_in_machine (NULL) == NULL);
}

TEST_CASE("menini_parse_machine dovrebbe tornare la struttura dati riempita per la motrice", "[machine]") {

    MeniniMachine* machine = new MeniniMachine;

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' style='background-color:white' width='2334.000000' height='400.000000' viewBox='0 0 2334.000000 400.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='150.000000' height='184.000000' x='30.000000' y='30.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='75.000000' height='92.000000' x='30.000000' y='66.800003' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='450.000000' height='46.000000' x='30.000000' y='214.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='120.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='390.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<!--2-->\n<!-- <?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='600.000000 '  height='600.000000' >\n<g>\n-->\n<!--#1-->\n\n<rect  x='480.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='480.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='980.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='530.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='942.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='942.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='567.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='567.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='530.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,690.000000,145.000000)'>\n<rect  x='680.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='690.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='690.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,840.000000,145.000000)'>\n<rect  x='830.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='840.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='840.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!-- FINEPRIMOCARRELLO -->\n<!--#1-->\n\n<rect  x='1030.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='1530.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1580.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='1080.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='1492.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1492.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='1117.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1117.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='1080.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,1240.000000,145.000000)'>\n<rect  x='1230.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1240.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1240.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,1390.000000,145.000000)'>\n<rect  x='1380.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1390.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1390.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g></g>\n</svg>\n";

    machine = menini_parse_machine (a);

    REQUIRE( machine->motrice->pianale.w == (float)450);
    REQUIRE( machine->motrice->pianale.h == (float)46); 
    REQUIRE( machine->motrice->pianale.x == (float)30);
    REQUIRE( machine->motrice->pianale.y == (float)214);
    REQUIRE( machine->motrice->cabina.w == (float)150);
    REQUIRE( machine->motrice->cabina.h == (float)184); 
    REQUIRE( machine->motrice->cabina.x == (float)30);
    REQUIRE( machine->motrice->cabina.y == (float)30);
    REQUIRE( machine->motrice->vetro.w == (float)75);
    REQUIRE( machine->motrice->vetro.h == (float)92); 
    REQUIRE( machine->motrice->vetro.x == (float)30);
    REQUIRE( machine->motrice->vetro.y == (float)66.800003);
    REQUIRE( machine->motrice->ruotasx.x == (float)120);
    REQUIRE( machine->motrice->ruotasx.y == (float)253.25);
    REQUIRE( machine->motrice->ruotasx.r == (float)27);
    REQUIRE( machine->motrice->ruotadx.x == (float)390);
    REQUIRE( machine->motrice->ruotadx.y == (float)253.25);
    REQUIRE( machine->motrice->ruotadx.r == (float)27);  
}

TEST_CASE("menini_parse_machine dovrebbe tornare la struttura dati riempita per il treno di carrelli", "[machine]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' style='background-color:white' width='2334.000000' height='400.000000' viewBox='0 0 2334.000000 400.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='150.000000' height='184.000000' x='30.000000' y='30.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='75.000000' height='92.000000' x='30.000000' y='66.800003' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='450.000000' height='46.000000' x='30.000000' y='214.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='120.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='390.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<!--2-->\n<!-- <?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='600.000000 '  height='600.000000' >\n<g>\n-->\n<!--#1-->\n\n<rect  x='480.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='480.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='980.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='530.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='942.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='942.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='567.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='567.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='530.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,690.000000,145.000000)'>\n<rect  x='680.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='690.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='690.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,840.000000,145.000000)'>\n<rect  x='830.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='840.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='840.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!-- FINEPRIMOCARRELLO -->\n<!--#1-->\n\n<rect  x='1030.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='1530.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1580.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='1080.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='1492.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1492.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='1117.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1117.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='1080.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,1240.000000,145.000000)'>\n<rect  x='1230.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1240.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1240.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,1390.000000,145.000000)'>\n<rect  x='1380.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1390.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1390.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g></g>\n</svg>\n";

    MeniniMachine* machine = menini_parse_machine (a);

    string inizio;
    string carrello;
    string fine = "</g>\n</svg>";
    size_t intestazione = a.find("<?xml", 10);
    size_t fineintestazione = a.find("-->", intestazione);
    carrello += a.substr(intestazione, fineintestazione-intestazione);
    carrello += a.substr(fineintestazione + 4, (a.find("<!-- FINEPRIMOCARRELLO -->", 0)) - (fineintestazione + 4));
    carrello += fine;
    OselinDevice* dev = new OselinDevice;
    oselin_parsing(dev, carrello);
    
    REQUIRE(dev->downfloor.x == machine->arr[0]->downfloor.x);
    REQUIRE(dev->downfloor.y == machine->arr[0]->downfloor.y);
    REQUIRE(dev->downfloor.width == machine->arr[0]->downfloor.width);
    REQUIRE(dev->downfloor.height == machine->arr[0]->downfloor.height);

    REQUIRE(dev->upfloor.x == machine->arr[0]->upfloor.x);
    REQUIRE(dev->upfloor.y == machine->arr[0]->upfloor.y);
    REQUIRE(dev->upfloor.width == machine->arr[0]->upfloor.width);
    REQUIRE(dev->upfloor.height == machine->arr[0]->upfloor.height);

    REQUIRE(dev->frontwheel.radius == machine->arr[0]->frontwheel.radius);
    REQUIRE(dev->frontwheel.x == machine->arr[0]->frontwheel.x);
    REQUIRE(dev->frontwheel.y == machine->arr[0]->frontwheel.y);

    REQUIRE(dev->rearwheel.radius == machine->arr[0]->rearwheel.radius);
    REQUIRE(dev->rearwheel.x == machine->arr[0]->rearwheel.x);
    REQUIRE(dev->rearwheel.y == machine->arr[0]->rearwheel.y);

    REQUIRE(dev->frontjoint.body.x == machine->arr[0]->frontjoint.body.x);
    REQUIRE(dev->frontjoint.body.y == machine->arr[0]->frontjoint.body.y);
    REQUIRE(dev->frontjoint.body.width == machine->arr[0]->frontjoint.body.width);
    REQUIRE(dev->frontjoint.body.height == machine->arr[0]->frontjoint.body.height);
    REQUIRE(dev->frontjoint.head.x == machine->arr[0]->frontjoint.head.x);
    REQUIRE(dev->frontjoint.head.y == machine->arr[0]->frontjoint.head.y);
    REQUIRE(dev->frontjoint.head.radius == machine->arr[0]->frontjoint.head.radius);
    REQUIRE(dev->frontjoint.length == machine->arr[0]->frontjoint.length);

    REQUIRE(dev->rearjoint.body.x == machine->arr[0]->rearjoint.body.x);
    REQUIRE(dev->rearjoint.body.y == machine->arr[0]->rearjoint.body.y);
    REQUIRE(dev->rearjoint.body.width == machine->arr[0]->rearjoint.body.width);
    REQUIRE(dev->rearjoint.body.height == machine->arr[0]->rearjoint.body.height);
    REQUIRE(dev->rearjoint.head.x == machine->arr[0]->rearjoint.head.x);
    REQUIRE(dev->rearjoint.head.y == machine->arr[0]->rearjoint.head.y);
    REQUIRE(dev->rearjoint.head.radius == machine->arr[0]->rearjoint.head.radius);
    REQUIRE(dev->rearjoint.length == machine->arr[0]->rearjoint.length);

    REQUIRE(dev->frontaxis.angle == machine->arr[0]->frontaxis.angle);
    REQUIRE(dev->frontaxis.body.x == machine->arr[0]->frontaxis.body.x);
    REQUIRE(dev->frontaxis.body.y == machine->arr[0]->frontaxis.body.y);
    REQUIRE(dev->frontaxis.body.width == machine->arr[0]->frontaxis.body.width);
    REQUIRE(dev->frontaxis.body.height == machine->arr[0]->frontaxis.body.height);
    REQUIRE(dev->frontaxis.bottomscrew.x == machine->arr[0]->frontaxis.bottomscrew.x);
    REQUIRE(dev->frontaxis.bottomscrew.y == machine->arr[0]->frontaxis.bottomscrew.y);
    REQUIRE(dev->frontaxis.bottomscrew.radius == machine->arr[0]->frontaxis.bottomscrew.radius);
    REQUIRE(dev->frontaxis.rotationpoint[0] == machine->arr[0]->frontaxis.rotationpoint[0]);
    REQUIRE(dev->frontaxis.rotationpoint[1] == machine->arr[0]->frontaxis.rotationpoint[1]);
    REQUIRE(dev->frontaxis.topscrew.x == machine->arr[0]->frontaxis.topscrew.x);
    REQUIRE(dev->frontaxis.topscrew.y == machine->arr[0]->frontaxis.topscrew.y);
    REQUIRE(dev->frontaxis.topscrew.radius == machine->arr[0]->frontaxis.topscrew.radius);

    REQUIRE(dev->rearaxis.angle == machine->arr[0]->rearaxis.angle);
    REQUIRE(dev->rearaxis.body.x == machine->arr[0]->rearaxis.body.x);
    REQUIRE(dev->rearaxis.body.y == machine->arr[0]->rearaxis.body.y);
    REQUIRE(dev->rearaxis.body.width == machine->arr[0]->rearaxis.body.width);
    REQUIRE(dev->rearaxis.body.height == machine->arr[0]->rearaxis.body.height);
    REQUIRE(dev->rearaxis.bottomscrew.x == machine->arr[0]->rearaxis.bottomscrew.x);
    REQUIRE(dev->rearaxis.bottomscrew.y == machine->arr[0]->rearaxis.bottomscrew.y);
    REQUIRE(dev->rearaxis.bottomscrew.radius == machine->arr[0]->rearaxis.bottomscrew.radius);
    REQUIRE(dev->rearaxis.rotationpoint[0] == machine->arr[0]->rearaxis.rotationpoint[0]);
    REQUIRE(dev->rearaxis.rotationpoint[1] == machine->arr[0]->rearaxis.rotationpoint[1]);
    REQUIRE(dev->rearaxis.topscrew.x == machine->arr[0]->rearaxis.topscrew.x);
    REQUIRE(dev->rearaxis.topscrew.y == machine->arr[0]->rearaxis.topscrew.y);
    REQUIRE(dev->rearaxis.topscrew.radius == machine->arr[0]->rearaxis.topscrew.radius);
}

TEST_CASE("menini_parse_machine dovrebbe tornare NULL per una stringa vuota", "[machine]") {

    string a = "";
    
    REQUIRE(menini_parse_machine(a) == NULL);
}

TEST_CASE("menini_are_equal dovrebbe tornare true se le due machine sono uguali", "[machine]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' style='background-color:white' width='2334.000000' height='400.000000' viewBox='0 0 2334.000000 400.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='150.000000' height='184.000000' x='30.000000' y='30.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='75.000000' height='92.000000' x='30.000000' y='66.800003' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='450.000000' height='46.000000' x='30.000000' y='214.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='120.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='390.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<!--2-->\n<!-- <?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='600.000000 '  height='600.000000' >\n<g>\n-->\n<!--#1-->\n\n<rect  x='480.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='480.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='980.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='530.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='942.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='942.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='567.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='567.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='530.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,690.000000,145.000000)'>\n<rect  x='680.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='690.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='690.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,840.000000,145.000000)'>\n<rect  x='830.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='840.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='840.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!-- FINEPRIMOCARRELLO -->\n<!--#1-->\n\n<rect  x='1030.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='1530.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1580.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='1080.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='1492.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1492.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='1117.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1117.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='1080.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,1240.000000,145.000000)'>\n<rect  x='1230.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1240.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1240.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,1390.000000,145.000000)'>\n<rect  x='1380.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1390.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1390.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g></g>\n</svg>\n";

    MeniniMachine* machine1 = menini_parse_machine(a);
    MeniniMachine* machine2 = menini_parse_machine(a);

    REQUIRE(menini_are_equal(machine1, machine2) == true);
}

TEST_CASE("menini_are_equal dovrebbe tornare true se le due machine sono entrambe NULL", "[machine]") {

    REQUIRE(menini_are_equal(NULL, NULL)==true);
}

TEST_CASE("menini_are_equal dovrebbe tornare false se una è NULL e l'altra no", "[machine]") {

    string a = "<?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' style='background-color:white' width='2334.000000' height='400.000000' viewBox='0 0 2334.000000 400.000000'>\n<g>\n<rect style='fill:#ff7f2a;fill-rule:evenodd;stroke-width:0.176061' id='rect10' width='150.000000' height='184.000000' x='30.000000' y='30.000000' />\n<rect style='fill:#00ffff;stroke-width:0.310366' id='rect12' width='75.000000' height='92.000000' x='30.000000' y='66.800003' />\n<rect style='fill:#ff7f2a;stroke-width:0.264583' id='rect95' width='450.000000' height='46.000000' x='30.000000' y='214.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14' cx='120.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<ellipse style='fill:#4d4d4d;stroke-width:0.23472' id='path14-7' cx='390.000000' cy='253.250000' rx='27.000000' ry='27.000000' />\n<!--2-->\n<!-- <?xml version='1.0' encoding='UTF-8' standalone='no'?>\n<svg xmlns='http://www.w3.org/2000/svg' width='600.000000 '  height='600.000000' >\n<g>\n-->\n<!--#1-->\n\n<rect  x='480.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='480.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='980.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='530.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='942.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='942.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='567.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='567.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='530.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,690.000000,145.000000)'>\n<rect  x='680.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='690.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='690.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,840.000000,145.000000)'>\n<rect  x='830.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='840.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='840.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!-- FINEPRIMOCARRELLO -->\n<!--#1-->\n\n<rect  x='1030.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1030.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#2-->\n\n<rect  x='1530.000000' y='240.000000' width='50.000000' height='10.000000' style='stroke-width:0.500000; stroke:black' fill='#990000' />\n<circle cx='1580.000000' cy='245.000000' r='6.000000' stroke='black' stroke-width='1.800000' fill='white' />\n<!--#3-->\n\n<rect  x='1080.000000' y='230.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#4-->\n\n<circle cx='1492.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1492.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#5-->\n\n<circle cx='1117.500000' cy='253.250000' r='27.000000' stroke='black' stroke-width='2.700000' fill='black' />\n<circle cx='1117.500000' cy='253.250000' r='20.250000' stroke='black' stroke-width='2.700000' fill= 'gray' />\n<!--#6-->\n\n<rect  x='1080.000000' y='30.000000' width='450.000000' height='30.000000' style='stroke-width:1.500000; stroke:black' fill='#990000' />\n<!--#7-->\n\n<g transform='rotate(20.000000,1240.000000,145.000000)'>\n<rect  x='1230.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1240.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1240.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g>\n<!--#8-->\n\n<g transform='rotate(20.000000,1390.000000,145.000000)'>\n<rect  x='1380.000000' y='30.000000' width='20.000000' height='230.000000' style='stroke-width:1.000000; stroke:black' fill='#990000' />\n<circle cx='1390.000000' cy='250.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n<circle cx='1390.000000' cy='40.000000' r='6.666667' stroke='black' stroke-width='2.700000' fill='white' />\n</g></g>\n</svg>\n";

    MeniniMachine* machine1 = menini_parse_machine(a);

    REQUIRE(menini_are_equal(machine1, NULL) == false);
    REQUIRE(menini_are_equal(NULL, machine1) == false);
}

TEST_CASE("oselin_init_acopyof dovrebbe ritornare una copia del device", "[machine]") {

    //MeniniMachine* machine = new MeniniMachine;
    //machine->motrice = new MeniniDevice;
    //machine->n = 2;
    //OselinDevice* dev = new OselinDevice* [machine->n];   // notare asterisco dopo MyDevice
    OselinDevice* dev = new OselinDevice;

    Parameters p;
    p.svgwidth = 800;
    p.svgheight = 600;    
    p.length    = 100;
    p.height    = 50;
    p.radius    = 18;
    p.ncars     = 2;
    p.nfloors   = 2;
    (*dev) = (*oselin_init(p));
    if (dev != NULL){
        oselin_trigonometry(dev,false);
    }

    dev->offset = 30 + dev->downfloor.width + DOWNOFFSET;
    REQUIRE (oselin_to_svg(dev) == oselin_to_svg(oselin_init_acopyof(dev)));



}

TEST_CASE("oselin_init_acopyof dovrebbe ritornare una copia del device in caso di dev = NULL", "[machine]") {

    OselinDevice* dev = NULL;

    REQUIRE (NULL == oselin_init_acopyof(dev));



}


//Manca menini_machine_create
