#include "MacierzKonfuzji.h"

MacierzKonfuzji::MacierzKonfuzji(const Klasy& k1, const Klasy& k2)
	: k1(k1), k2(k2)
{
	int liczbaKlas = k1.LiczbaKlas();
	for (int i = 0; i < liczbaKlas; i++)
	{
		vector<int> wiersz;
		for (int j = 0; j < liczbaKlas; j++)
			wiersz.push_back(0);
		wpisy.push_back(wiersz);
	}

	int liczbaObiektow = k1.LiczbaObiektow();
	for (int i = 0; i < liczbaObiektow; i++)
		wpisy[k1.NrKlasyObiektu(i)][k2.NrKlasyObiektu(i)]++;
}
