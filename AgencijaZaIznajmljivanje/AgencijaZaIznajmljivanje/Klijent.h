#pragma once
#include "Osoba.h"
class Klijent :public Osoba {
private:
	std::string adresa, telefon;
public:
	std::string getAdresa();
	std::string getTelefon();
	friend std::ostream& operator<<(std::ostream& stream, Klijent& k);
	void setAdresa(const std::string& adresa);
	void setTelefon(const std::string& telefon);
};