#include "pch.h"
#include "main.h"

using namespace std;

int main()
{	
	//Obsluga okna
	HANDLE hOut;
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1200, 600, TRUE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	srand(static_cast<unsigned int>(time(NULL)));

	//CALA PETLA PROGRAMU
	for (;;)
	{
		int* wielkosc_x = new int;
		int* wielkosc_y = new int;
		int* predkosc = new int;
		char* punkcik = new char;
		char znak;
		int wybor_menu = 404;

		//Petla Menu
		do {
			system("cls");
			cout << "\t\t\t\t\t\t .d8888b.  888b    888        d8888 888    d8P  8888888888 " << endl;
			cout << "\t\t\t\t\t\td88P  Y88b 8888b   888       d88888 888   d8P   888        " << endl;
			cout << "\t\t\t\t\t\tY88b.      88888b  888      d88P888 888  d8P    888        " << endl;
			cout << "\t\t\t\t\t\t \"Y888b.   888Y88b 888     d88P 888 888d88K     8888888    " << endl;
			cout << "\t\t\t\t\t\t    \"Y88b. 888 Y88b888    d88P  888 8888888b    888        " << endl;
			cout << "\t\t\t\t\t\t      \"888 888  Y88888   d88P   888 888  Y88b   888        " << endl;
			cout << "\t\t\t\t\t\tY88b  d88P 888   Y8888  d8888888888 888   Y88b  888        " << endl;
			cout << "\t\t\t\t\t\t \"Y8888P\"  888    Y888 d88P     888 888    Y88b 8888888888 " << endl;


			cout << "MENU: 1 - Z pliku | 2 - Wprowadz recznie | 3 - Wyjdz" << endl;

			do {	//Wybor menu z kontorla strumienia
				if (wybor_menu != 404)
				{
					cin.clear();
					cin.ignore(numeric_limits < streamsize >::max(), '\n');
				}
				cin >> wybor_menu;
			} while (cin.fail());

			switch(wybor_menu)
			{
			case 1: //Obsluga pliku
				wybor_menu = wczytaj_plik(*wielkosc_x,*wielkosc_y,*predkosc,*punkcik);
				break;
			case 2: //Obsluga recznego wprowadzania
				cout << "USTAWIENIA:" << endl;
				*wielkosc_x = ustaw_dane("Ustaw wysokosc mapy (1-30): ");
				*wielkosc_y = ustaw_dane("Ustaw szerokosc mapy (1-30): ");
				*predkosc = ustaw_dane("Ustaw predkosc (1-8): ");
				*punkcik = ustaw_jedzenie("Ustaw znaczek jedzenia: ");
				break;
			case 3: //Wyjscie
				exit(0);
			default: wybor_menu = 999;
			}
			wybor_menu=sprawdz_poprawnosc_danych(*wielkosc_x, *wielkosc_y, *predkosc, *punkcik);
		} while (wybor_menu == 999);

		//TWORZENIE OBIEKTÓW
		GRA* wsk;
		MAPA pole(*wielkosc_x, *wielkosc_y);
		SNAKE waz;
		PUNKT jedzonko(*punkcik, pole);
		wsk = &waz;

		delete wielkosc_x;
		delete wielkosc_y;
		delete punkcik;

		//PETLA GRY
		while (pole.czy_zginal(waz) != true)
		{
			//SPRAWDZANIE CZY ZJADL
			if (pole.czy_zjadl(jedzonko, waz) == true) pole.ustaw_punkt(jedzonko, waz);
			
			//SPRAWDZANIE BUFORA KLAWIATURY
			if (_kbhit() == 1) waz.zmiana_kierunku(_getch());
			
			//RUCH
			waz.ruch(pole);
			pole.powieksz_weza(jedzonko, waz);

			//SPRAWDZANIE CZY ZGINAL
			if (pole.czy_zginal(waz) == false)
			{
				wyswietl_mape(waz, jedzonko, pole, wsk);
				Sleep(1000 / *predkosc); 
				system("cls");
			}
			else cout << "PRZEGRANA" << endl;
		}

		cout << "ZDOBYTE PUNKTY: " << pole.zwroc_liczbe_punktow() << endl;
		cout << "Jeszcze raz? (Y/N): ";
		cin >> znak;
		if ((znak == 'Y') || (znak == 'y')) system("cls");
		else exit(0);
		delete predkosc;
	}
	return 0;
}
