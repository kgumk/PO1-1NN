#include "DaneZKlasami.h"

vector<string> Podziel(char* linia, char separator)
{
	vector<string> wynik;
	string czesc;
	while (*linia)
	{
		if (*linia == separator)
		{
			wynik.push_back(czesc);
			czesc = "";
		}
		else
			czesc.push_back(*linia);
		linia++;
	}
	if (czesc.size())
		wynik.push_back(czesc);
	return wynik;
}

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
		if (*linia)
			dane.Analizuj(linia);
	}
	return o;
}
