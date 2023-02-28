#pragma once
#include "Osoba.h"
enum Kvalifikacija{kv=1, sss, vkv, vk, vss, mr};
class Uposlenik :public Osoba {
private:
	std::string korisnicko_ime, sifra;
	Kvalifikacija kvalifikacija;
	bool prethodno_iskustvo;
	int plata;
public:
	std::string getKorisnickoIme();
	std::string getSifra();
	Kvalifikacija getKvalifikacija();
	bool getPrethodnoIskustvo();
	int getPlata();
	std::string getKvalifikacijaString();
	std::string getPrethodnoIskustvoString();
	friend std::ostream& operator<<(std::ostream& stream, Uposlenik& u);
	void setKorisnickoIme(const std::string& ime);
	void setSifra(const std::string& sifra);
	void setKvalifikacija(Kvalifikacija k);
	void setPrethodnoIskustvo(bool iskustvo);
	void setPlata(int plata);
};