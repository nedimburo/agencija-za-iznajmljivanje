#include "Kontejner.h"
#include "DodatneFunkcije.h"
#include <fstream>
std::vector<Uposlenik>& Kontejner::getUposlenici() {
	return this->uposlenici;
}
std::vector<Vozilo*>& Kontejner::getVozila() {
	return this->sva_vozila;
}
std::vector<Iznajmljivanje>& Kontejner::getIznajmljivanja() {
	return this->iznajmljivanja;
}
std::vector<Klijent>& Kontejner::getKlijenti() {
	return this->klijenti;
}
std::vector<Iznajmljivanje>& Kontejner::getHistoriju() {
	return this->historija;
}

// DODAVANJE UPOSLENIKA

void Kontejner::dodajUposlenika() {
	std::shared_ptr<Uposlenik> u = std::make_shared<Uposlenik>();
	// unos jmbg
	std::string temp_jmbg;
	do {
		std::cout << "Unesite JMBG osobe: ";
		std::cin >> temp_jmbg;
		if (temp_jmbg.length() != 13) {
			std::cout << "[GRESKA] Uneseni JMBG nije odgovarajuce duzine(13 brojeva). Unesite ponovo JMBG." << std::endl;
		}
		else if (!jeLiBroj(temp_jmbg)) {
			std::cout << "[GRESKA] Uneseni JMBG sadrzi karaktere koji nisu brojevi. Unesite ponovo JMBG." << std::endl;
		}
		else {
			for (int i = 0; i < this->getUposlenici().size(); i++) {
				if (temp_jmbg == this->getUposlenici()[i].getJmbg()) {
					throw "[GRESKA] Uneseni JMBG vec postoji. Unesite ponovo podatke za uposlenika.";
				}
			}
			for (int i = 0; i < this->getKlijenti().size(); i++) {
				if (temp_jmbg == this->getKlijenti()[i].getJmbg()) {
					throw "[GRESKA] Uneseni JMBG vec postoji. Unesite ponovo podatke za uposlenika.";
				}
			}
		}
	} while (temp_jmbg.length() != 13 || !jeLiBroj(temp_jmbg));
	u->setJmbg(temp_jmbg);
	// unos ime
	std::string temp_ime;
	std::cout << "Unesite ime osobe: ";
	std::cin >> temp_ime;
	u->setIme(temp_ime);
	// unos prezime
	std::string temp_prezime;
	std::cout << "Unesite prezime osobe: ";
	std::cin >> temp_prezime;
	u->setPrezime(temp_prezime);
	// unos korisnickog imena
	std::string temp_korisnicko;
	std::cout << "Unesite korisnicko ime: ";
	std::cin >> temp_korisnicko;
	for (int i = 0; i < this->getUposlenici().size(); i++) {
		if (temp_korisnicko == this->getUposlenici()[i].getKorisnickoIme()) {
			throw "[GRESKA] Uneseno korisnicko ime vec postoji. Unesite ponovo podatke za uposlenika.";
		}
	}
	u->setKorisnickoIme(temp_korisnicko);
	// unos sifre
	std::string temp_sifra;
	do {
		std::cout << "Unesite sifru(minimalno 6 karaktera): ";
		std::cin >> temp_sifra;
		if (temp_sifra.length() < 6) {
			std::cout << "[GRESKA] Unesena sifra ima manje od 6 karaktera. Unesite ponovo sifru." << std::endl;
		}
	} while (temp_sifra.length() < 6);
	u->setSifra(temp_sifra);
	// unos kvalifikacije
	Kvalifikacija temp_kvalifikacija;
	std::shared_ptr<int> x = std::make_shared<int>();
	std::cout << "Odaberite kvalifikaciju radnika: \n1 - KV \n2 - SSS \n3 - VKV \n4 - VK \n5 - VSS \n6 - MR" << std::endl;
	do {
		std::cout << "Odabir: ";
		std::cin >> *x;
		if ((*x < 1 || *x>6) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena opcija ne postoji. Odaberite ponovo opciju." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za uposlenika.";
		}
	} while (*x < 1 || *x>6);
	temp_kvalifikacija = static_cast<Kvalifikacija> (*x);
	u->setKvalifikacija(temp_kvalifikacija);
	// unos prethodnog iskustva
	bool temp_iskustvo;
	std::cout << "Da li radnik ima prethodno radno iskustvo: \n0 - NE \n1 - DA" << std::endl;
	do {
		std::cout << "Odabir: ";
		std::cin >> *x;
		if ((*x < 0 || *x>1) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena opcija ne postoji. Odaberite ponovo opciju." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za uposlenika.";
		}
	} while (*x < 0 || *x>1);
	temp_iskustvo = static_cast<bool> (*x);
	u->setPrethodnoIskustvo(temp_iskustvo);
	// unos plate
	int temp_plata;
	do {
		std::cout << "Unesite pocetnu platu radnika(minimalna: 596 KM): ";
		std::cin >> temp_plata;
		if ((temp_plata < 596) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena plata je ispod minimalne. Unesite ponovo platu." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za uposlenika.";
		}
	} while (temp_plata < 596);
	if (static_cast<int> (u->getKvalifikacija()) > 3) {
		temp_plata += int(temp_plata * 0.15);
	}
	if (u->getPrethodnoIskustvo()) {
		temp_plata += int(temp_plata * 0.10);
	}
	u->setPlata(temp_plata);
	// spremanje uposlenika u vektor svih uposlenika
	this->uposlenici.push_back(*u);
	std::ofstream unos;
	// spremanje u datoteku
	unos.open("uposlenici.txt", std::ios::app);
	unos << "JMBG: " << u->getJmbg() << std::endl;
	unos << "Ime: " << u->getIme() << std::endl;
	unos << "Prezime: " << u->getPrezime() << std::endl;
	unos << "Korisnicko: " << u->getKorisnickoIme() << std::endl;
	unos << "Sifra: " << u->getSifra() << std::endl;
	unos << "Kvalifikacija: " << u->getKvalifikacijaString() << std::endl;
	unos << "Iskustvo: " << u->getPrethodnoIskustvoString() << std::endl;
	unos << "Plata: " << u->getPlata() << std::endl;
	unos.close();
}

// ISPIS SVIH UPOSLENIKA

void Kontejner::ispisUposlenika() {
	if (this->getUposlenici().size() == 0) {
		throw "\n[GRESKA] Trenutno nema nijedan uposlenik u agenciji.";
	}
	std::cout << std::endl;
	for (int i = 0; i < this->uposlenici.size(); i++) {
		std::cout << i + 1 << ". Uposlenik: " << std::endl;
		std::cout << this->uposlenici[i];
		std::cout << "\n=============================================" << std::endl;
		std::cout << std::endl;
	}
}

// ISPIS PODATAK ZA VOZILO POMOCU UNESENOG INDEKSA

