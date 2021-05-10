#pragma once
#include <string>
#include <iostream>

class Client
{
private:
	std::string m_nume;
	std::string m_prenume;
	std::string m_nrTel;
public:
	Client(const std::string & = "Necunoscut", const std::string & = "Necunoscut", const std::string & = "Necunoscut");
	friend std::ostream& operator<<(std::ostream&, const Client&);
	friend std::istream& operator>>(std::istream&, Client&);
};

