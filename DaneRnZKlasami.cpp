#include "DaneRnZKlasami.h"

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

vector<float> AnalizujObiekt(vector<string> s, int ile)
{
	vector<float> kolejny;
	for (int i = 0; i < ile; i++)
	{
		float f = stof(s[i]);
		kolejny.push_back(f);
	}
	return kolejny;
}

void DaneRnZKlasami::Analizuj(char* linia)
{
	vector<string> czesci = Podziel(linia, ' ');
	dane.push_back(AnalizujObiekt(czesci, czesci.size() - 1));
	klasy.Dodaj(czesci[czesci.size() - 1]);
}


istream& operator >>(istream &o, DaneRnZKlasami &dane)
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
