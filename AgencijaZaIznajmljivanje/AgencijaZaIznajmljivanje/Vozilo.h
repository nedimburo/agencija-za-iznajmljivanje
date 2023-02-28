#pragma once
#include "Motor.h"
#include "Mjenjac.h"
class Vozilo {
private:
	std::string id, proizvodjac, model;
	int godina_proizvodnje;
	Motor motor;
	Mjenjac mjenjac;
	int cijena;
public:
	Vozilo() = default;
	std::string getId();
	std::string getProizvodjac();
	std::string getModel();
	int getGodinaProizvodnje();
	Motor getMotor();
	Mjenjac getMjenjac();
	int getCijena();
	virtual void ispisVozila(std::ostream& stream);
	void setId(const std::string& id);
	void setProizvodjac(const std::string& proizvodjac);
	void setModel(const std::string& model);
	void setGodinaProizvodnje(int god_proizvodnje);
	void setMotor(Motor motor);
	void setMjenjac(Mjenjac mjenjac);
	void setCijena(int cijena);
	virtual ~Vozilo() = default;
};