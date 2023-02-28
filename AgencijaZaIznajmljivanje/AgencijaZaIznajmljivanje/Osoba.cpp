#include "Osoba.h"
#include "DodatneFunkcije.h"
Osoba::Osoba() {
	this->jmbg = "00000000000000";
	this->ime = "Nema";
	this->prezime = "Nema";
}
Osoba::Osoba(const Osoba& osoba) {
	this->jmbg = osoba.jmbg;
	this->ime = osoba.ime;
	this->prezime = osoba.prezime;
}
std::string Osoba::getJmbg() {
	return this->jmbg;
}
std::string Osoba::getIme() {
	return this->ime;
}
std::string Osoba::getPrezime() {
	return this->prezime;
}
std::ostream& operator<<(std::ostream& stream, Osoba& o) {
	stream << "JMBG osobe: " << o.getJmbg()<<std::endl;
	stream << "Ime osobe: " << o.getIme()<<std::endl;
	stream << "Prezime osobe: " << o.getPrezime() << std::endl;
	return stream;
}
void Osoba::ispisOsobe(std::ostream& stream) {
	stream << *this;
}
void Osoba::setJmbg(const std::string& jmbg) {
	this->jmbg = jmbg;
}
void Osoba::setIme(const std::string& ime) {
	this->ime = ime;
}
void Osoba::setPrezime(const std::string& prezime) {
	this->prezime = prezime;
}