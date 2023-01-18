#pragma once
#include <string>
#include <vector>
using namespace std;

template <class ObiektDanych>
class Dane
{
protected:
	vector<ObiektDanych> dane;

public:
	//void AnalizujObiekt(vector<string> s, int ile);
	int LiczbaObiektow() const { return dane.size(); }
	const ObiektDanych& Obiekt(int i) const { return dane[i]; }
};

