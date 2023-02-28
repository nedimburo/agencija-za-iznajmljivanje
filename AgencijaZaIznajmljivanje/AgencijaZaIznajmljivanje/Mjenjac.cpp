#include "Mjenjac.h"
Mjenjac::Mjenjac() {
	this->prijenos = manuelni;
	this->broj_brzina = 4;
}
Mjenjac::Mjenjac(const Mjenjac& mjenjac) {
	this->prijenos = mjenjac.prijenos;
	this->broj_brzina = mjenjac.broj_brzina;
}
void Mjenjac::setPrijenos() {
	std::shared_ptr<int> x = std::make_shared<int>();
	std::cout << "Odaberite prijenos mjenjaca: \n1 - Manuelni\n2 - Automatik\n3 - Polu-automatik"<<std::endl;
	do {
		std::cout << "Odabir: ";
		std::cin >> *x;
		if (( * x < 1 || *x>3) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena opcija ne postoji. Odaberite ponovo opciju." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za mjenjac.";
		}
	} while (*x < 1 || *x>3);
	this->prijenos = static_cast<Prijenos>(*x);
}
void Mjenjac::setBrojBrzina() {
	std::shared_ptr<bool> uneseno = std::make_shared<bool>();
	*uneseno = false;
	if (this->getPrijenos() == manuelni) {
		std::cout << "=== Minimalan broj za brzina za manuelni mjenjac je 1, a maksimalni broj je 6 brzina ===" << std::endl;
	}
	else if (this->getPrijenos() == automatik) {
		std::cout << "=== Minimalan broj za brzina za automatski mjenjac je 1, a maksimalni broj je 10 brzina ===" << std::endl;
	}
	else {
		std::cout << "=== Minimalan broj za brzina za polu-automatski mjenjac je 1, a maksimalni broj je 10 brzina ===" << std::endl;
	}
	do {
		std::cout << "Unesite broj brzina mjenjaca (bez rikverca): ";
		std::cin >> this->broj_brzina;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za mjenjac.";
		}
		if (this->getPrijenos() == manuelni && (this->broj_brzina > 0 && this->broj_brzina <7)) {
			*uneseno = true;
		}
		else if(this->getPrijenos() == automatik && (this->broj_brzina > 0 && this->broj_brzina < 11)) {
			*uneseno = true;
		}
		else if (this->getPrijenos() == polu_automatik && (this->broj_brzina > 0 && this->broj_brzina < 11)) {
			*uneseno = true;
		}
		else {
			std::cout << "[GRESKA] Uneseni broj brzina nije iz intervala brzina odgovarajuceg prijenosa. Unesite ponovo broj brzina." << std::endl;
		}
	} while (*uneseno == false);
	
}
Prijenos Mjenjac::getPrijenos() {
	return this->prijenos;
}
int Mjenjac::getBrojBrzina() {
	return this->broj_brzina;
}
std::string Mjenjac::getPrijenosString() {
	switch (this->getPrijenos()) {
	case Prijenos::manuelni:
		return "Manuelni";
		break;
	case Prijenos::automatik:
		return "Automatik";
		break;
	case Prijenos::polu_automatik:
		return "Polu-automatik";
		break;
	default:
		return "Manuelni";
		break;
	}
}
std::ostream& operator<<(std::ostream& stream, Mjenjac& m) {
	stream << "Podaci o mjenjacu: "<<std::endl;
	stream << "Prijenos: " << m.getPrijenosString() << std::endl;
	stream << "Broj brzina: " << m.getBrojBrzina() << "+R." << std::endl;
	return stream;
}
std::istream& operator>>(std::istream& stream, Mjenjac& m) {
	std::cout << "Unos podataka za mjenjac: "<<std::endl;
	m.setPrijenos();
	m.setBrojBrzina();
	std::cin.ignore();
	return stream;
}
void Mjenjac::setPrijenos(Prijenos prijenos) {
	this->prijenos = prijenos;
}
void Mjenjac::setBrojBrzina(int br_brzina) {
	this->broj_brzina = br_brzina;
}