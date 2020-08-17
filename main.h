//Plik naglowkowy do zalaczania funkcji i klas
#pragma once
#include "GRA.h"
#include "MAPA.h"
#include "SNAKE.h"
#include "PUNKT.h"

int ustaw_dane(string tekst);
char ustaw_jedzenie(string tekst);
int wczytaj_plik(int&,int&,int&,char&);
int sprawdz_poprawnosc_danych(int,int,int,char);
