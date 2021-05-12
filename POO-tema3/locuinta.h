#pragma once
#include "client.h"

class Locuinta
{
protected:
	Client m_client;
	float m_discount = 0;
	float m_pretMetruPatrat = 20;
 

	virtual void afis(std::ostream&) const;
	virtual void citire(std::istream&);
public:
	Locuinta() {}

	Locuinta(const Client&, float, float=20);
	
	friend std::ostream& operator<<(std::ostream&, const Locuinta&);
	friend std::istream& operator>>(std::istream&, Locuinta&);
	virtual float getChirie() const = 0;

	void setPretMp(float pret) { m_pretMetruPatrat = pret; }
};

