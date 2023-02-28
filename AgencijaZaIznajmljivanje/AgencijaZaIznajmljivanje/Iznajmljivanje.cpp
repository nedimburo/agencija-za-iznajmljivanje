#include "Iznajmljivanje.h"
void Iznajmljivanje::setKlijent(Klijent klijent) {
	this->klijent = klijent;
}
void Iznajmljivanje::setVozilo(Vozilo* vozilo) {
	this->vozilo = vozilo;
}
void Iznajmljivanje::setBrojDana(int br_dana) {
	this->broj_dana = br_dana;
}
Klijent Iznajmljivanje::getKlijent() {
	return this->klijent;
}
Vozilo* Iznajmljivanje::getVozilo() {
	return this->vozilo;
}
int Iznajmljivanje::getBrojDana() {
	return this->broj_dana;
}