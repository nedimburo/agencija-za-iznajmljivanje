#pragma once
#include <iostream>
#include <string>
enum Prijenos{manuelni=1, automatik, polu_automatik};
class Mjenjac {
private:
	Prijenos prijenos;
	int broj_brzina;
public:
	Mjenjac();
	Mjenjac(const Mjenjac& mjenjac);
	void setPrijenos();
	void setBrojBrzina();
	Prijenos getPrijenos();
	int getBrojBrzina();
	std::string getPrijenosString();
	friend std::ostream& operator<<(std::ostream& stream, Mjenjac& m);
	friend std::istream& operator>>(std::istream& stream, Mjenjac& m);
	void setPrijenos(Prijenos prijenos);
	void setBrojBrzina(int br_brzina);
	~Mjenjac() = default;
};