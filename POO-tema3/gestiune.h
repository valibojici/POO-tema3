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

	struct Compare 
	{
		bool operator()(const std::pair<T*, std::string> & x, const std::pair<T*, std::string> & y)const
		{
			return x.first->getIndex() < y.first->getIndex();
		}
	};

	std::set < std::pair<T*, std::string>, Compare> m_info;

	int m_nrLoc = 0;
	float m_totalChirie = 0;

public:
	Gestiune() {}

	Gestiune& operator+= (const std::pair<T*, std::string>&);
	Gestiune& operator-= (int);

	float getTotalChirie() const { return m_totalChirie; }
	

	void afis() const; 
	void afisPeCategorii() const;

};

template<class T>
Gestiune<T>& Gestiune<T>::operator+=(const std::pair<T*,std::string>& val)
{
	auto p = val;

	m_nrLoc++;
	p.first->setIndex(m_nrLoc);
	m_totalChirie += p.first->getChirie();

	m_info.insert({ p.first, p.second });
 
	return *this;
}

template<class T>
Gestiune<T>& Gestiune<T>::operator-= (int index)
{
	auto it = std::find_if(m_info.begin(), m_info.end(), [index](const std::pair<T*, std::string>& p) {
		return p.first->getIndex() == index;
	});

	if (it == m_info.end())throw std::invalid_argument("Indexul nu exista");
	
	m_totalChirie -= it->first->getChirie();
	m_info.erase(it);

	return *this;
}

template<class T> 
void Gestiune<T>::afis() const {
	for (const auto& t : m_info)
	{
		std::cout << "Tip locuinta: " << t.second << '\n' << *(t.first) << "\n--------------------------\n\n";
	}
}

template<class T>
void Gestiune<T>::afisPeCategorii() const {
	std::vector<std::pair<T*, std::string> >temp(m_info.begin(), m_info.end());

	std::sort(temp.begin(), temp.end(), [](const auto& x, const auto& y) {
		if(x.second != y.second)
			return x.second < y.second;
		return x.first->getIndex() < y.first->getIndex();
	});

	for (const auto& p : temp)
	{
		std::cout << "Tip locuinta: " << p.second << '\n';
		std::cout << *p.first << "\n--------------------------\n\n";
	}
}
 

template<> class Gestiune<Casa> {
private:
	std::vector<std::pair<Casa*, float> > m_info;
	int m_nrCase = 0;
	int m_nrLoc = 0;

public:
	Gestiune() {}
	Gestiune& operator+= (const std::pair<Casa*, std::string>&);
	void afis() const;
};