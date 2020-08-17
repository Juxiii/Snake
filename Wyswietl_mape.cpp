#include "SNAKE.h"
#include "GRA.h"
#include "PUNKT.h"
#include "MAPA.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include "pch.h"
HANDLE hOut;
using namespace std;

void wyswietl_mape(SNAKE &waz, PUNKT &jedzonko, MAPA &pole, GRA *wsk)
{
	//Sprawdzanie czy waz uderzyl w siebie
	int licz = 0;

	for (int i = 0; i < pole.wielk_x; i++)
	{
		for (int j = 0; j < pole.wielk_y; j++)
		{
			cout << "  ";
			for (unsigned int a = 0; a < waz.polozenie[0].size(); a++)
			{

				if ((waz.polozenie[0][a] == i) && (waz.polozenie[1][a] == j))
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

					if ((waz.polozenie[0][0] == i) && (waz.polozenie[1][0] == j)) cout << "O";
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