void Kontejner::ispisPrekoIndeksa() {
	std::shared_ptr<int> izbor_indeksa = std::make_shared<int>();
	do {
		std::cout << "Unesite indeks(0 - "<<this->getVozila().size() - 1<<"): ";
		std::cin >> *izbor_indeksa;
		if ((*izbor_indeksa<0 || *izbor_indeksa>this->getVozila().size() - 1) && !std::cin.fail()) {
			std::cout << "[GRESKA] Uneseni indeks ne postoji. Unesite ponovo indeks." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Probajte ponovo.";
		}
	} while (*izbor_indeksa<0 || *izbor_indeksa>this->getVozila().size() - 1);
	std::cout << "=============================================" << std::endl;
	sva_vozila[*izbor_indeksa]->ispisVozila(std::cout);
	std::cout << "=============================================\n" << std::endl;
}

// SPREMANJE VEC POSTOJECIH UPOSLENIKA IZ DATOTEKE

void Kontejner::popuniPostojeceUposlenike() {
	std::shared_ptr<Uposlenik> temp = std::make_shared<Uposlenik>();
	std::ifstream prolaz;
	std::string vrijednost;
	// citanje iz datoteke
	prolaz.open("uposlenici.txt");
	while (!prolaz.eof()) {
		prolaz >> vrijednost;
		if (vrijednost == "JMBG:") {
			prolaz >> vrijednost;
			temp->setJmbg(vrijednost);
		}
		prolaz >> vrijednost;
		if (vrijednost == "Ime:") {
			prolaz >> vrijednost;
			temp->setIme(vrijednost);
		}
		prolaz >> vrijednost;
		if (vrijednost == "Prezime:") {
			prolaz >> vrijednost;
			temp->setPrezime(vrijednost);
		}
		prolaz >> vrijednost;
		if (vrijednost == "Korisnicko:") {
			prolaz >> vrijednost;
			temp->setKorisnickoIme(vrijednost);
		}
		prolaz >> vrijednost;
		if (vrijednost == "Sifra:") {
			prolaz >> vrijednost;
			temp->setSifra(vrijednost);
		}
		prolaz >> vrijednost;
		if (vrijednost == "Kvalifikacija:") {
			prolaz >> vrijednost;
			if (vrijednost == "KV") {
				temp->setKvalifikacija(Kvalifikacija::kv);
			}
			else if (vrijednost == "SSS"){
				temp->setKvalifikacija(Kvalifikacija::sss);
			}
			else if (vrijednost == "VKV") {
				temp->setKvalifikacija(Kvalifikacija::vkv);
			}
			else if (vrijednost == "VK") {
				temp->setKvalifikacija(Kvalifikacija::vk);
			}
			else if (vrijednost == "VSS") {
				temp->setKvalifikacija(Kvalifikacija::vss);
			}
			else {
				temp->setKvalifikacija(Kvalifikacija::mr);
			}
		}
		prolaz >> vrijednost;
		if (vrijednost == "Iskustvo:") {
			prolaz >> vrijednost;
			if (vrijednost == "DA") {
				temp->setPrethodnoIskustvo(true);
			}
			else {
				temp->setPrethodnoIskustvo(false);
			}
		}
		prolaz >> vrijednost;
		if (vrijednost == "Plata:") {
			prolaz >> vrijednost;
			temp->setPlata(std::stoi(vrijednost));
			this->getUposlenici().push_back(*temp);
		}
	}
	prolaz.close();
}

// DODAVANJE AUTOMOBILA

void Kontejner::dodajAutomobil() {
	auto* automobil = new Automobil();
	std::string temp_id;
	do {
		std::cout << "Unesite ID vozila(minimalno 3 broja): ";
		std::cin >> temp_id;
		if (temp_id.length() != 3) {
			std::cout << "[GRESKA] Uneseni ID nije odgovarajuce duzine(3 brojeva). Unesite ponovo ID." << std::endl;
		}
		else if (!jeLiBroj(temp_id)) {
			std::cout << "[GRESKA] Uneseni ID sadrzi karaktere koji nisu brojevi. Unesite ponovo ID." << std::endl;
		}
		else {
			for (int i = 0; i < this->getVozila().size(); i++) {
				if (temp_id == this->getVozila()[i]->getId()) {
					throw "[GRESKA] Uneseni ID vec postoji. Unesite ponovo podatke za vozilo.";
				}
			}
		}
	} while (temp_id.length() != 3 || !jeLiBroj(temp_id));
	automobil->setId(temp_id);
	// 
	std::cin.ignore();
	std::string temp_proizvodjac;
	std::cout << "Unesite naziv proizvodjaca: ";
	std::getline(std::cin, temp_proizvodjac);
	automobil->setProizvodjac(temp_proizvodjac);
	//
	std::string temp_model;
	std::cout<< "Unesite model vozila: ";
	std::getline(std::cin, temp_model);
	automobil->setModel(temp_model);
	//
	int temp_god;
	do {
		std::cout << "Unesite godinu proizvodnje vozila: ";
		std::cin >> temp_god;
		if ((temp_god < 1900 || temp_god>2023) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena godina nije isprava. Unesite ponovo godinu proizvodnje." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za vozilo.";
		}
	} while (temp_god < 1900 || temp_god>2023);
	automobil->setGodinaProizvodnje(temp_god);
	std::cin.ignore();
	// 
	Motor temp_motor;
	std::cin >> temp_motor;
	automobil->setMotor(temp_motor);
	//
	Mjenjac temp_mjenjac;
	std::cin >> temp_mjenjac;
	automobil->setMjenjac(temp_mjenjac);
	//
	int temp_cijena;
	do {
		std::cout << "Unesite cijenu vozila(za iznajmljivanje): ";
		std::cin >> temp_cijena;
		if ((temp_cijena < 1) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena cijena vozila ne smije biti negativna. Unesite ponovo cijenu vozila." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za vozilo.";
		}
	} while (temp_cijena < 1);
	automobil->setCijena(temp_cijena);
	//
	Vrsta temp_vrsta;
	std::shared_ptr<int> x = std::make_shared<int>();
	std::cout << "Odaberite vrstu automobila: \n1 - Hatchback \n2 - Sedan \n3 - Kabrio \n4 - SUV \n5 - Terenac" << std::endl;
	do {
		std::cout << "Odabir: ";
		std::cin >> *x;
		if ((*x < 1 || *x>5) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena opcija ne postoji. Odaberite ponovo opciju." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za automobil.";
		}
	} while (*x < 1 || *x>5);
	temp_vrsta = static_cast<Vrsta>(*x);
	automobil->setVrstaAutomobila(temp_vrsta);
	//
	int temp_brvrata;
	if (automobil->getVrstaAutomobila() == Vrsta::kabrio) {
		temp_brvrata = 2;
		std::cout << "Broj vrata za kabrioleta je 2." << std::endl;
	}
	else {
		std::shared_ptr<int> x = std::make_shared<int>();
		std::cout << "Odaberite broj vrata na automobilu: \n0 - Dvoja vrata \n1 - Cetvora vrata" << std::endl;
		do {
			std::cout << "Odabir: ";
			std::cin >> *x;
			if ((*x < 0 || *x>1) && !std::cin.fail()) {
				std::cout << "[GRESKA] Unesena opcija ne postoji. Odaberite ponovo opciju." << std::endl;
			}
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za automobil.";
			}
		} while (*x < 0 || *x>1);
		switch (*x) {
		case 0:
			temp_brvrata = 2;
			break;
		case 1:
			temp_brvrata = 4;
			break;
		default:
			temp_brvrata = 2;
			break;
		}
	}
	automobil->setBrojVrata(temp_brvrata);
	sva_vozila.push_back(automobil);
	// SPREMANJE AUTOMOBILA U DATOTEKU
	std::ofstream unos;
	unos.open("vozila.txt", std::ios::app);
	unos << "IDAuta: " << automobil->getId() << std::endl;
	unos << "Proizvodjac: " << automobil->getProizvodjac() << std::endl;
	unos << "Model: " << automobil->getModel() << std::endl;
	unos << "GodProizvodnje: " << automobil->getGodinaProizvodnje() << std::endl;
	unos << "Kubikaza: " << automobil->getMotor().getKubikazu() << std::endl;
	unos << "Gorivo: " << automobil->getMotor().getTipGorivaString() << std::endl;
	unos << "Snaga: " << automobil->getMotor().getSnagu() << std::endl;
	unos << "Prijenos: " << automobil->getMjenjac().getPrijenosString() << std::endl;
	unos << "Brzine: " << automobil->getMjenjac().getBrojBrzina() << std::endl;
	unos << "Cijena: " << automobil->getCijena() << std::endl;
	unos << "Vrsta: " << automobil->getVrstaAutomobilaString() << std::endl;
	unos << "BrVrata: " << automobil->getBrojVrata() << std::endl;
	unos.close();
}

