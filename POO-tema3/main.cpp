#include <iostream>
#include <cstdlib>
#include "apartament.h"
#include "casa.h"
#include "gestiune.h"

void main_menu2();

void main_menu();
void locuinte_menu();
void case_menu();

class Menu {
private:
	std::vector<std::string> m_options;
public:
	Menu(const std::vector<std::string>& options) : m_options(options) {}

	void display()
	{
		for (int i = 0; i < m_options.size(); ++i)
		{
			std::cout << " " << i + 1 << ". " << m_options[i] << '\n';
		}
		std::cout << " 0. Exit\n";
	}

	int input()
	{
		
		std::string input;
		int opt;

		bool ok = false;
		while (!ok)
		{
			ok = true;
			std::cout << "Enter option: ";
			std::cin >> input;
			try
			{
				opt = std::stoi(input);
				if (opt < 0 || opt > m_options.size())throw std::invalid_argument("Invalid index");

			}
			catch (const std::exception& e)
			{
				ok = false;
				std::cout << e.what() << '\n';
			}
		}
		return opt;
	}
};


int main()
{
 
    
    Locuinta* l = new Apartament({ "Popescu", "Ion", "12345" }, 10, 2, 120);


    l = new Casa({ "Popescu", "Ion", "12345" }, 0, 3, { 120, 60, 60 }, 230);


    Gestiune<Locuinta> t;
	main_menu();
}

void main_menu()
{
	Menu m({
		"Gestiune locuinte",
		"Gestiune case"});

	while (true)
	{
		system("cls");

		m.display();
		int opt = m.input();
		if (opt == 0)break;
		else
			if (opt == 1)locuinte_menu();
			else
				if (opt == 2)case_menu();
	}
}

void locuinte_menu()
{
	Gestiune<Locuinta> g;
	Menu m({
		"Adauga apartament",
		"Adauga casa",
		"Afisare",
		"Afisare (sortare dupa tip)",
		"Total obtinut",
		"Sterge"});

	while (true)
	{
		m.display();
		int opt = m.input();
		switch (opt)
		{
		case 0:
			return; break;

		case 1:
			{
				Locuinta* a = new Apartament();
				std::cin >> *a;
				g += {a, "Apartament"};
				break;
			}
		
		case 2:
			{
				Locuinta* a = new Casa();
				std::cin >> *a;
				g += {a, "Casa"};
				break;
			}

		case 3:
			std::cout << "\n\n";
			g.afis();
			std::cout << '\n';
			break;

		case 4:
			std::cout << "\n\n";
			g.afisPeCategorii();
			std::cout << '\n';
			break;

		case 5:
			std::cout << "Total: " << g.getTotalChirie() << '\n';
			break;

		case 6:
			{
				int idx;
				std::cout << "Index: ";
				std::cin >> idx;
				try
				{
					g -= idx;
				}
				catch (const std::exception& e)
				{
					std::cout << e.what() << '\n';
				}
			}
			break;
		}
	}
}

void case_menu()
{
	Gestiune<Casa> g;

	Menu m({
		"Adauga casa",
		"Afisare",
		"Afisare (sortare dupa supr. curte)",
		"Total obtinut",
		"Sterge" });

	while (true)
	{
		m.display();
		int opt = m.input();
		switch (opt)
		{
		case 0:
			return; break;

		case 1:
		{
			Casa* a = new Casa();
			std::cin >> *a;
			g += a;
			break;
		}

		case 2:
			std::cout << "\n\n";
			g.afis();
			std::cout << '\n';
			break;

		case 3:
			std::cout << "\n\n";
			g.afisDupaDimensiuneCurte();
			std::cout << '\n';
			break;
 
		case 4:
			std::cout << "\nTotal: " << g.getTotalChirie() << "\n\n";
			break;

		case 5:
		{
			int idx;
			std::cout << "Index: ";
			std::cin >> idx;
			try
			{
				g -= idx;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
		}
		break;
		}
	}
}

void main_menu2()
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