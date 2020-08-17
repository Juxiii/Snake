//Funkcje u¿ywane przez main()

#include "pch.h"
#include "main.h"

using namespace std;

//Wprowadzanie liczb ze strumienia
int ustaw_dane(string tekst)
{
	string wejscie;
	int wejscie_liczba;
	cout << tekst;
	cin >> wejscie;

	while (cin.fail() || cin.eof() || wejscie.find_first_not_of("0123456789") != string::npos) {

		cout << "Niepoprawne dane! Oczekiwano liczby" << endl;

		if (wejscie.find_first_not_of("0123456789") == string::npos) {
			cin.clear();
			cin.ignore(numeric_limits < streamsize >::max(), '\n');
		}
		cout << tekst;
		cin >> wejscie;
	}
	string::size_type st;
	wejscie_liczba = stoi(wejscie, &st);
	return wejscie_liczba;
}

//Wprowadzanie znaku ze strumienia
char ustaw_jedzenie(string tekst)
{
	char znak;
	do {
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
		cout << tekst;
		cin >> znak;
	} while (cin.fail());
	return znak;
}

//Przeci¹¿ony operator << by wyœwietlaæ wspó³rzêdne jedzenia
ostream & operator << (ostream &wyjscie, const PUNKT &v)
{
	return wyjscie << "Wspolrzedne punktu:[" << v.y + 1 << "][" << v.x + 1 << "]";

}

//Wczytywanie danych z pliku
int wczytaj_plik(int &wielkosc_x, int &wielkosc_y, int &predkosc, char &punkcik)
{
	fstream plik;
	string dane_pliku;
	plik.open("ustawienia.txt", ios::in);
	if (plik.good() == false)	//Sprawdzanie czy otwarcie siê udalo
	{
		cout << "Dostep do pliku zostal zabroniony!" << endl;
		_getch();
		return 997;
	}
	cout << "Uzyskano dostep do pliku!" << endl;

	//Wczytywanie 4 lini z pliku
	getline(plik, dane_pliku);
	wielkosc_x = stoi(dane_pliku.erase(0, dane_pliku.find(":")+1)); //stoi? stoi.
	getline(plik, dane_pliku);
	wielkosc_y = stoi(dane_pliku.erase(0, dane_pliku.find(":") + 1));
	getline(plik, dane_pliku);
	predkosc = stoi(dane_pliku.erase(0, dane_pliku.find(":") + 1));
	getline(plik, dane_pliku);
	punkcik = dane_pliku.erase(0, dane_pliku.find(":") + 1)[0];

	return 1;
}

//Sprawdza czy ustawienia wprowadzone s¹ dozwolone
int sprawdz_poprawnosc_danych(int wielkosc_x, int wielkosc_y, int predkosc, char punkcik)
{
	if (wielkosc_x <= 0 || wielkosc_x > 30)
	{
		cout << "Wysokosc spoza dozwolonego zakresu (1-30)! Wprowadz dane jeszcze raz..." << endl;
		_getch();
		return 999;
	}
	if (wielkosc_y <= 0 || wielkosc_y > 30)
	{
		cout << "Szerokosc spoza dozwolonego zakresu (1-30)! Wprowadz dane jeszcze raz..." << endl;
		_getch();
		return 999;
	}
	if (predkosc <= 0 || predkosc > 8)
	{
		cout << "Predkosc spoza dozwolonego zakresu (1-8)! Wprowadz dane jeszcze raz..." << endl;
		_getch();
		return 999;
	}
	if((int)punkcik < 33 || (int)punkcik > 126)
	{
		cout << "Znak spoza dozwolonego zakresu! Wprowadz dane jeszcze raz..." << endl;
		_getch();
		return 999;
	}
	return 0;
}
