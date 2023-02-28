#include "Automobil.h"
Vrsta Automobil::getVrstaAutomobila() {
	return this->vrsta_automobila;
}
int Automobil::getBrojVrata() {
	return this->broj_vrata;
}
std::string Automobil::getVrstaAutomobilaString() {
	switch (this->getVrstaAutomobila()) {
	case Vrsta::hatchback:
		return "Hatchback";
		break;
	case Vrsta::sedan:
		return "Sedan";
		break;
	case Vrsta::kabrio:
		return "Kabrio";
		break;
	case Vrsta::suv:
		return "SUV";
		break;
	case Vrsta::terenac:
		return "Terenac";
		break;
	default:
		return "Hatchback";
		break;
	}
}
void Automobil::ispisVozila(std::ostream& stream) {
	stream << "Podaci o automobilu: " << std::endl;
	Vozilo::ispisVozila(std::cout);
	stream << "Vrsta: " <<this->getVrstaAutomobilaString() << std::endl;
	stream << "Broj vrata: " << this->getBrojVrata() << std::endl;
}
void Automobil::setVrstaAutomobila(Vrsta vrsta) {
	this->vrsta_automobila = vrsta;
}
void Automobil::setBrojVrata(int br_vrata) {
	this->broj_vrata = br_vrata;
}