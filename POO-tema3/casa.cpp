#include "casa.h"

Casa::Casa(const Client& c, float discount, int nrEtaje, const std::vector<float>& suprEtaje, float suprCurte, float pretMp, float pretMpCurte)
	: Locuinta(c, discount, pretMp), m_nrEtaje(nrEtaje), m_suprafataEtaj(suprEtaje),
		m_suprafataCurte(suprCurte), c_pretCurte(pretMpCurte) {}

void Casa::afis(std::ostream& out) const {
	Locuinta::afis(out);
	out << "\nNumar etaje: " << m_nrEtaje << '\n';
	for (int i = 0; i < m_nrEtaje; ++i)
	{
		if (i == 0)
			out << "Parter: ";
		else
			out << "Etajul " << i << ": ";
		
		out << m_suprafataEtaj[i] << " mp\n";
	}
	out << "Suprafata curte: " << m_suprafataCurte << "mp\n";
	out << "Pret chirie: " << getChirie();
}

void Casa::citire(std::istream& in)
{
	Locuinta::citire(in);
	std::cout << "Numar etaje: ";
	in >> m_nrEtaje;
	m_suprafataEtaj.resize(m_nrEtaje);

	for (int i = 0; i < m_nrEtaje; ++i)
	{
		if (i == 0)
		{
			std::cout << "Suprafata parter: ";
		}
		else
		{
			std::cout << "Suprafata etaj " << i << ": ";
		}
		in >> m_suprafataEtaj[i];
	}

	std::cout << "Suprafata curte: ";
	in >> m_suprafataCurte;
}

std::istream& operator>>(std::istream& in, Casa& c)
{
	c.citire(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Casa& c)
{
	c.afis(out);
	return out;
}

float Casa::getChirie() const {
	float total = 0;
	for (float sup : m_suprafataEtaj)
		total += sup * c_pretMetruPatrat;
	total = total - m_discount * total / 100.0f + m_suprafataCurte * c_pretCurte;
	return total;
}