// DODAVANJE MOTOCIKLA

void Kontejner::dodajMotocikl() {
	auto* motocikl = new Motocikl();
	std::string temp_id;
	do {
		std::cout << "Unesite ID vozila(minimalno 3 broja): ";
		std::cin >> temp_id;
		if (temp_id.length() != 3) {
			std::cout << "[GRESKA] Uneseni ID nije odgovarajuce duzine(3 brojeva). Unesite ponovo ID." << std::endl;
		}
		else if (!jeLiBroj(temp_id)) {
			std::cout << "[GRESKA] Uneseni ID sadrzi karaktere koji nisu brojevi. Unesite ponovo ID." << std::endl;
		}
		else {
			for (int i = 0; i < this->getVozila().size(); i++) {
				if (temp_id == this->getVozila()[i]->getId()) {
					throw "[GRESKA] Uneseni ID vec postoji. Unesite ponovo podatke za vozilo.";
				}
			}
		}
	} while (temp_id.length() != 3 || !jeLiBroj(temp_id));
	motocikl->setId(temp_id);
	//
	std::cin.ignore();
	std::string temp_proizvodjac;
	std::cout << "Unesite naziv proizvodjaca: ";
	std::getline(std::cin, temp_proizvodjac);
	motocikl->setProizvodjac(temp_proizvodjac);
	//
	std::string temp_model;
	std::cout << "Unesite model vozila: ";
	std::getline(std::cin, temp_model);
	motocikl->setModel(temp_model);
	//
	int temp_god;
	do {
		std::cout << "Unesite godinu proizvodnje vozila: ";
		std::cin >> temp_god;
		if ((temp_god < 1900 || temp_god>2023) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena godina nije isprava. Unesite ponovo godinu proizvodnje." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za vozilo.";
		}
	} while (temp_god < 1900 || temp_god>2023);
	motocikl->setGodinaProizvodnje(temp_god);
	std::cin.ignore();
	// 
	Motor temp_motor;
	std::cin >> temp_motor;
	motocikl->setMotor(temp_motor);
	//
	Mjenjac temp_mjenjac;
	std::cin >> temp_mjenjac;
	motocikl->setMjenjac(temp_mjenjac);
	//
	int temp_cijena;
	do {
		std::cout << "Unesite cijenu vozila(za iznajmljivanje): ";
		std::cin >> temp_cijena;
		if ((temp_cijena < 1) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena cijena vozila ne smije biti negativna. Unesite ponovo cijenu vozila." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za vozilo.";
		}
	} while (temp_cijena < 1);
	motocikl->setCijena(temp_cijena);
	//
	Tip temp_tip;
	std::shared_ptr<int> x = std::make_shared<int>();
	std::cout << "Odaberite tip motocikla: \n1 - Moped \n2 - Skuter \n3 - Kroser \n4 - Enduro \n5 - Quad" << std::endl;
	do {
		std::cout << "Odabir: ";
		std::cin >> *x;
		if ((*x < 1 || *x>5) && !std::cin.fail()) {
			std::cout << "[GRESKA] Unesena opcija ne postoji. Odaberite ponovo opciju." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za motocikl.";
		}
	} while (*x < 1 || *x>5);
	temp_tip = static_cast<Tip>(*x);
	motocikl->setTipMotocikla(temp_tip);
	//
	int temp_brtockova;
	if (motocikl->getTipMotocikla() == Tip::quad) {
		temp_brtockova = 4;
		std::cout << "Broj tockova za Quad je 4." << std::endl;
	}
	else if (motocikl->getTipMotocikla() == Tip::moped || motocikl->getTipMotocikla() == Tip::kroser) {
		temp_brtockova = 2;
		std::cout << "Broj tockova za " << motocikl->getTipMotociklaString() << "a je 2." << std::endl;
	}
	else {
		std::shared_ptr<int> x = std::make_shared<int>();
		std::cout << "Odaberite broj tockova za motocikl: \n 0 - Dva tocka \n 1 - Tri tocka \n 2 - Cetiri tocka" << std::endl;
		do {
			std::cout << "Odabir: ";
			std::cin >> *x;
			std::cin.ignore();
			if ((*x < 0 || *x>2) && !std::cin.fail()) {
				std::cout << "[GRESKA] Unesena opcija ne postoji. Odaberite ponovo opciju." << std::endl;
			}
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				throw "[GRESKA] Pogresan nacin unosenja podatka. Unesite ponovo podatke za motocikl.";
			}
		} while (*x < 0 || *x>2);
		switch (*x) {
		case 0:
			temp_brtockova = 2;
			break;
		case 1:
			temp_brtockova = 3;
			break;
		case 2:
			temp_brtockova = 4;
			break;
		default:
			temp_brtockova = 2;
			break;
		}
	}
	motocikl->setBrojTockova(temp_brtockova);
	sva_vozila.push_back(motocikl);
	// SPREMANJE MOTOCIKLA U DATOTEKU
	std::ofstream unos;
	unos.open("vozila.txt", std::ios::app);
	unos << "IDMoto: " << motocikl->getId() << std::endl;
	unos << "Proizvodjac: " << motocikl->getProizvodjac() << std::endl;
	unos << "Model: " << motocikl->getModel() << std::endl;
	unos << "GodProizvodnje: " << motocikl->getGodinaProizvodnje() << std::endl;
	unos << "Kubikaza: " << motocikl->getMotor().getKubikazu() << std::endl;
	unos << "Gorivo: " << motocikl->getMotor().getTipGorivaString() << std::endl;
	unos << "Snaga: " << motocikl->getMotor().getSnagu() << std::endl;
	unos << "Prijenos: " << motocikl->getMjenjac().getPrijenosString() << std::endl;
	unos << "Brzine: " << motocikl->getMjenjac().getBrojBrzina() << std::endl;
	unos << "Cijena: " << motocikl->getCijena() << std::endl;
	unos << "Tip: " << motocikl->getTipMotociklaString() << std::endl;
	unos << "BrTockova: " << motocikl->getBrojTockova() << std::endl;
	unos.close();
}

