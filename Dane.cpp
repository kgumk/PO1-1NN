#include "Dane.h"

void Dane::Analizuj(vector<string> s, int ile)
{
	vector<float> kolejny;
	for (int i = 0; i < s.size(); i++)
	{
		float f = stof(s);
		kolejny.push_back(f);
	}
	dane.push_back(kolejny);
}
