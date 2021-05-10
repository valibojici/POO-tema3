#include "locuinta.h"

Locuinta::Locuinta(const Client& client, float discount , float pret)
	: m_client(client), m_discount(discount), m_pretMetruPatrat(pret) {}
 
std::ostream& operator<<(std::ostream& out, const Locuinta& l)
{
	out << "Client:\n" << l.m_client << '\n';
	out << "Pret metru patrat: " << l.m_pretMetruPatrat << " | Discount: " << l.m_discount << "%";
	l.afis(out);
	return out;
}

std::istream& operator>>(std::istream& in, Locuinta& l)
{
	in >> l.m_client;
	std::cout << "Discount: ";
	in >> l.m_discount;
	l.citire(in);
	return in;
}

void 