#include "Motor.h"
Motor::Motor() {
	this->kubikaza = 500;
	this->tip_goriva = dizel;
	this->snaga = 10;
}
Motor::Motor(const Motor& motor) {
	this->kubikaza = motor.kubikaza;
	this->tip_goriva = motor.tip_goriva;
	this->snaga = motor.snaga;
}
void Motor::setKubikazu() {
	std::cout << "Unesite kubikazu motora(u ccm): ";
	std::cin >> this->kubikaza;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za motor.";
	}
}
void Motor::setTipGoriva() {
	std::shared_ptr<int> x = std::make_shared<int>();
	std::cout << "Odaberite tip goriva motora: \n1 - Dizel\n2 - Benzin\n3 - Plin\n4 - Hibrid"<<std::endl;
	do {
		std::cout << "Odabir: ";
		std::cin >> *x;
		if (( * x < 1 || *x>4) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena opcija ne postoji. Odaberite ponovo opciju." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za motor.";
		}
	} while (*x < 1 || *x>4);
	this->tip_goriva = static_cast<Gorivo> (*x);
}
void Motor::setSnagu() {
	std::cout << "Unesite snagu motora(u kw): ";
	std::cin >> this->snaga;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za motor.";
	}
}
int Motor::getKubikazu() {
	return this->kubikaza;
}
Gorivo Motor::getTipGoriva() {
	return this->tip_goriva;
}
int Motor::getSnagu() {
	return this->snaga;
}
std::string Motor::getTipGorivaString() {
	switch (this->getTipGoriva()) {
	case Gorivo::dizel:
		return "Dizel";
		break;
	case Gorivo::benzin:
		return "Benzin";
		break;
	case Gorivo::plin:
		return "Plin";
		break;
	case Gorivo::hibrid:
		return "Hibrid";
		break;
	default:
		return "Dizel";
		break;
	}
}
std::ostream& operator<<(std::ostream& stream, Motor& m) {
	stream << "Podaci o motoru: " << std::endl;
	stream << "Kubikaza: " << m.getKubikazu() << " ccm." << std::endl;
	stream << "Tip goriva: " << m.getTipGorivaString() <<"." << std::endl;
	stream << "Snaga: " << m.getSnagu() << " kw." << std::endl;
	return stream;
}
std::istream& operator>>(std::istream& stream, Motor& m) {
	std::cout << "Unos podataka za motor: "<<std::endl;
	m.setKubikazu();
	m.setTipGoriva();
	m.setSnagu();
	std::cin.ignore();
	return stream;
}
void Motor::setKubikazu(int kubikaza) {
	this->kubikaza = kubikaza;
}
void Motor::setTipGoriva(Gorivo gorivo) {
	this->tip_goriva = gorivo;
}
void Motor::setSnagu(int snaga) {
	this->snaga = snaga;
}