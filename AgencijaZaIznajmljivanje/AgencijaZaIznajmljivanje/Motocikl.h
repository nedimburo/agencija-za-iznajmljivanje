#pragma once
#include "Vozilo.h"
enum Tip{moped=1, skuter, kroser, enduro, quad};
class Motocikl : public Vozilo {
private:
	Tip tip_motocikla;
	int broj_tockova;
public:
	Motocikl() = default;
	Tip getTipMotocikla();
	int getBrojTockova();
	std::string getTipMotociklaString();
	void ispisVozila(std::ostream& stream) override;
	//
	void setTipMotocikla(Tip tip);
	void setBrojTockova(int br_tockova);
	~Motocikl() override = default;
};