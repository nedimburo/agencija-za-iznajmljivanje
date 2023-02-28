#pragma once
#include "Vozilo.h"
enum Vrsta{hatchback=1, sedan, kabrio, suv, terenac};
class Automobil : public Vozilo {
private:
	Vrsta vrsta_automobila;
	int broj_vrata;
public:
	Automobil() = default;
	Vrsta getVrstaAutomobila();
	int getBrojVrata();
	std::string getVrstaAutomobilaString();
	void ispisVozila(std::ostream& stream) override;
	void setVrstaAutomobila(Vrsta vrsta);
	void setBrojVrata(int br_vrata);
	~Automobil() override = default;
};