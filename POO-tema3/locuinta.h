#pragma once
#include "client.h"

class Locuinta
{
private:
	Client m_client;
	float m_discount;
	const float m_pretMetruPatrat = 20;
public:
	Locuinta(const Client&, float, float=20);
	virtual void afis(std::ostream&) const;
	virtual void citire(std::istream&);
	friend std::ostream& operator<<(std::ostream&, const Locuinta&);
	friend std::istream& operator>>(std::istream&, Locuinta&);
	virtual float getChirie() const = 0;
};

