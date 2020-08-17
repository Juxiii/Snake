#pragma once

using namespace std;

//Klasa abstrakcyjna GRA - rodzic reszty klas
class GRA
{
public:
	GRA();
	virtual void Wyswietl(int, int) = 0;
};

