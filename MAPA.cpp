#include "pch.h"
#include "GRA.h"
#include "MAPA.h"
#include "PUNKT.h"
#include "SNAKE.h"

using namespace std;

MAPA::MAPA(int wielkosc_x, int wielkosc_y)
{
	wielk_x = wielkosc_x;
	wielk_y = wielkosc_y;
	liczba_pkt = 0;
	vector<char> temp;
	for (int i = 0; i < wielk_x; i++)
	{
		plansza.push_back(temp);
		for (int j = 0; j < wielk_y; j++)
		{
			plansza[i].push_back(254);
		}
		cout << endl;
	}
}

bool MAPA::czy_zjadl(PUNKT &jedzonko, SNAKE &waz)
{
	if ((waz.zwroc_polozenie(0,0) == jedzonko.zwroc_wspolrzedna('x')) && (waz.zwroc_polozenie(1,0) == jedzonko.zwroc_wspolrzedna('y'))) { liczba_pkt++; return true; }
	else return false;
}

bool MAPA::czy_zginal(SNAKE &waz)
{
	for (unsigned int j = 1; j < waz.zwroc_wielkosc(1); j++)
	{
		if ((waz.zwroc_polozenie(0,0) == waz.zwroc_polozenie(0,j)) && (waz.zwroc_polozenie(1,0) == waz.zwroc_polozenie(1,j))) return true;
	}

	return false;
}

void MAPA::powieksz_weza(PUNKT &jedzonko, SNAKE &waz)
{
	//POWIEKSZENIE JESLI ZJADL
	if ((waz.zwroc_polozenie(0,0) != jedzonko.zwroc_wspolrzedna('x')) || (waz.zwroc_polozenie(1,0) != jedzonko.zwroc_wspolrzedna('y')))
	{
		waz.utnij(0);
		waz.utnij(1);
	}
}

void MAPA::ustaw_punkt(PUNKT &jedzonko, SNAKE &waz)
{
	bool k;

	do {
		k = false;

		int *nowa_wspolrzedna = new int;
		*nowa_wspolrzedna = rand() % (zwroc_wysokosc_mapy() - 1);
		jedzonko.zmien_wspolrzedna('x', nowa_wspolrzedna);
		*nowa_wspolrzedna = rand() % (zwroc_szerokosc_mapy() - 1);
		jedzonko.zmien_wspolrzedna('y', nowa_wspolrzedna);
		delete nowa_wspolrzedna;

		for (unsigned int i = 0; i < waz.zwroc_wielkosc(0); i++)
		{
			if ((jedzonko.zwroc_wspolrzedna('x') == waz.zwroc_polozenie(0,i)) && (jedzonko.zwroc_wspolrzedna('y') == waz.zwroc_polozenie(1,i))) k = true;
		}
	} while (k == true);
}

void MAPA::Wyswietl(int i, int j)
{
	cout << plansza[i][j];
}

void wyswietl_mape(SNAKE &waz, PUNKT &jedzonko, MAPA &pole, GRA *wsk)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//Sprawdzanie czy waz uderzyl w siebie
	int licz = 0;

	for (int i = 0; i < pole.zwroc_wysokosc_mapy(); i++)
	{
		for (int j = 0; j < pole.zwroc_szerokosc_mapy(); j++)
		{
			cout << "  ";
			for (unsigned int a = 0; a < waz.zwroc_wielkosc(0); a++)
			{

				if ((waz.zwroc_polozenie(0,a) == i) && (waz.zwroc_polozenie(1,a) == j))
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

					if ((waz.zwroc_polozenie(0,0) == i) && (waz.zwroc_polozenie(1,0) == j)) cout << "O";
					else {
						wsk = &waz;
						wsk->Wyswietl(i, j);
						}

					SetConsoleTextAttribute(hOut, 15);
					licz++;
				}
			}
			if (licz == 0)
			{
				if ((i == jedzonko.x) && (j == jedzonko.y)) {
					SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);

					wsk = &jedzonko;
					wsk->Wyswietl(i, j);

					SetConsoleTextAttribute(hOut, 15);
				}
				else {
					wsk = &pole;
					wsk->Wyswietl(i, j);
				}
			}
			licz = 0;
		}
		if (i == 1) cout << "\t\t\t Liczba punktow: " << pole.liczba_pkt;
		if (i == 2) cout << "\t\t\t " << jedzonko;
		cout << endl;
	}

}

int MAPA::zwroc_liczbe_punktow()
{
	return liczba_pkt;
}

int MAPA::zwroc_wysokosc_mapy()
{
	return wielk_x;
}

int MAPA::zwroc_szerokosc_mapy()
{
	return wielk_y;
}

MAPA::~MAPA()
{
}