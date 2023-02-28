#include "Vozilo.h"
std::string Vozilo::getId() {
	return this->id;
}
std::string Vozilo::getProizvodjac() {
	return this->proizvodjac;
}
std::string Vozilo::getModel() {
	return this->model;
}
int Vozilo::getGodinaProizvodnje() {
	return this->godina_proizvodnje;
}
Motor Vozilo::getMotor() {
	return this->motor;
}
Mjenjac Vozilo::getMjenjac() {
	return this->mjenjac;
}
int Vozilo::getCijena() {
	return this->cijena;
}
void Vozilo::ispisVozila(std::ostream& stream) {
	stream << "ID: " << this->getId() << std::endl;
	stream << "Proizvodjac: " << this->getProizvodjac() << std::endl;
	stream << "Model: " << this->getModel() << std::endl;
	stream << "Godina proizvodnje: " << this->getGodinaProizvodnje() << std::endl;
	stream << this->motor;
	stream << this->mjenjac;
	stream << "Cijena: " << this->getCijena() << std::endl;
}
void Vozilo::setProizvodjac(const std::string& proizvodjac) {
	this->proizvodjac = proizvodjac;
}
void Vozilo::setModel(const std::string& model) {
	this->model = model;
}
void Vozilo::setGodinaProizvodnje(int god_proizvodnje) {
	this->godina_proizvodnje = god_proizvodnje;
}
void Vozilo::setMotor(Motor motor) {
	this->motor = motor;
}
void Vozilo::setMjenjac(Mjenjac mjenjac) {
	this->mjenjac = mjenjac;
}
void Vozilo::setCijena(int cijena) {
	this->cijena = cijena;
}
void Vozilo::setId(const std::string& id) {
	this->id = id;
}