#pragma once
#include <string>
#include <vector>

class Dane
{
	vector<vector<float>> dane;

public:
	void Analizuj(vector<string> s, int ile);
	int LiczbaObiektow() const { return dane.size(); }
	const vector<float>& Obiekt(int i) const { return dane[i]; }
};

