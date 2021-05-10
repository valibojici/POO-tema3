#pragma once
#include "locuinta.h"

class Client;

class Apartament : public Locuinta
{
private:
	int m_etaj;
	float m_suprafataUtila;

protected:
	void afis(std::ostream&) const;
	void citire(std::istream&);

public:
	Apartament(){}
	Apartament(const Client&, float, int,float, float = 20);

	friend std::ostream& operator<<(std::ostream&, const Apartament&);
	friend std::istream& operator>>(std::istream&, Apartament&);
	float getChirie() const;
};

