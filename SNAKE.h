#pragma once

using namespace std;


//Klasa SNAKE - zarz¹dzanie wê¿em
class SNAKE :public GRA
{
private:
	char kierunek;
	vector< vector<int> > polozenie;
	friend void wyswietl_mape(SNAKE &waz, PUNKT &jedzonko, MAPA &pole, GRA *wsk);

public:
	int zwroc_polozenie(int, int);
	unsigned int zwroc_wielkosc(int);
	void utnij(int);
	void zmiana_kierunku(char);
	virtual void Wyswietl(int, int);
	void ruch(MAPA &pole);
	SNAKE();
	~SNAKE();
};