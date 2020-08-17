#pragma once

using namespace std;

class SNAKE;
class PUNKT;

//Klasa mapa - kontrola planszy

class MAPA :public GRA
{
private:
	int liczba_pkt;
	vector< vector<char> > plansza;
	int wielk_x;
	int wielk_y;

public:
	MAPA(int, int);
	~MAPA();
	virtual void Wyswietl(int, int);
	friend void wyswietl_mape(SNAKE &waz, PUNKT &jedzonko, MAPA &pole, GRA *wsk);
	bool czy_zjadl(PUNKT &jedzonko, SNAKE &waz);
	bool czy_zginal(SNAKE &waz);
	void powieksz_weza(PUNKT &jedzonko, SNAKE &waz);
	void ustaw_punkt(PUNKT &jedzonko, SNAKE &waz);
	int zwroc_liczbe_punktow();
	int zwroc_wysokosc_mapy();
	int zwroc_szerokosc_mapy();
};

