 #include <iostream>
#include "apartament.h"
#include "casa.h"

int main()
{
    Locuinta *l = new Apartament({ "Popescu", "Ion", "12345" }, 10, 2, 120);
    std::cout << *l << "\n\n";

    l = new Casa({ "Popescu", "Ion", "12345" }, 0, 3, { 120, 60, 60 }, 230);

    std::cout << *l << "\n\n";

    l = new Casa;

    std::cin >> *l;
    std::cout << "\n" << *l;
}
 