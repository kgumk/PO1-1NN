#include "DaneZKlasami.h"

void DaneZKlasami::Analizuj(char* linia)
{
	vector<string> czesci = Podziel(linia, ' ');
	Dane::Analizuj(czesci, czesci.size() - 1);
	klasy.Dodaj(czesci[czesci.size() - 1]);
}


istream& operator >>(istream &o, DaneZKlasami &dane)
{
	char linia[1024];
	while (!o.eof())
	{
		o.getline(linia, 1023);
		dane.Analizuj(linia);
	}
}
