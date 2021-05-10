#include "apartament.h"

Apartament::Apartament(const Client& c, float discount, int etaj,float suprafata, float pretMetruPatrat)
	: Locuinta(c,discount, pretMetruPatrat), m_etaj(etaj), m_suprafataUtila(suprafata) {}

void Apartament::afis(std::ostream& out)const {
	Locuinta::afis(out);
	out << "\nEtaj: " << m_etaj;
	out << "\nSuprafata utila: " << m_suprafataUtila << " mp";
	out << "\nPret chirie: " << getChirie();
}

void Apartament::citire(std::istream& in) 
{
	Locuinta::citire(in);
	std::cout << "Etaj: ";
	in >> m_etaj;
	std::cout << "Suprafata utila: ";
	in >> m_suprafataUtila;
}

std::ostream& operator<<(std::ostream& out, const Apartament& a)
{
	a.afis(out);
	return out;
}

std::istream& operator>>(std::istream& in, Apartament& a)
{
	a.citire(in);
	return in;
}

float Apartament::getChirie() const
{
	float total = c_pretMetruPatrat * m_suprafataUtila;
	return total - m_discount * total / 100.0f;
}