// SPREMANJE VEC POSTOJECIH VOZILA IZ DATOTEKE

void Kontejner::popuniPostojecaVozila() {
	std::ifstream prolaz;
	std::string vrijednost, tekst = "";
	prolaz.open("vozila.txt");
	while (!prolaz.eof()) {
		prolaz >> vrijednost;
		// SPREMANJE AUTOMOBILA
		if (vrijednost == "IDAuta:") {
			auto* automobil = new Automobil();
			prolaz >> vrijednost;
			automobil->setId(vrijednost);
			prolaz >> vrijednost;
			if (vrijednost == "Proizvodjac:") {
				prolaz >> vrijednost;
				do {
					tekst = tekst + vrijednost + " ";
					prolaz >> vrijednost;
				} while (vrijednost != "Model:");
				automobil->setProizvodjac(tekst);
				tekst = "";
			}
			if (vrijednost == "Model:") {
				prolaz >> vrijednost;
				do {
					tekst = tekst + vrijednost + " ";
					prolaz >> vrijednost;
				} while (vrijednost != "GodProizvodnje:");
				automobil->setModel(tekst);
				tekst = "";
			}
			if (vrijednost == "GodProizvodnje:") {
				prolaz >> vrijednost;
				automobil->setGodinaProizvodnje(std::stoi(vrijednost));
			}
			// 
			Motor temp;
			prolaz >> vrijednost;
			if (vrijednost == "Kubikaza:") {
				prolaz >> vrijednost;
				temp.setKubikazu(std::stoi(vrijednost));
			}
			prolaz >> vrijednost;
			if (vrijednost == "Gorivo:") {
				prolaz >> vrijednost;
				if (vrijednost == "Dizel") {
					temp.setTipGoriva(Gorivo::dizel);
				}
				else if (vrijednost == "Benzin") {
					temp.setTipGoriva(Gorivo::benzin);
				}
				else if (vrijednost == "Plin") {
					temp.setTipGoriva(Gorivo::plin);
				}
				else {
					automobil->getMotor().setTipGoriva(Gorivo::hibrid);
					temp.setTipGoriva(Gorivo::hibrid);
				}
			}
			prolaz >> vrijednost;
			if (vrijednost == "Snaga:") {
				prolaz >> vrijednost;
				temp.setSnagu(std::stoi(vrijednost));
			}
			automobil->setMotor(temp);
			//
			Mjenjac temp2;
			prolaz >> vrijednost;
			if (vrijednost == "Prijenos:") {
				prolaz >> vrijednost;
				if (vrijednost == "Manuelni") {
					temp2.setPrijenos(Prijenos::manuelni);
				}
				else if (vrijednost == "Automatik") {
					temp2.setPrijenos(Prijenos::automatik);
				}
				else {
					temp2.setPrijenos(Prijenos::polu_automatik);
				}
			}
			prolaz >> vrijednost;
			if (vrijednost == "Brzine:") {
				prolaz >> vrijednost;
				temp2.setBrojBrzina(std::stoi(vrijednost));
			}
			automobil->setMjenjac(temp2);
			//
			prolaz >> vrijednost;
			if (vrijednost == "Cijena:") {
				prolaz >> vrijednost;
				automobil->setCijena(std::stoi(vrijednost));
			}
			prolaz >> vrijednost;
			if (vrijednost == "Vrsta:") {
				prolaz >> vrijednost;
				if (vrijednost == "Hatchback") {
					automobil->setVrstaAutomobila(Vrsta::hatchback);
				}
				else if (vrijednost == "Sedan") {
					automobil->setVrstaAutomobila(Vrsta::sedan);
				}
				else if (vrijednost == "Kabrio") {
					automobil->setVrstaAutomobila(Vrsta::kabrio);
				}
				else if (vrijednost == "SUV") {
					automobil->setVrstaAutomobila(Vrsta::suv);
				}
				else {
					automobil->setVrstaAutomobila(Vrsta::terenac);
				}
			}
			prolaz >> vrijednost;
			if (vrijednost == "BrVrata:") {
				prolaz >> vrijednost;
				automobil->setBrojVrata(std::stoi(vrijednost));
				sva_vozila.push_back(automobil);
			}
		}
		// SPREMANJE MOTOCIKLA
		if (vrijednost == "IDMoto:") {
			auto* motocikl = new Motocikl();
			prolaz >> vrijednost;
			motocikl->setId(vrijednost);
			prolaz >> vrijednost;
			if (vrijednost == "Proizvodjac:") {
				prolaz >> vrijednost;
				do {
					tekst = tekst + vrijednost + " ";
					prolaz >> vrijednost;
				} while (vrijednost != "Model:");
				motocikl->setProizvodjac(tekst);
				tekst = "";
			}
			if (vrijednost == "Model:") {
				prolaz >> vrijednost;
				do {
					tekst = tekst + vrijednost + " ";
					prolaz >> vrijednost;
				} while (vrijednost != "GodProizvodnje:");
				motocikl->setModel(tekst);
				tekst = "";
			}
			if (vrijednost == "GodProizvodnje:") {
				prolaz >> vrijednost;
				motocikl->setGodinaProizvodnje(std::stoi(vrijednost));
			}
			//
			Motor temp;
			prolaz >> vrijednost;
			if (vrijednost == "Kubikaza:") {
				prolaz >> vrijednost;
				temp.setKubikazu(std::stoi(vrijednost));
			}
			prolaz >> vrijednost;
			if (vrijednost == "Gorivo:") {
				prolaz >> vrijednost;
				if (vrijednost == "Dizel") {
					temp.setTipGoriva(Gorivo::dizel);
				}
				else if (vrijednost == "Benzin") {
					temp.setTipGoriva(Gorivo::benzin);
				}
				else if (vrijednost == "Plin") {
					temp.setTipGoriva(Gorivo::plin);
				}
				else {
					temp.setTipGoriva(Gorivo::hibrid);
				}
			}
			prolaz >> vrijednost;
			if (vrijednost == "Snaga:") {
				prolaz >> vrijednost;
				temp.setSnagu(std::stoi(vrijednost));
			}
			motocikl->setMotor(temp);
			//
			Mjenjac temp2;
			prolaz >> vrijednost;
			if (vrijednost == "Prijenos:") {
				prolaz >> vrijednost;
				if (vrijednost == "Manuelni") {
					temp2.setPrijenos(Prijenos::manuelni);
				}
				else if (vrijednost == "Automatik") {
					temp2.setPrijenos(Prijenos::automatik);
				}
				else {
					temp2.setPrijenos(Prijenos::polu_automatik);
				}
			}
			prolaz >> vrijednost;
			if (vrijednost == "Brzine:") {
				prolaz >> vrijednost;
				temp2.setBrojBrzina(std::stoi(vrijednost));
			}
			motocikl->setMjenjac(temp2);
			//
			prolaz >> vrijednost;
			if (vrijednost == "Cijena:") {
				prolaz >> vrijednost;
				motocikl->setCijena(std::stoi(vrijednost));
			}
			prolaz >> vrijednost;
			if (vrijednost == "Tip:") {
				prolaz >> vrijednost;
				if (vrijednost == "Moped") {
					motocikl->setTipMotocikla(Tip::moped);
				}
				else if (vrijednost == "Skuter") {
					motocikl->setTipMotocikla(Tip::skuter);
				}
				else if (vrijednost == "Kroser") {
					motocikl->setTipMotocikla(Tip::kroser);
				}
				else if (vrijednost == "Endure") {
					motocikl->setTipMotocikla(Tip::enduro);
				}
				else {
					motocikl->setTipMotocikla(Tip::quad);
				}
			}
			prolaz >> vrijednost;
			if (vrijednost == "BrTockova:") {
				prolaz >> vrijednost;
				motocikl->setBrojTockova(std::stoi(vrijednost));
				sva_vozila.push_back(motocikl);
			}
		}
	}
	prolaz.close();
}

