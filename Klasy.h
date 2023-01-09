#pragma once
#include <map>
#include <vector>
#include <string>

class Klasy
{
	vector<string> nazwy;
	map<string, int> indeksyKlas;
	vector<int> indeksy;
public:
	void Dodaj(string s);
	string Klasa(int i) { return nazwy[indeksy[i]]; }
};

