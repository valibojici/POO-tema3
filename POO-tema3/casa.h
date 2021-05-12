#pragma once
#include "locuinta.h"
#include <vector>

class Client;

class Casa : public Locuinta
{
private:
	int m_nrEtaje = 0;
	float m_suprafataCurte = 0;
	float m_pretCurte = 40;
	std::vector<float> m_suprafataEtaj;

protected:
	void afis(std::ostream&) const;
	void citire(std::istream&);

public:
	Casa() {}
	Casa(const Client&, float, int,const std::vector<float>&, float, float = 20, float = 40);

	friend std::ostream& operator<<(std::ostream&, const Casa&);
	friend std::istream& operator>>(std::istream&, Casa&);
	float getChirie() const;
	void setPretMpCurte(float pret) { m_pretCurte = pret; }
};

