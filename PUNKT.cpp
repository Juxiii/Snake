#include "pch.h"
#include "GRA.h"
#include "PUNKT.h"
#include "MAPA.h"

using namespace std;

PUNKT::PUNKT(char znak, MAPA& pole)
{
	x = rand() % pole.zwroc_wysokosc_mapy();
	y = rand() % pole.zwroc_szerokosc_mapy();
	Rodzaj_ikony = znak;

}

//KONSTRUKTOR KOPIUJACY//
PUNKT::PUNKT(PUNKT& punkt)
{
	x = punkt.x;
	y = punkt.y;
	Rodzaj_ikony = punkt.Rodzaj_ikony;
}

PUNKT::~PUNKT()
{

}

void PUNKT::Wyswietl(int i, int j)
{
	cout << Rodzaj_ikony;
}

int PUNKT::zwroc_wspolrzedna(char wspolrzedna)
{
	if (wspolrzedna == 'x') return x;
		return y;
}

char PUNKT::zwroc_rodzaj_ikony()
{
	return Rodzaj_ikony;
}

void PUNKT::zmien_wspolrzedna(char wspolrzedna, int* wartosc)
{
	if (wspolrzedna == 'x') x = *wartosc;
	y = *wartosc;
}