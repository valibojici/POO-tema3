 #include <iostream>
#include "apartament.h"
#include "casa.h"
#include "gestiune.h"

void main_menu();


int main()
{
 
    
    Locuinta* l = new Apartament({ "Popescu", "Ion", "12345" }, 10, 2, 120);


    l = new Casa({ "Popescu", "Ion", "12345" }, 0, 3, { 120, 60, 60 }, 230);


    Gestiune<Locuinta> t;
	main_menu();
}

void main_menu()
{
	Gestiune<Locuinta> gest;

	std::string input;
	int option;
	while (true)
	{
		std::cout << "1. Adauga apartament\n";
		std::cout << "2. Adauga casa\n";
		std::cout << "3. Afisare\n";
		std::cout << "4. Afisare (sortare dupa tip)\n";
		std::cout << "5. Total obtinut\n";
		std::cout << "6. Sterge\n";
		std::cout << "0. Exit\n";

		bool ok = false;
		while (!ok)
		{
			std::cin >> input;
			ok = true;
			try
			{
				option = std::stoi(input);
				if (option < 0 || option > 6)throw std::invalid_argument("optiunea nu e valida");
			}
			catch (const std::exception& e)
			{
				ok = false;
				std::cout << e.what() << '\n';
			}
		}


		if (option == 1)
		{
			Apartament* a = new Apartament();
			std::cin >> *a;
			gest += {a, "Apartament"};
		}
		else if (option == 2)
		{
			Casa* a = new Casa();
			std::cin >> *a;
			gest += {a, "Casa"};
		}
		else if (option == 3)
		{
			std::cout << "\n";
			gest.afis();
			std::cout << "\n";
		}
		else if (option == 4)
		{
			std::cout << '\n';
			gest.afisPeCategorii();
		}
		else if (option == 5)
		{

			std::cout << "TOTAL: " << gest.getTotalChirie() << '\n';
		}
		else if (option == 6)
		{
			std::cout << "Index = ";
			int idx;
			std::cin >> idx;
			gest -= idx;
		}
		else {
			return;
		}

		std::cout << '\n';
	}
}