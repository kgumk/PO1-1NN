#pragma once

#include <string>
#include "Klasy.h"
using namespace std;

class MacierzKonfuzji
{
	const Klasy& k1, & k2;
	vector<vector<int>> wpisy;
public:
	MacierzKonfuzji(const Klasy &k1, const Klasy &k2);
	int LiczbaKlas() { return k1.LiczbaKlas(); }
	string Klasa(int i) { return k1.Klasa(i); }
	int Wpis(int i, int j) { return wpisy[i][j]; }
};