// SPREMANJE PRETHODNIH KLIJENATA

void Kontejner::popuniPrethodneKlijente() {
	std::shared_ptr<Klijent> temp = std::make_shared<Klijent>();
	std::ifstream prolaz;
	std::string vrijednost, tekst = "";
	prolaz.open("klijenti.txt");
	while (!prolaz.eof()) {
		prolaz >> vrijednost;
		if (vrijednost == "JMBG:") {
			prolaz >> vrijednost;
			temp->setJmbg(vrijednost);
		}
		prolaz >> vrijednost;
		if (vrijednost == "Ime:") {
			prolaz >> vrijednost;
			temp->setIme(vrijednost);
		}
		prolaz >> vrijednost;
		if (vrijednost == "Prezime:") {
			prolaz >> vrijednost;
			temp->setPrezime(vrijednost);
		}
		prolaz >> vrijednost;
		if (vrijednost == "Adresa:") {
			prolaz >> vrijednost;
			do {
				tekst = tekst + vrijednost + " ";
				prolaz >> vrijednost;
			} while (vrijednost != "Telefon:");
			temp->setAdresa(tekst);
			tekst = "";
		}
		if (vrijednost == "Telefon:") {
			prolaz >> vrijednost;
			temp->setTelefon(vrijednost);
			this->getKlijenti().push_back(*temp);
		}
	}
	prolaz.close();
}

// SPREMANJE PRETHODNIH IZNAJMLJIVANJA

void Kontejner::popuniPrethodnaIznajmljivanja() {
	std::shared_ptr<Iznajmljivanje> temp_iznajmljivanje = std::make_shared<Iznajmljivanje>();
	std::shared_ptr<Klijent> temp_klijent = std::make_shared<Klijent>();
	std::shared_ptr<Vozilo*> temp_vozilo = std::make_shared<Vozilo*>();
	std::ifstream prolaz;
	std::string vrijednost, tekst="";
	prolaz.open("iznajmljivanje.txt");
	while (!prolaz.eof()) {
		prolaz >> vrijednost;
		if (vrijednost == "JMBG:") {
			prolaz >> vrijednost;
			for (int i = 0; i < this->getKlijenti().size(); i++) {
				if (vrijednost == this->getKlijenti()[i].getJmbg()) {
					*temp_klijent = this->getKlijenti()[i];
				}
			}
		}
		prolaz >> vrijednost;
		if (vrijednost == "ID:") {
			prolaz >> vrijednost;
			for (int i = 0; i < this->getVozila().size(); i++) {
				if (vrijednost == this->getVozila()[i]->getId()) {
					*temp_vozilo = this->getVozila()[i];
				}
			}
		}
		prolaz >> vrijednost;
		if (vrijednost == "Dana:") {
			prolaz >> vrijednost;
			temp_iznajmljivanje->setBrojDana(std::stoi(vrijednost));
			temp_iznajmljivanje->setKlijent(*temp_klijent);
			temp_iznajmljivanje->setVozilo(*temp_vozilo);
			this->getIznajmljivanja().push_back(*temp_iznajmljivanje);
		}
	}
	prolaz.close();
}

// SPREMANJE HISTORIJE IZNAJMLJIVANJA

void Kontejner::popuniHistorijuIznajmljivanja() {
	std::shared_ptr<Iznajmljivanje> temp_iznajmljivanje = std::make_shared<Iznajmljivanje>();
	std::shared_ptr<Klijent> temp_klijent = std::make_shared<Klijent>();
	std::shared_ptr<Vozilo*> temp_vozilo = std::make_shared<Vozilo*>();
	std::ifstream prolaz;
	std::string vrijednost, tekst = "";
	prolaz.open("historija.txt");
	while (!prolaz.eof()) {
		prolaz >> vrijednost;
		if (vrijednost == "JMBG:") {
			prolaz >> vrijednost;
			for (int i = 0; i < this->getKlijenti().size(); i++) {
				if (vrijednost == this->getKlijenti()[i].getJmbg()) {
					*temp_klijent = this->getKlijenti()[i];
				}
			}
		}
		prolaz >> vrijednost;
		if (vrijednost == "ID:") {
			prolaz >> vrijednost;
			for (int i = 0; i < this->getVozila().size(); i++) {
				if (vrijednost == this->getVozila()[i]->getId()) {
					*temp_vozilo = this->getVozila()[i];
				}
			}
		}
		prolaz >> vrijednost;
		if (vrijednost == "Dana:") {
			prolaz >> vrijednost;
			temp_iznajmljivanje->setBrojDana(std::stoi(vrijednost));
			temp_iznajmljivanje->setKlijent(*temp_klijent);
			temp_iznajmljivanje->setVozilo(*temp_vozilo);
			this->getHistoriju().push_back(*temp_iznajmljivanje);
		}
	}
	prolaz.close();
}

// IZNAJMLJIVANJE

