#include <iostream>
using namespace std;

char *crt = "\n----------------------------------------\n";

void dealociraj(char *& tekst) {
	delete[] tekst;
	tekst = nullptr;
}

int prikaziMeni() {
	int izbor = 0;
	do {
		cout << crt << "\t::MENI::" << crt;
		cout << "1. Unos teksta" << endl;
		cout << "2. Dodavanje teksta" << endl;
		cout << "3. Pretraga teksta" << endl;
		cout << "4. Tekst info" << endl;
		cout << "5. Kraj" << crt;
		cout << "Vas izbor: ";
		cin >> izbor;
	} while (izbor < 1 || izbor>5);
	cin.ignore();
	system("cls");
	return izbor;
}

char *unosNovogTeksta() {
	const int max = 1000;
	char temp[max];
	cout << crt << "\t::UNOS TEKSTA::" << crt;
	cout << "Unesite tekst: ";
	cin.getline(temp, max);
	int brojKaraktera = strlen(temp) + 1;
	char*niz = new char[brojKaraktera];
	strcpy_s(niz, brojKaraktera, temp);
	return niz;
}

char *dodavanjeNovogTeksta(char*tekst) {
	const int max = 1000;
	char temp[max];
	cout << crt << "\t::DODAVANJE TEKSTA::" << crt;
	cout << "Unesite tekst: ";
	cin.getline(temp, max);
	int ukupnaVelicina = strlen(temp) + strlen(tekst) + 2;
	char*niz = new char[ukupnaVelicina];
	strcpy_s(niz, ukupnaVelicina, tekst);
	strcat_s(niz, ukupnaVelicina, " ");
	strcat_s(niz, ukupnaVelicina, temp);
	return niz;
}

void pretragaTeksta(char*tekst) {
	const int max = 50;
	char temp[max];
	cout << crt << "\t::PRETRAGA TEKSTA::" << crt;
	cout << "Unesite tekst: ";
	cin.getline(temp, max);
	char *pok = strstr(tekst, temp);
	if (pok != nullptr)
		cout << "Sadrzaj \"" << temp << "\" je pronadjen, a nakon njega se nalazi sadrzaj \"" << pok << "\"." << endl;
	else cout << "Trazeni sadrzaj \"" << temp << "\" nije pronadjen." << endl;
}

void tekstInfo(char * tekst) {
	cout << crt << "\t::TEKST INFO::" << crt;
	int velikaSlova = 0, malaSlova = 0, prazanProstor = 0, broj = 0, znak = 0;
	for (size_t i = 0; i < strlen(tekst); i++)
	{
		if (isupper(tekst[i]))
			velikaSlova++;
		else if (islower(tekst[i]))
			malaSlova++;
		else if (ispunct(tekst[i]))
			znak++;
		else if (isspace(tekst[i]))
			prazanProstor++;
		else if (isdigit(tekst[i]))
			broj++;
	}
	cout << "Velikih slova: " << velikaSlova << endl;
	cout << "Malih slova: " << malaSlova << endl;
	cout << "Razmaka: " << prazanProstor << endl;
	cout << "Brojeva: " << broj << endl;
	cout << "Interpunkcijskih znakova: " << znak << endl;
}

void main() {
	char *tekst = nullptr;
	int izbor = 0;

	do {
		izbor = prikaziMeni();
		switch (izbor)
		{
		case 1: tekst = unosNovogTeksta(); break;
		case 2: tekst = dodavanjeNovogTeksta(tekst); break;
		case 3: pretragaTeksta(tekst); break;
		case 4: tekstInfo(tekst); break;
		}
		cout << crt << "\t::TEKST::" << endl << tekst << crt;
	} while (izbor != 5);
	delete[] tekst;
	tekst = nullptr;

	system("pause>0");
}
