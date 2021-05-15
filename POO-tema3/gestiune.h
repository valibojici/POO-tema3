#pragma once
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include "casa.h"
#include "apartament.h"

template<class T>
class Gestiune;

template<class T>
std::ostream& operator<<(std::ostream&, const Gestiune<T>&);


template<class T>
class Gestiune  {
protected:
	std::set <std::pair<int, T*> > m_locuinte;

	int m_idxLoc = 0;
 
	virtual void afis(std::ostream&) const;
	 
public:
	
	virtual Gestiune<T>& operator+= (T*);
	Gestiune<T>& operator-= (int);

	float getTotalChirie() const;
	friend std::ostream& operator<< <>(std::ostream&, const Gestiune<T>&);

	virtual ~Gestiune<T>() {
		for (auto& p : m_locuinte)
		{
			delete p.second;
		}
	}
};

template<class T>
Gestiune<T>& Gestiune<T>::operator+=(T* loc)
{
	m_idxLoc++;
	m_locuinte.insert({ m_idxLoc, loc });
	return *this;
}

template<class T>
Gestiune<T>& Gestiune<T>::operator-=(int index)
{
	auto it = std::find_if(m_locuinte.begin(), m_locuinte.end(), [index](const auto& p) {
		return p.first == index;
		});

	if (it == m_locuinte.end())throw std::invalid_argument("Index invalid");

	m_locuinte.erase(it);

	return *this;
}

template<class T> 
void Gestiune<T>::afis(std::ostream& out) const {
	if (m_locuinte.size() == 0)
	{
		out << "Nu exista locuinte";
		return;
	}

	for (const auto& t : m_locuinte)
	{
		out << std::string(60, '-') << '\n';
		Apartament* a = dynamic_cast<Apartament*>(t.second);
		if (a != nullptr)
		{
			out << "Tip locuinta: Apartament\n";
		}
		else
		{
			Casa* c = dynamic_cast<Casa*> (t.second);
			if (c != nullptr)
			{
				out << "Tip locuinta: Casa\n";
			}
		}
		out << "Index locuinta: " << t.first << '\n';
		out << *(t.second) << "\n" << std::string(60, '-') << "\n\n";
	}
}
 
template<class T>
std::ostream& operator<<(std::ostream& out, const Gestiune<T>& g)
{
	g.afis(out);
	return out;
}

template<class T>
float Gestiune<T>::getTotalChirie() const {
	float total = 0;
	for (const auto& p : m_locuinte)
		total += p.second->getChirie();
	return total;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



template<class T>
class GestiuneRestransa;

template<class T>
std::ostream& operator<< (std::ostream&, const GestiuneRestransa<T>&);

template<class T>
class GestiuneRestransa : public Gestiune<T> {
private:
	static int s_maxLoc;

	void afis(std::ostream&) const;
	
	friend std::ostream& operator<< <>(std::ostream&, const GestiuneRestransa<T>&);
public:
	GestiuneRestransa& operator+= (T*);
 
};

template<class T>
int GestiuneRestransa<T>::s_maxLoc = 5;

template<class T>
GestiuneRestransa<T>& GestiuneRestransa<T>::operator+=(T* val)
{
	if (this->m_locuinte.size() >= s_maxLoc)throw std::length_error("Sunt deja un numar maxim de locuinte stocate");
	Gestiune<T>::operator+=(val);
	return *this;
}

template<class T>
std::ostream& operator<< (std::ostream& out, const GestiuneRestransa<T>& g)
{
	g.afis(out);
	return out;
}

template<class T>
void GestiuneRestransa<T>::afis(std::ostream& out) const
{
	Gestiune<T>::afis(out);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



template<> class Gestiune<Casa>;
template<> std::ostream& operator<<(std::ostream&, const Gestiune<Casa>&);

template<> class Gestiune<Casa> {
private:
	std::set <std::pair<int, Casa*> > m_locuinte;
	int m_idxLoc = 0;
	 
	void afis(std::ostream&) const;
public:
	Gestiune() {}
	Gestiune<Casa>& operator+= (Casa*);
	Gestiune<Casa>& operator-= (int);
	
	friend std::ostream& operator<< <>(std::ostream&, const Gestiune<Casa>&);
	float getTotalChirie() const;

	~Gestiune<Casa>() {
		for (auto& p : m_locuinte)
		{
			delete p.second;
		}
	}
};

template<>
std::ostream& operator<<(std::ostream& out, const Gestiune<Casa>& g)
{
	g.afis(out);
	return out;
}
 
void Gestiune<Casa>::afis(std::ostream& out) const {
	if (m_locuinte.size() == 0)
	{
		std::cout << "Nu exista case";
		return;
	}
	for (const auto& t : m_locuinte)
	{
		out << std::string(60, '-') << '\n';
		out << "Index locuinta: " << t.first << '\n';
		out << *(t.second) << "\n" << std::string(60, '-') << "\n\n";
	}
}

Gestiune<Casa>& Gestiune<Casa>::operator+= (Casa* c)
{
	m_idxLoc++;
	m_locuinte.insert({ m_idxLoc, c });
	return *this;
}

Gestiune<Casa>& Gestiune<Casa>::operator-= (int idx)
{
	auto it = std::find_if(m_locuinte.begin(), m_locuinte.end(), [idx](const auto& p) {
		return p.first == idx;
	});

	if (it == m_locuinte.end())throw std::invalid_argument("Index invalid");

	m_locuinte.erase(it);
 
	return *this;
}


float Gestiune<Casa>::getTotalChirie() const
{
	float total = 0;
	for (const auto& p : m_locuinte)
	{
		total += p.second->getChirie();
	}
	return total;
}