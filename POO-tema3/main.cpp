#include <iostream>
#include <cstdlib>
#include "apartament.h"
#include "casa.h"
#include "gestiune.h"
 
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

Gestiune<Locuinta>* gestLoc;
Gestiune<Casa>* gestCasa;

int main()
{
	main_menu();
}

void main_menu()
{
	Menu m({
		"Gestiune locuinte",
		"Gestiune case",
		"Gestiune restransa locuinte" });

	while (true)
	{
		system("cls");

		m.display();
		int opt = m.input();

		switch (opt)
		{
		case 0:return; break;

		case 1:
		{
			delete gestLoc;
			gestLoc = new Gestiune<Locuinta>;
			locuinte_menu(); break;
		}

		case 2:
		{
			delete gestCasa;
			gestCasa = new Gestiune<Casa>;
			case_menu(); break;
		}

		case 3:
		{
			delete gestLoc;
			gestLoc = new GestiuneRestransa<Locuinta>;
			locuinte_menu(); break;
		}

		}

	}
}

void locuinte_menu()
{
	Menu m({
		"Adauga apartament",
		"Adauga casa",
		"Afisare",
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
				try
				{
					*gestLoc += a;
				}
				catch (const std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n\n";
				}
				
				break;
			}
		
		case 2:
			{
				Locuinta* a = new Casa();
				std::cin >> *a;
				try
				{
					*gestLoc += a;
				}
				catch (const std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n\n";
				}
				break;
			}

		case 3:
			std::cout << "\n\n" << *gestLoc << "\n\n";
			break;

		case 4:
			std::cout << "\n\nTotal: " << gestLoc->getTotalChirie() << "\n\n";
			break;

		case 5:
			{
				int idx;
				std::cout << "Index: ";
				std::cin >> idx;
				try
				{
					*gestLoc -= idx;
				}
				catch (const std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n\n";
				}
			}
			break;
		}
	}
}

void case_menu()
{
	Menu m({
		"Adauga casa",
		"Afisare",
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
			*gestCasa += a;
			break;
		}

		case 2:
			std::cout << "\n\n" << *gestCasa << "\n\n";
			break;
 
		case 3:
			std::cout << "\nTotal: " << gestCasa->getTotalChirie() << "\n\n";
			break;

		case 4:
		{
			int idx;
			std::cout << "Index: ";
			std::cin >> idx;
			try
			{
				*gestCasa -= idx;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << '\n';
			}
			break;
		}
			
		}
	}
}
 