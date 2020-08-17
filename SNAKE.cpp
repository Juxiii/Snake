#include "pch.h"
#include "GRA.h"
#include "PUNKT.h"
#include "SNAKE.h"
#include "MAPA.h"

using namespace std;

void SNAKE::zmiana_kierunku(char a)
{
	//Blokada zawracania weza i zmiana kierunku
	switch (a)
	{
	case 'a':if (kierunek != 'd') kierunek = 'a'; break;
	case 'd':if (kierunek != 'a') kierunek = 'd'; break;
	case 'w':if (kierunek != 's') kierunek = 'w'; break;
	case 's':if (kierunek != 'w') kierunek = 's'; break;
	default:break;
	}
}

void SNAKE::ruch(MAPA &pole)
{
	int temp_x, temp_y;

	temp_x = polozenie[0][0];
	temp_y = polozenie[1][0];

	//Ruch z przechodzeniem przez sciany
	switch (kierunek)
	{
	case 'a':if (temp_y == 0) temp_y = pole.zwroc_szerokosc_mapy() - 1;
			 else temp_y--; break;
	case 'w':if (temp_x == 0) temp_x = pole.zwroc_wysokosc_mapy() - 1;
			 else temp_x--; break;
	case 's':if (temp_x == pole.zwroc_wysokosc_mapy() - 1) temp_x = 0;
			 else temp_x++; break;
	case 'd':if (temp_y == pole.zwroc_szerokosc_mapy() - 1) temp_y = 0;
			 else temp_y++; break;
	default:break;
	}

	polozenie[0].insert(polozenie[0].begin(), temp_x);
	polozenie[1].insert(polozenie[1].begin(), temp_y);
}

SNAKE::SNAKE()
{
	kierunek = 'd';
	polozenie.push_back(vector<int>(0));
	polozenie.push_back(vector<int>(0));
	polozenie[0].push_back(1);
	polozenie[0].push_back(0);
	polozenie[1].push_back(0);
	polozenie[1].push_back(0);
}

void SNAKE::Wyswietl(int i, int j)
{
	cout << "X";
}

int SNAKE::zwroc_polozenie(int a, int b)
{
	return polozenie[a][b];
}

unsigned int SNAKE::zwroc_wielkosc(int a)
{
	return polozenie[a].size();
}

void SNAKE::utnij(int a)
{
	polozenie[a].pop_back();
}

SNAKE::~SNAKE()
{

}