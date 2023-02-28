#pragma once
#include <iostream>
#include <string>
enum Gorivo{dizel=1, benzin, plin, hibrid};
class Motor {
private:
	int kubikaza;
	Gorivo tip_goriva;
	int snaga;
public:
	Motor();
	Motor(const Motor& motor);
	void setKubikazu();
	void setTipGoriva();
	void setSnagu();
	int getKubikazu();
	Gorivo getTipGoriva();
	int getSnagu();
	std::string getTipGorivaString();
	friend std::ostream& operator<<(std::ostream& stream, Motor& m);
	friend std::istream& operator>>(std::istream& stream, Motor& m);
	//
	void setKubikazu(int kubikaza);
	void setTipGoriva(Gorivo gorivo);
	void setSnagu(int snaga);
	~Motor()=default;
};