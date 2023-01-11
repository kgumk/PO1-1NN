#pragma once
#include <map>
#include <vector>
#include <string>

using namespace std;

class Klasy
{
	vector<string> nazwy;
	map<string, int> indeksyKlas;
	vector<int> indeksy;
public:
	void Dodaj(string s);
	string Klasa(int i) const { return nazwy[i]; }
	string KlasaObiektu(int i) const { return nazwy[indeksy[i]]; }
	int NrKlasyObiektu(int i) const { return indeksy[i]; }
	int LiczbaKlas() const { return nazwy.size(); }
	int LiczbaObiektow() const { return indeksy.size(); }
};

