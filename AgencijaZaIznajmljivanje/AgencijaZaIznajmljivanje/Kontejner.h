#pragma once
#include "Automobil.h"
#include "Klijent.h"
#include "Motocikl.h"
#include "Uposlenik.h"
#include "Iznajmljivanje.h"
#include <vector>
class Kontejner {
private:
	std::vector<Iznajmljivanje> historija;
	std::vector<Iznajmljivanje> iznajmljivanja;
	std::vector<Vozilo*> sva_vozila;
	std::vector<Klijent> klijenti;
	std::vector<Uposlenik> uposlenici;
public:
	Kontejner() = default;
	inline Vozilo* operator[](int index) {
		return sva_vozila.at(index);
	}
	std::vector<Uposlenik>& getUposlenici();
	std::vector<Vozilo*>& getVozila();
	std::vector<Iznajmljivanje>& getIznajmljivanja();
	std::vector<Klijent>& getKlijenti();
	std::vector<Iznajmljivanje>& getHistoriju();
	void dodajUposlenika();
	void dodajAutomobil();
	void dodajMotocikl();
	void ispisUposlenika();
	void ispisPrekoIndeksa();
	void popuniPostojeceUposlenike();
	void popuniPostojecaVozila();
	void popuniPrethodneKlijente();
	void popuniPrethodnaIznajmljivanja();
	void popuniHistorijuIznajmljivanja();
	void iznajmljivanje();
	void vracanje();
	int izracunZarade();
	void ispisVozilaPoId();
	void ispisIznajmljivanjaKlijenta();
	void operator!();
	void operator++();
	void operator++(int);
	void ukloniUposlenika();
	~Kontejner() = default;
};