void Kontejner::iznajmljivanje() {
	if (this->getVozila().size() == 0) {
		throw "[GRESKA] Ne moze se izvrsiti iznajmljivanje jer agencija nema nijedno vozilo.";
	}
	// UPDATE: Dodatna provjera ukoliko su sva vozila iznajmljena (6.5.2023)
	if (this->getVozila().size() == this->getIznajmljivanja().size()) {
		throw "[GRESKA] Ne moze se izvrsiti iznajmljivanje jer su sva vozila agencije su trenutno iznajmljena.";
	}
	std::shared_ptr<Iznajmljivanje> temp_iznajmljivanje = std::make_shared<Iznajmljivanje>();
	std::shared_ptr<Klijent> k = std::make_shared<Klijent>();
	// UNOS KLIJENTA
	// unos jmbg
	std::string temp_jmbg;
	do {
		std::cout << "Unesite JMBG osobe: ";
		std::cin >> temp_jmbg;
		if (temp_jmbg.length() != 13) {
			std::cout << "[GRESKA] Uneseni JMBG nije odgovarajuce duzine(13 brojeva). Unesite ponovo JMBG." << std::endl;
		}
		else if (!jeLiBroj(temp_jmbg)) {
			std::cout << "[GRESKA] Uneseni JMBG sadrzi karaktere koji nisu brojevi. Unesite ponovo JMBG." << std::endl;
		}
		else {
			for (int i = 0; i < this->getUposlenici().size(); i++) {
				if (temp_jmbg == this->getUposlenici()[i].getJmbg()) {
					throw "[GRESKA] Uneseni JMBG vec postoji kod uposlenika. Probajte ponovo.";
				}
			}
		}
	} while (temp_jmbg.length() != 13 || !jeLiBroj(temp_jmbg));
	bool postoji = false;
	for (int i = 0; i < this->getKlijenti().size(); i++) {
		if (temp_jmbg == this->getKlijenti()[i].getJmbg()) {
			*k = this->getKlijenti()[i];
			std::cout << "Uneseni JMBG odgovara jednom od prethodnih klijenata. Ostali podaci su prekopirani." << std::endl;
			postoji = true;
			break;
		}
	}
	if (!postoji) {
		k->setJmbg(temp_jmbg);
		// unos ime
		std::string temp_ime;
		std::cout << "Unesite ime osobe: ";
		std::cin >> temp_ime;
		k->setIme(temp_ime);
		// unos prezime
		std::string temp_prezime;
		std::cout << "Unesite prezime osobe: ";
		std::cin >> temp_prezime;
		k->setPrezime(temp_prezime);
		// unos adrese
		std::cin.ignore();
		std::string temp_adresa;
		std::cout << "Unesite adresu klijenta: ";
		std::getline(std::cin, temp_adresa);
		k->setAdresa(temp_adresa);
		// unos telefona
		std::string temp_broj;
		do {
			std::cout << "Unesite broj telefona klijenta(9 karaktera): ";
			std::cin >> temp_broj;
			if (temp_broj.length() != 9) {
				std::cout << "[GRESKA] Uneseni broj telefona ne sadrzi odgovarajuci broj brojeva. Unesite ponovo broj telefona." << std::endl;
			}
			if (!jeLiBroj(temp_broj)) {
				std::cout << "[GRESKA] Uneseni broj telefona sadrzi karaktere koji nisu brojevi. Unesite ponovo broj telefona." << std::endl;
			}
		} while (temp_broj.length() != 9 || !jeLiBroj(temp_broj));
		k->setTelefon(temp_broj);
	}
	// ODABIR AUTA
	std::shared_ptr<Vozilo*> v = std::make_shared<Vozilo*>();
	std::cout << "\nISPIS SVIH VOZILA AGENCIJE" << std::endl;
	// UPDATE: Napravljen ispis za stanje vozila ukoliko je trenutno iznajmljeno (1.3.2023)
	bool temp_provjera = false;
	for (int i = 0; i < this->sva_vozila.size(); i++) {
		std::cout<<"Indeks: "<< i << " | ID: " << sva_vozila[i]->getId() << " | Proizvodjac: " << sva_vozila[i]->getProizvodjac() << " | Model: " << sva_vozila[i]->getModel();
		for (int j = 0; j < this->getIznajmljivanja().size(); j++) {
			if (this->getVozila()[i]->getId() == this->getIznajmljivanja()[j].getVozilo()->getId()) {
				temp_provjera = true;
				break;
			}
		}
		if (temp_provjera) {
			std::cout << " Stanje: ZAUZETO";
			temp_provjera = false;
		}
		else {
			std::cout << " Stanje: SLOBODNO";
		}
		std::cout << std::endl;
	}
	//
	std::shared_ptr<int> odabir = std::make_shared<int>();
	do {
		// UPDATE: Prepravljen ispis (1.3.2023)
		std::cout << "Odaberite indeks vozila za klijenta(0 - " << this->getVozila().size() - 1 << "): ";
		//
		std::cin >> *odabir;
		if ((*odabir<0 || *odabir>this->getVozila().size() - 1) && !std::cin.fail()) {
			std::cout << "[GRESKA] Uneseni indeks ne postoji. Unesite ponovo indeks." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Probajte ponovo.";
		}
	} while (*odabir<0 || *odabir>this->getVozila().size() - 1);
	for (int i = 0; i < this->getIznajmljivanja().size(); i++) {
		if (this->getVozila()[*odabir]->getId() == this->getIznajmljivanja()[i].getVozilo()->getId()) {
			throw "[GRESKA] Odabrano vozilo je vec iznajmljeno. Probajte ponovo.";
		}
	}
	*v = sva_vozila[*odabir];
	// UNOS BROJA DANA
	int temp_brdana;
	do {
		std::cout << "Unesite broj dana iznajmljivanja: ";
		std::cin >> temp_brdana;
		if (temp_brdana < 1 && !std::cin.fail()) {
			std::cout << "[GRESKA] Uneseni broj dana mora biti veci od 0." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Probajte ponovo.";
		}
	} while (temp_brdana < 1);
	temp_iznajmljivanje->setKlijent(*k);
	// UPDATE: Ukoliko se klijent ponavlja, on se nece spremiti u niz kako bi se izbjegle nepotrebne kopije (6.5.2023)
	if (!postoji) {
		this->getKlijenti().push_back(*k);
	}
	temp_iznajmljivanje->setVozilo(*v);
	temp_iznajmljivanje->setBrojDana(temp_brdana);
	this->getIznajmljivanja().push_back(*temp_iznajmljivanje);
	// UNOS U DATOTEKU
	std::ofstream unos;
	std::ofstream unos_klijenti;
	unos.open("iznajmljivanje.txt", std::ios::app);
	unos_klijenti.open("klijenti.txt", std::ios::app);
	unos << "JMBG: " << temp_iznajmljivanje->getKlijent().getJmbg() << std::endl;
	// UPDATE: Ukoliko se ponavlja klijent njegovi podaci se nece zapisivati ponovo u datoteku (6.5.2023)
	// (kako bi se izbjegle nepotrebne kopije)
	if (!postoji) {
		unos_klijenti << "JMBG: " << temp_iznajmljivanje->getKlijent().getJmbg() << std::endl;
		unos_klijenti << "Ime: " << temp_iznajmljivanje->getKlijent().getIme() << std::endl;
		unos_klijenti << "Prezime: " << temp_iznajmljivanje->getKlijent().getPrezime() << std::endl;
		unos_klijenti << "Adresa: " << temp_iznajmljivanje->getKlijent().getAdresa() << std::endl;
		unos_klijenti << "Telefon: " << temp_iznajmljivanje->getKlijent().getTelefon() << std::endl;
	}
	unos << "ID: " << temp_iznajmljivanje->getVozilo()->getId() << std::endl;
	unos << "Dana: " << temp_iznajmljivanje->getBrojDana() << std::endl;
	unos_klijenti.close();
	unos.close();
	std::cout << "\nVozilo je uspjesno iznajmljeno klijentu." << std::endl;
}

