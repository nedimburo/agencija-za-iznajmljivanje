#pragma once
#include <iostream>
#include <string>
class Osoba {
private:
	std::string jmbg, ime, prezime;
public:
	Osoba();
	Osoba(const Osoba& osoba);
	std::string getJmbg();
	std::string getIme();
	std::string getPrezime();
	void ispisOsobe(std::ostream& stream);
	friend std::ostream& operator<<(std::ostream& stream, Osoba& o);
	void setJmbg(const std::string& jmbg);
	void setIme(const std::string& ime);
	void setPrezime(const std::string& prezime);
	~Osoba() = default;
};