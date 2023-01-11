#include "Klasy.h"

void Klasy::Dodaj(string s)
{
	if (indeksyKlas.find(s) == indeksyKlas.end())
	{
		nazwy.push_back(s);
		indeksyKlas[s] = nazwy.size() - 1;
	}
	indeksy.push_back(indeksyKlas[s]);
}
