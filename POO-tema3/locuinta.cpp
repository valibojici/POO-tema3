#include "locuinta.h"

Locuinta::Locuinta(const Client& client, float discount , float pret)
	: m_client(client), m_discount(discount), c_pretMetruPatrat(pret) {}
 
std::ostream& operator<<(std::ostream& out, const Locuinta& l)
{
	l.afis(out);
	return out;
}

std::istream& operator>>(std::istream& in, Locuinta& l)
{
	l.citire(in);
	return in;
}

void Locuinta::afis(std::ostream& out) const
{
	out << "Index locuinta: " << m_index << '\n';
	out << "Date client -> " << m_client << '\n';
	out << "Pret metru patrat: " << c_pretMetruPatrat << " | Discount: " << m_discount << "%";
}

void Locuinta::citire(std::istream& in) 
{
	in >> m_client;
	std::cout << "Discount: ";
	in >> m_discount;
}