// VRACANJE

void Kontejner::vracanje() {
	if (this->getIznajmljivanja().size() == 0) {
		throw "[GRESKA] Trenutno nijedno auto se ne iznajmljuje.";
	}
	std::shared_ptr<int> odabir = std::make_shared<int>();
	++(*this);
	do {
		std::cout << "Odaberite broj iznajmljivanja za koje zelite evidentirati vracanje vozila(1 - "<<this->getIznajmljivanja().size()<<"): ";
		std::cin >> *odabir;
		*odabir = *odabir - 1;
		if ((*odabir<0 || *odabir>this->getIznajmljivanja().size() - 1) && !std::cin.fail()) {
			std::cout << "[GRESKA] Uneseni broj iznajmljivanja ne postoji. Unesite ponovo broj." << std::endl;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			throw "[GRESKA] Pogresan nacin unosenja podatka. Probajte ponovo.";
		}
	} while (*odabir<0 || *odabir>this->getIznajmljivanja().size()-1);
	std::ofstream unos;
	unos.open("historija.txt", std::ios::app);
	unos << "JMBG: " << this->getIznajmljivanja()[*odabir].getKlijent().getJmbg() << std::endl;
	unos << "ID: " << this->getIznajmljivanja()[*odabir].getVozilo()->getId() << std::endl;
	unos << "Dana: " << this->getIznajmljivanja()[*odabir].getBrojDana() << std::endl;
	unos.close();
	this->getHistoriju().push_back(this->getIznajmljivanja()[*odabir]);
	this->getIznajmljivanja().erase(this->getIznajmljivanja().begin() + *odabir);
	std::remove("iznajmljivanje.txt");
	std::ofstream novi_unos;
	unos.open("iznajmljivanje.txt", std::ios::app);
	for (int i = 0; i < this->getIznajmljivanja().size(); i++) {
		unos << "JMBG: " << this->getIznajmljivanja()[i].getKlijent().getJmbg() << std::endl;
		unos << "ID: " << this->getIznajmljivanja()[i].getVozilo()->getId() << std::endl;
		unos << "Dana: " << this->getIznajmljivanja()[i].getBrojDana() << std::endl;
	}
	unos.close();
	std::cout << "\nIznajmljeno vozilo je uspjesno vraceno." << std::endl;
}

// ISPIS SVIH KLIJENATA

void Kontejner::operator!() {
	std::cout << std::endl;
	for (int i = 0; i < this->klijenti.size(); i++) {
		std::cout << i + 1 << ". Klijent: " << std::endl;
		std::cout << this->klijenti[i];
		std::cout << "\n=============================================" << std::endl;
		std::cout << std::endl;
	}
}

// ISPIS SVIH AKTIVNIH IZNAJMLJIVANJA

void Kontejner::operator++() {
	std::cout << std::endl;
	for (int i = 0; i < this->getIznajmljivanja().size(); i++) {
		std::cout << i + 1 << ". Iznajmljivanje: " << std::endl;
		std::cout << "Podaci o klijentu: " << std::endl;
		std::cout <<"JMBG: " << this->getIznajmljivanja()[i].getKlijent().getJmbg();
		std::cout << " | Ime: " << this->getIznajmljivanja()[i].getKlijent().getIme();
		std::cout << " | Prezime: " << this->getIznajmljivanja()[i].getKlijent().getPrezime() << std::endl;
		std::cout << "Podaci o vozilu: " << std::endl;
		std::cout << "ID: " << this->getIznajmljivanja()[i].getVozilo()->getId();
		std::cout << " | Proizvodjac: " << this->getIznajmljivanja()[i].getVozilo()->getProizvodjac();
		std::cout << " | Model: " << this->getIznajmljivanja()[i].getVozilo()->getModel() << std::endl;
		std::cout << "Iznajmljeno na " << this->getIznajmljivanja()[i].getBrojDana() << " dana." << std::endl;
		std::cout << "\n=============================================" << std::endl;
		std::cout << std::endl;
	}
}

// ISPIS SVIH IZVRSENIH IZNAJMLJIVANJA

void Kontejner::operator++(int) {
	std::cout << std::endl;
	for (int i = 0; i < this->getHistoriju().size(); i++) {
		std::cout << i + 1 << ". Iznajmljivanje: " << std::endl;
		std::cout << "Podaci o klijentu: " << std::endl;
		std::cout << "JMBG: " << this->getHistoriju()[i].getKlijent().getJmbg();
		std::cout << " | Ime: " << this->getHistoriju()[i].getKlijent().getIme();
		std::cout << " | Prezime: " << this->getHistoriju()[i].getKlijent().getPrezime() << std::endl;
		std::cout << "Podaci o vozilu: " << std::endl;
		std::cout << "ID: " << this->getHistoriju()[i].getVozilo()->getId();
		std::cout << " | Proizvodjac: " << this->getHistoriju()[i].getVozilo()->getProizvodjac();
		std::cout << " | Model: " << this->getHistoriju()[i].getVozilo()->getModel() << std::endl;
		std::cout << "Bilo iznajmljeno na " << this->getHistoriju()[i].getBrojDana() << " dana." << std::endl;
		std::cout << "\n=============================================" << std::endl;
		std::cout << std::endl;
	}
}

// RACUNANJE PROFITA

int Kontejner::izracunZarade() {
	std::shared_ptr<int> zarada = std::make_shared<int>();
	for (int i = 0; i < this->getHistoriju().size(); i++) {
		*zarada += this->getHistoriju()[i].getBrojDana() * this->getHistoriju()[i].getVozilo()->getCijena();
	}
	for (int i = 0; i < this->getIznajmljivanja().size(); i++) {
		*zarada += this->getIznajmljivanja()[i].getBrojDana() * this->getIznajmljivanja()[i].getVozilo()->getCijena();
	}
	return *zarada;
}

// ISPIS VOZILA PO ID-U

