#include "Klijent.h"
#include "DodatneFunkcije.h"
std::string Klijent::getAdresa() {
	return this->adresa;
}
std::string Klijent::getTelefon() {
	return this->telefon;
}
std::ostream& operator<<(std::ostream& stream, Klijent& k) {
	k.ispisOsobe(stream);
	stream << "Adresa: " << k.getAdresa() << std::endl;
	stream << "Telefon: " << k.getTelefon()<<std::endl;
	return stream;
}
void Klijent::setAdresa(const std::string& adresa) {
	this->adresa = adresa;
}
void Klijent::setTelefon(const std::string& telefon) {
	this->telefon = telefon;
}