#include <iostream>
#include "Kontejner.h"
#include "DodatneFunkcije.h"

int main()
{
    Kontejner kontejner;
    kontejner.popuniPostojeceUposlenike();
    kontejner.popuniPostojecaVozila();
    kontejner.popuniPrethodneKlijente();
    kontejner.popuniPrethodnaIznajmljivanja();
    kontejner.popuniHistorijuIznajmljivanja();
    std::shared_ptr<std::string> izbor=std::make_shared<std::string>();
    do {
        system("CLS");
        pocetna();
        std::cout << "Odabir: ";
        std::cin >> *izbor;
        // pristup skrivenom meniju za vlasnika agencije
        if (*izbor == "vlasnikagencije") {
            std::shared_ptr<std::string> izbor2 = std::make_shared<std::string>();
            do {
                skriveniMeni();
                std::cout << "Odabir: ";
                std::cin >> *izbor2;
                if (*izbor2 == "1") {
                    system("CLS");
                    std::cout << "=============================================" << std::endl;
                    std::cout << " UNOS UPOSLENIKA" << std::endl;
                    std::cout << "=============================================" << std::endl;
                    try {                   
                        kontejner.dodajUposlenika();
                        std::cout << "\nUposlenik je uspjesno unesen." << std::endl;
                    }
                    catch (const char* txt) {
                        std::cout << txt << std::endl;
                    }            
                    system("pause");
                }
                if (*izbor2 == "2") {
                    system("CLS");
                    std::cout << "=============================================" << std::endl;
                    std::cout << " ISPIS SVIH UPOSLENIKA AGENCIJE" << std::endl;
                    std::cout << "=============================================" << std::endl;
                    try {
                        kontejner.ispisUposlenika();
                    }
                    catch (const char* txt) {
                        std::cout << txt << std::endl;
                    }
                    system("pause");
                }
                if (*izbor2 == "3") {
                    system("CLS");
                    std::cin.ignore();
                    std::cout << "=============================================" << std::endl;
                    std::cout << " UNOS AUTOMOBILA" << std::endl;
                    std::cout << "=============================================" << std::endl;
                    try {                       
                        kontejner.dodajAutomobil();
                        std::cout << "\nAutomobil je uspjesno unesen." << std::endl;
                    }
                    catch (const char* txt) {
                        std::cout << txt << std::endl;
                    }
                    system("pause");
                }
                if (*izbor2 == "4") {
                    system("CLS");
                    std::cin.ignore();
                    std::cout << "=============================================" << std::endl;
                    std::cout << " UNOS MOTOCIKLA" << std::endl;
                    std::cout << "=============================================" << std::endl;
                    try {                       
                        kontejner.dodajMotocikl();
                        std::cout << "\nMotocikl je uspjesno unesen." << std::endl;
                    }
                    catch (const char* txt) {
                        std::cout << txt << std::endl;
                    }
                    system("pause");
                }
                if (*izbor2 == "5") {
                    system("CLS");
                    std::cout << "=============================================" << std::endl;
                    std::cout << " ISPIS SVIH KLIJENATA" << std::endl;
                    std::cout << "=============================================" << std::endl;
                    if (kontejner.getKlijenti().size() == 0) {
                        std::cout << "\n[GRESKA] Trenutno nema nijednog klijenta u agenciji." << std::endl;
                    }
                    else {
                        !kontejner;
                    }
                    system("pause");
                }
                if (*izbor2 == "6") {
                    system("CLS");
                    std::cout << "=============================================" << std::endl;
                    std::cout << " ISPIS SVIH AKTIVNIH IZNAJMLJIVANJA" << std::endl;
                    std::cout << "=============================================" << std::endl;
                    if (kontejner.getIznajmljivanja().size() == 0) {
                        std::cout << "\n[GRESKA] Trenutno nema nijedno aktivno iznajmljivanje." << std::endl;
                    }
                    else {
                        ++kontejner;
                    }
                    system("pause");
                }
                if (*izbor2 == "7") {
                    system("CLS");
                    std::cout << "=============================================" << std::endl;
                    std::cout << " ISPIS SVIH IZVRSENIH IZNAJMLJIVANJA" << std::endl;
                    std::cout << "=============================================" << std::endl;
                    if (kontejner.getHistoriju().size() == 0) {
                        std::cout << "\n[GRESKA] Nijedno iznajmljivanje nije izvrseno." << std::endl;
                    }
                    else {
                        kontejner++;
                    }
                    system("pause");
                }
                if (*izbor2 == "8") {
                    system("CLS");
                    std::cout << "===================================================" << std::endl;
                    std::cout << " UKUPNA ZARADA AGENCIJE" << std::endl;
                    std::cout << "===================================================" << std::endl;
                    std::cout << " Ukupan broj iznajmljivanja: " << kontejner.getHistoriju().size() + kontejner.getIznajmljivanja().size()<<std::endl;
                    std::cout << " Ukupni profit: " << kontejner.izracunZarade()<<" KM." << std::endl;
                    std::cout << "===================================================" << std::endl;
                    system("pause");
                }
                if (*izbor2 == "9") {
                    system("CLS");
                    std::cout << "===================================================" << std::endl;
                    std::cout << " ISPIS SVIH VOZILA AGENCIJE" << std::endl;
                    std::cout << "===================================================\n" << std::endl;
                    if (kontejner.getVozila().size() == 0) {
                        std::cout << "[GRESKA] Trenutno nema nijedno vozilo u agenciji." << std::endl;
                    }
                    else {
                        for (int i = 0; i < kontejner.getVozila().size(); i++) {
                            kontejner[i]->ispisVozila(std::cout);
                            std::cout << std::endl;
                            std::cout << "============================================\n" << std::endl;
                        }
                    }
                    system("pause");
                }
                if (*izbor2 == "10") {
                    system("CLS");
                    std::cout << "===================================================" << std::endl;
                    std::cout << " UKLANJANJE UPOSLENIKA AGENCIJE" << std::endl;
                    std::cout << "===================================================\n" << std::endl;
                    try {
                        kontejner.ukloniUposlenika();
                    }
                    catch (const char* txt) {
                        std::cout << txt << std::endl;
                    }
                    system("pause");
                }
                if (*izbor2 == "0") {
                    std::cout << "\nIzasli ste iz menija za vlasnika." << std::endl;                
                    system("pause");
                }
            } while (*izbor2 != "0"); 
        }
        if (*izbor == "1") {
            if (kontejner.getUposlenici().size() == 0) {
                std::cout << "\n[GRESKA] Nema nijednog uposlenika." << std::endl;
                system("pause");
            }
            else {
                // login uposlenika
                system("CLS");
                std::shared_ptr<std::string> login_korisnicko = std::make_shared<std::string>();
                std::shared_ptr<std::string> login_sifra = std::make_shared<std::string>();
                bool pronadjeno_korisnicko=false;
                bool pronadjen=false;
                std::cout << "=============================================" << std::endl;
                std::cout << " LOGIN" << std::endl;
                std::cout << "=============================================\n" << std::endl;
                std::cout << " * Unesite korisnicko ime: ";
                std::cin >> *login_korisnicko;
                for (int i = 0; i < kontejner.getUposlenici().size(); i++) {
                    if (*login_korisnicko == kontejner.getUposlenici()[i].getKorisnickoIme()) {
                        pronadjeno_korisnicko = true;
                    }
                }
                // ispis greske ukoliko korisnicko ime ne postoji
                if (!pronadjeno_korisnicko) {
                    std::cout << "[GRESKA] Uneseno korisnicko ime ne postoji. Probajte ponovo.\n" << std::endl;
                    system("pause");
                }
                for (int i = 0; i < kontejner.getUposlenici().size(); i++) {
                    if (*login_korisnicko == kontejner.getUposlenici()[i].getKorisnickoIme()) {                       
                        std::cout << " * Unesite sifru: ";
                        std::cin >> *login_sifra;
                        if (*login_sifra == kontejner.getUposlenici()[i].getSifra()) {
                            pronadjen = true;
                            break;
                        }
                        else {
                            std::cout << "[GRESKA] Unesena je pogresna sifra. Probajte ponovo.\n" << std::endl;
                            system("pause");
                            break;
                        }
                    }
                }
                // pristup meniju za uposlenike
                if (pronadjen) {
                    std::shared_ptr<std::string> izbor2 = std::make_shared<std::string>();
                    do {
                        glavniMeni();
                        std::cout << "Odabir: ";
                        std::cin >> *izbor2;
                        if (*izbor2 == "0") {
                            std::cout << "\nIzasli ste iz menija za uposlenika." << std::endl;
                            system("pause");
                        }
                        if (*izbor2 == "1") {
                            system("CLS");
                            std::cout << "=============================================" << std::endl;
                            std::cout << " ISPIS PODATAKA VOZILA PREKO INDEKSA" << std::endl;
                            std::cout << "=============================================\n" << std::endl;
                            if (kontejner.getVozila().size() == 0) {
                                std::cout << "[GRESKA] Trenutno nema nijedno vozilo u agenciji." << std::endl;
                            }
                            else {
                                try {
                                    kontejner.ispisPrekoIndeksa();
                                }
                                catch (const char* txt) {
                                    std::cout << txt << std::endl;
                                }
                            }
                            system("pause");
                        }
                        if (*izbor2 == "2") {
                            system("CLS");
                            std::cout << "=============================================" << std::endl;
                            std::cout << " ISPIS SVIH VOZILA AGENCIJE" << std::endl;
                            std::cout << "=============================================\n" << std::endl;
                            if (kontejner.getVozila().size() == 0) {
                                std::cout << "[GRESKA] Trenutno nema nijedno vozilo u agenciji." << std::endl;
                            }
                            else {
                                for (int i = 0; i < kontejner.getVozila().size(); i++) {
                                    kontejner[i]->ispisVozila(std::cout);
                                    std::cout << std::endl;
                                    std::cout << "============================================\n" << std::endl;
                                }
                            }
                            system("pause");
                        }
                        if (*izbor2 == "3") {
                            system("CLS");
                            std::cout << "=============================================" << std::endl;
                            std::cout << " EVIDENCIJA IZNAJMLJIVANJA" << std::endl;
                            std::cout << "=============================================\n" << std::endl;
                            try {
                                kontejner.iznajmljivanje();                            
                            }
                            catch (const char* txt) {
                                std::cout << txt << std::endl;
                            }
                            system("pause");
                        }
                        if (*izbor2 == "4") {
                            system("CLS");
                            std::cout << "=============================================" << std::endl;
                            std::cout << " EVIDENCIJA VRACANJA" << std::endl;
                            std::cout << "=============================================\n" << std::endl;
                            try {
                                kontejner.vracanje();
                            }
                            catch (const char* txt) {
                                std::cout << txt << std::endl;
                            }
                            system("pause");
                        }
                        if (*izbor2 == "5") {
                            system("CLS");
                            std::cout << "=============================================" << std::endl;
                            std::cout << " PRETRAGA VOZILA PO ID-U" << std::endl;
                            std::cout << "=============================================\n" << std::endl;
                            try {
                                kontejner.ispisVozilaPoId();
                            }
                            catch(const char* txt) {
                                std::cout << txt << std::endl;
                            }
                            system("pause");
                        }
                        if (*izbor2 == "6") {
                            system("CLS");
                            std::cout << "=============================================" << std::endl;
                            std::cout << " ISPIS IZNAJMLJIVANJA ODREDENOG KLIJENTA" << std::endl;
                            std::cout << "=============================================\n" << std::endl;
                            try {
                                kontejner.ispisIznajmljivanjaKlijenta();
                            }
                            catch (const char* txt) {
                                std::cout << txt << std::endl;
                            }
                            system("pause");
                        }
                    } while (*izbor2 != "0");
                } 
            }
        }
        if (*izbor == "0") {
            std::cout << "\nIzasli ste iz programa." << std::endl;
        }
    } while (*izbor!="0");
    system("pause");
    return 0;
}