#pragma once

using namespace std;

class MAPA;
class SNAKE;

//Klasa PUNKT - zarz¹dzanie "jedzeniem" dla wê¿a
class PUNKT :public GRA
{	
private:
	int x, y;
	char Rodzaj_ikony;
public:
	int czas_czekania;
	friend void wyswietl_mape(SNAKE &waz, PUNKT &jedzonko, MAPA &pole, GRA *wsk);
	virtual void Wyswietl(int, int);
	PUNKT(char, MAPA &pole);
	PUNKT(PUNKT& punkt);
	~PUNKT();
	friend ostream &operator<<(ostream &wyjscie, const PUNKT &v);
	int zwroc_wspolrzedna(char);
	char zwroc_rodzaj_ikony();
	void zmien_wspolrzedna(char, int*);
};