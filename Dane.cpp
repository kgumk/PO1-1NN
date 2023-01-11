#include <string>
#include "Dane.h"
using namespace std;

void Dane::Analizuj(vector<string> s, int ile)
{
	vector<float> kolejny;
	for (int i = 0; i < ile; i++)
	{
		float f = stof(s[i]);
		kolejny.push_back(f);
	}
	dane.push_back(kolejny);
}
