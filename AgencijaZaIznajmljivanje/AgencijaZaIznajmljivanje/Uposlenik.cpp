#include "Uposlenik.h"
std::string Uposlenik::getKorisnickoIme() {
	return this->korisnicko_ime;
}
std::string Uposlenik::getSifra() {
	return this->sifra;
}
Kvalifikacija Uposlenik::getKvalifikacija() {
	return this->kvalifikacija;
}
bool Uposlenik::getPrethodnoIskustvo() {
	return this->prethodno_iskustvo;
}
int Uposlenik::getPlata() {
	return this->plata;
}
std::string Uposlenik::getKvalifikacijaString() {
	switch (this->getKvalifikacija()) {
	case Kvalifikacija::kv:
		return "KV";
		break;
	case Kvalifikacija::sss:
		return "SSS";
		break;
	case Kvalifikacija::vkv:
		return "VKV";
		break;
	case Kvalifikacija::vk:
		return "VK";
		break;
	case Kvalifikacija::vss:
		return "VSS";
		break;
	case Kvalifikacija::mr:
		return "MR";
		break;
	default:
		return "KV";
		break;
	}
}
std::string Uposlenik::getPrethodnoIskustvoString() {
	if (this->getPrethodnoIskustvo()) {
		return "DA";
	}
	else {
		return "NE";
	}
}
std::ostream& operator<<(std::ostream& stream, Uposlenik& u) {
	u.ispisOsobe(stream);
	stream << "Kvalifikacija: " << u.getKvalifikacijaString() << std::endl;
	stream << "Prethodno iskustvo: " << u.getPrethodnoIskustvoString() << std::endl;
	stream << "Plata: " << u.getPlata() << std::endl;
	return stream;
}
void Uposlenik::setKorisnickoIme(const std::string& ime) {
	this->korisnicko_ime = ime;
}
void Uposlenik::setSifra(const std::string& sifra) {
	this->sifra = sifra;
}
void Uposlenik::setKvalifikacija(Kvalifikacija k) {
	this->kvalifikacija = k;
}
void Uposlenik::setPrethodnoIskustvo(bool iskustvo) {
	this->prethodno_iskustvo = iskustvo;
}
void Uposlenik::setPlata(int plata) {
	this->plata = plata;
}