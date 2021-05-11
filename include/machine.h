#ifndef MACHINE_H
#define MACHINE_H
#include <string>
#include "motrice.h"
#include "../diitpahomework1/include/car_trailer.h"

using namespace std;

struct MeniniMachine{
    int n;
    MeniniDevice* motrice;
    OselinDevice** arr;
};

//OselinDevice* menini_init_device_in_machine(int);

string menini_to_svg_machine (MeniniMachine*, int);

MeniniDevice* menini_set_motrice_in_machine(MeniniMachine*);

MeniniMachine* menini_machine_create(MeniniMachine*);

string create(OselinDevice*);

MeniniMachine* menini_parse_machine (string);

void menini_delete (MeniniMachine *, MeniniDevice *, bool);

#endif 
