#pragma once
#include <iostream>
#include <string>
inline bool jeLiBroj(const std::string& s) {
	char ch;
	for (int i = 0; i < s.length(); i++) {
		ch = s[i];
		if (isdigit(ch) == 0) {
			return false;
		}
	}
	return true;
}
inline void natpis() {
	std::cout << "    *      *******  ******  **    *  *****  *      *      *    " << std::endl;
	std::cout << "   * *     *        **      * *   *  *      *      *     * *   " << std::endl;
	std::cout << "  *****    *  ****  ******  *  *  *  *      *      *    *****  " << std::endl;
	std::cout << " *     *   *     *  **      *   * *  *      *  *   *   *     * " << std::endl;
	std::cout << "*       *  *******  ******  *    **  *****  *   ***   *       *" << std::endl;
}
inline void pocetna() {
	system("CLS");
	natpis();
	std::cout << "=============================================" << std::endl;
	std::cout << " POCETNA STRANICA" << std::endl;
	std::cout << "  1 - LOGIN " << std::endl;
	std::cout << "  0 - IZLAZ" << std::endl;
	std::cout << "=============================================" << std::endl;
}
inline void skriveniMeni() {
	system("CLS");
	natpis();
	std::cout << "=============================================" << std::endl;
	std::cout << " MENI ZA VLASNIKA AGENCIJE" << std::endl;
	std::cout << "  1 - Dodaj uposlenika" << std::endl;
	std::cout << "  2 - Ispis uposlenika" << std::endl;
	std::cout << "  3 - Dodaj automobil" << std::endl;
	std::cout << "  4 - Dodaj motocikl" << std::endl;
	std::cout << "  5 - Ispis svih klijenata" << std::endl;
	std::cout << "  6 - Ispis svih aktivnih iznajmljivanja" << std::endl;
	std::cout << "  7 - Ispis historije iznajmljivanja" << std::endl;
	std::cout << "  8 - Zarada agencije" << std::endl;
	std::cout << "  9 - Ispis svih vozila" << std::endl;
	std::cout << " 10 - Uklanjanje uposlenika" << std::endl;
	std::cout << "  0 - Povratak na pocetnu" << std::endl;
	std::cout << "=============================================" << std::endl;
}
inline void glavniMeni() {
	system("CLS");
	natpis();
	std::cout << "=============================================" << std::endl;
	std::cout << " MENI ZA UPOSLENIKA AGENCIJE" << std::endl;
	std::cout << "  1 - Ispis vozila na osnovu unesenog indeksa" << std::endl;
	std::cout << "  2 - Ispis svih vozila" << std::endl;
	std::cout << "  3 - Evidentiraj iznajmljivanje" << std::endl;
	std::cout << "  4 - Evidentiraj vracanje" << std::endl;
	std::cout << "  5 - Pretraga vozila po ID-u" << std::endl;
	std::cout << "  6 - Ispis iznajmljivanja odrednog klijenta" << std::endl;
	std::cout << "  0 - Povratak na pocetnu" << std::endl;
	std::cout << "=============================================" << std::endl;
}
