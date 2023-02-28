#include "Motocikl.h"
Tip Motocikl::getTipMotocikla() {
	return this->tip_motocikla;
}
int Motocikl::getBrojTockova() {
	return this->broj_tockova;
}
std::string Motocikl::getTipMotociklaString() {
	switch (this->getTipMotocikla()) {
	case Tip::moped:
		return "Moped";
		break;
	case Tip::skuter:
		return "Skuter";
		break;
	case Tip::kroser:
		return "Kroser";
		break;
	case Tip::enduro:
		return "Enduro";
		break;
	case Tip::quad:
		return "Quad";
		break;
	default:
		return "Moped";
		break;
	}
}
void Motocikl::ispisVozila(std::ostream& stream) {
	stream << "Podaci o motociklu: " << std::endl;
	Vozilo::ispisVozila(std::cout);
	stream << "Tip: " <<this->getTipMotociklaString() << std::endl;
	stream << "Broj tockova: " << this->getBrojTockova() << std::endl;
}
void Motocikl::setTipMotocikla(Tip tip) {
	this->tip_motocikla = tip;
}
void Motocikl::setBrojTockova(int br_tockova) {
	this->broj_tockova = br_tockova;
}