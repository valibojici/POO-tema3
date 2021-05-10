 #include <iostream>
#include "apartament.h"
#include "casa.h"
#include "gestiune.h"

int main()
{
 
    
    Locuinta* l = new Apartament({ "Popescu", "Ion", "12345" }, 10, 2, 120);


    l = new Casa({ "Popescu", "Ion", "12345" }, 0, 3, { 120, 60, 60 }, 230);


    Gestiune<Locuinta> t;
    t.main_menu();
}