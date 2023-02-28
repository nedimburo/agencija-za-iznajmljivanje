#pragma once
#include "Vozilo.h"
#include "Klijent.h"
class Iznajmljivanje {
private:
	Klijent klijent;
	Vozilo* vozilo;
	int broj_dana;
public:
	Iznajmljivanje() = default;
	void setKlijent(Klijent klijent);
	void setVozilo(Vozilo* vozilo);
	void setBrojDana(int br_dana);
	Klijent getKlijent();
	Vozilo* getVozilo();
	int getBrojDana();
	~Iznajmljivanje() = default;
};