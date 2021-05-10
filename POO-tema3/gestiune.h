#pragma once
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include "casa.h"
#include "apartament.h"

template<class T>
class Gestiune  {
private:
	std::set<std::pair<T*, std::string> > m_info;

	int m_nrLoc = 0;

public:
	Gestiune() {}

	Gestiune& operator+= (T*);

	void main_menu();

	void afis() const; 

};

template<class T>
Gestiune<T>& Gestiune<T>::operator+=(T* val)
{
	T* c = dynamic_cast<Casa*>(val);
	if (c != nullptr)
	{
		m_nrLoc++;
		c->setIndex(m_nrLoc);

		m_info.insert({ c, "Casa" });
	}
	else
	{
		c = dynamic_cast<Apartament*>(val);
		if (c != nullptr)
		{
			m_nrLoc++;
			c->setIndex(m_nrLoc);

			m_info.insert({ c, "Apartament" });
		}
		else {
			throw std::invalid_argument("invalid argument");
		}
	}
	return *this;
}

template<class T> 
void Gestiune<T>::afis() const {
	for (const auto& t : m_info)
	{
		std::cout << "Tip locuinta: " << t.second << '\n' << *(t.first) << "\n---------------------\n\n";
	}
}


template<class T>
void Gestiune<T>::main_menu()
{
	std::string input;
	int option;
	while (true)
	{
		std::cout << "1. Adauga apartament\n";
		std::cout << "2. Adauga casa\n";
		std::cout << "3. Afisare\n";
		std::cout << "4. Afisare (sortare pe tipuri)\n";
		std::cout << "5. Total obtinut\n";
		std::cout << "0. Exit\n";

		bool ok = false;
		while (!ok)
		{
			std::cin >> input;
			ok = true;
			try
			{
				option = std::stoi(input);
				if (option < 0 || option > 5)throw std::invalid_argument("optiunea nu e valida");
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
			(*this) += a;
		}
		else if (option == 2)
		{
			Casa* a = new Casa();
			std::cin >> *a;
			(*this) += a;
		}
		else if (option == 3)
		{
			std::cout << "\n";
			this->afis();
			std::cout << "\n";
		}
		else if (option == 4)
		{
			std::vector<std::pair<T*, std::string> >vals(m_info.begin(), m_info.end());

			std::sort(vals.begin(), vals.end(), [](const auto& val1, const auto& val2) {
				if(val1.second != val2.second)
					return  val1.second < val2.second;
				return val1.first->getIndex() < val2.first->getIndex();
			});

			for (const auto& p : vals)
			{
				std::cout << "Tip locuinta: " << p.second << '\n' << *(p.first) << "\n---------------------\n\n";
			}
		}
		else if(option == 5)
		{
			float total = 0;
			for (const auto& p : m_info)
			{
				total += (p.first)->getChirie();
			}
			std::cout << "TOTAL: " << total << '\n';
		}
		else {
			return;
		}

		std::cout << '\n';
	}
}