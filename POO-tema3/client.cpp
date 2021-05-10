#include "client.h"

Client::Client(const std::string& nume, const std::string& prenume, const std::string& nrTel)
	: m_nume(nume), m_prenume(prenume), m_nrTel(nrTel) {}

std::ostream& operator<<(std::ostream& out, const Client& c)
{
	out << "Nume: " << c.m_nume << " | Prenume: " << c.m_prenume << " | Nr. telefon: " << c.m_nrTel;
	return out;
}

std::istream& operator>>(std::istream& in, Client& c)
{
	std::cout << "Nume client: ";
	in >> c.m_nume;
	std::cout << "Prenume client: ";
	in >> c.m_prenume;
	std::cout << "Nr. telefon client: ";
	in >> c.m_nrTel;
 
	return in;
}