void Kontejner::ispisVozilaPoId() {
	if (this->getVozila().size() == 0) {
		throw "[GRESKA] U agenciji trenutno nema nijedno vozilo.";
	}
	else {
		std::cout << "Dostupni ID-ovi za vozila: " << std::endl;
		for (int i = 0; i < this->getVozila().size(); i++) {
			std::cout << i + 1 << ". Vozilo: " << this->getVozila()[i]->getId() << std::endl;
		}
		std::shared_ptr<std::string> temp_id = std::make_shared<std::string>();
		std::cout << "\nUnesite ID za pretragu: ";
		std::cin >> *temp_id;
		int temp_br = 0;
		for (int i = 0; i < this->getVozila().size(); i++) {
			if (*temp_id == this->getVozila()[i]->getId()) {
				temp_br = 1;
				std::cout << "=============================================" << std::endl;
				this->getVozila()[i]->ispisVozila(std::cout);
				std::cout << "=============================================\n" << std::endl;
			}
		}
		if (temp_br == 0) {
			throw "[GRESKA] Uneseni ID ne postoji ni za jedno vozilo u agenciji.";
		}
	}
}

// ISPIS IZNAJMLJIVANJA ODREDENOG KLIJENTA

void Kontejner::ispisIznajmljivanjaKlijenta() {
	if (this->getKlijenti().size() == 0) {
		throw "[GRESKA] Trenutno nema nijednog klijenta u agenciji.";
	}
	if (this->getIznajmljivanja().size() == 0 && this->getHistoriju().size() == 0) {
		throw "[GRESKA] Nema nijedno registrovano iznajmljivanje u agenciji.";
	}
	std::shared_ptr<std::string> temp_ime = std::make_shared<std::string>();
	std::shared_ptr<std::string> temp_prezime = std::make_shared<std::string>();
	std::cout << " * Unesite ime za pretragu: ";
	std::cin >> *temp_ime;
	std::cout << " * Unesite prezime za pretragu: ";
	std::cin >> *temp_prezime;
	bool pronadjen_klijent = false;
	for (int i = 0; i < this->getKlijenti().size(); i++) {
		if (*temp_ime == this->getKlijenti()[i].getIme() && *temp_prezime == this->getKlijenti()[i].getPrezime()) {
			pronadjen_klijent = true;
		}
	}
	if (!pronadjen_klijent) {
		throw "[GRESKA] Uneseni podaci za klijenta ne postoje. Probajte ponovo.";
	}
	else {
		bool ima = false;
		int temp_br = 1;
		std::cout << "\nIspis aktivnih iznajmljivanja:" << std::endl;
		for (int i = 0; i < this->getIznajmljivanja().size(); i++) {
			if (*temp_ime == this->getIznajmljivanja()[i].getKlijent().getIme() && *temp_prezime == this->getIznajmljivanja()[i].getKlijent().getPrezime()) {
				std::cout << temp_br << ". Iznajmljivanje: " << std::endl;
				std::cout << "ID: " << this->getIznajmljivanja()[i].getVozilo()->getId() << " | Proizvodjac: "
					<< this->getIznajmljivanja()[i].getVozilo()->getProizvodjac()
					<< " | Model: " << this->getIznajmljivanja()[i].getVozilo()->getModel() << " | Broj dana: " << this->getIznajmljivanja()[i].getBrojDana() << std::endl;
				temp_br += 1;
				ima = true;
			}
		}
		if (!ima) {
			std::cout << "Klijent nema aktivnih iznajmljivanja." << std::endl;
		}
		ima = false;
		temp_br = 1;
		std::cout << "\nIspis izvrsenih iznajmljivanja:" << std::endl;
		for (int i = 0; i < this->getHistoriju().size(); i++) {
			if (*temp_ime == this->getHistoriju()[i].getKlijent().getIme() && *temp_prezime == this->getHistoriju()[i].getKlijent().getPrezime()) {
				std::cout << temp_br << ". Iznajmljivanje: " << std::endl;
				std::cout << "ID: " << this->getHistoriju()[i].getVozilo()->getId() << " | Proizvodjac: "
					<< this->getHistoriju()[i].getVozilo()->getProizvodjac()
					<< " | Model: " << this->getHistoriju()[i].getVozilo()->getModel() << " | Broj dana: " << this->getHistoriju()[i].getBrojDana() << std::endl;
				temp_br += 1;
				ima = true;
			}
		}
		if (!ima) {
			std::cout << "Klijent nema izvrsenih iznajmljivanja." << std::endl;
		}
	}
	std::cout << std::endl;
}

// UKLANJANJE UPOSLENIKA

void Kontejner::ukloniUposlenika() {
	if (this->getUposlenici().size() == 0) {
		throw "[GRESKA] Trenutno nema uposlenika u agenciji.";
	}
	else {
		std::cout << "Lista uposlenika: " << std::endl;
		for (int i = 0; i < this->getUposlenici().size(); i++) {
			std::cout << "Indeks uposlenika: " << i + 1<<std::endl;
			std::cout << "JMBG: " << this->getUposlenici()[i].getJmbg() << " | Ime: " 
				<< this->getUposlenici()[i].getIme() << " | Prezime: " << this->getUposlenici()[i].getPrezime() << std::endl;
		}
		std::cout << std::endl;
		std::shared_ptr<int> odabir = std::make_shared<int>();
		do {
			std::cout << "Odaberite indeks radnika kojeg zelite ukloniti (1 - " << this->getUposlenici().size() << "): ";
			std::cin >> *odabir;
			std::cin.ignore();
			if ((*odabir<1 || *odabir>this->getUposlenici().size()) && !std::cin.fail()) {
				std::cout << "[GRESKA] Uneseni indeks je ne postoji. Odaberite ponovo indeks uposlenika." << std::endl;
			}
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				throw "[GRESKA] Pogresan nacin unosenja podatka. Probajte ponovo.";
			}
		} while (*odabir<1 || *odabir>this->getUposlenici().size());
		*odabir = *odabir - 1;
		this->getUposlenici().erase(this->getUposlenici().begin() + *odabir);
		// brisanje postojeceg fajla uposlenika 
		std::remove("uposlenici.txt");
		// kreiranje novog fajla za uposlenike
		std::ofstream unos;
		unos.open("uposlenici.txt", std::ios::app);
		for (int i = 0; i < this->getUposlenici().size(); i++) {
			unos << "JMBG: " << this->getUposlenici()[i].getJmbg() << std::endl;
			unos << "Ime: " << this->getUposlenici()[i].getIme() << std::endl;
			unos << "Prezime: " << this->getUposlenici()[i].getPrezime() << std::endl;
			unos << "Korisnicko: " << this->getUposlenici()[i].getKorisnickoIme() << std::endl;
			unos << "Sifra: " << this->getUposlenici()[i].getSifra() << std::endl;
			unos << "Kvalifikacija: " << this->getUposlenici()[i].getKvalifikacijaString() << std::endl;
			unos << "Iskustvo: " << this->getUposlenici()[i].getPrethodnoIskustvoString() << std::endl;
			unos << "Plata: " << this->getUposlenici()[i].getPlata() << std::endl;
		}
		unos.close();
		std::cout << "\nUposlenik je uspjesno uklonjen iz agencije." << std::endl;
	}
}
