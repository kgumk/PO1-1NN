#include "MetrykaEuklidesa.h"

float MetrykaEuklidesa::operator()(const vector<float>& d1, const vector<float>& d2)
{
	double wynik = 0;
	for (int i = 0; i < d1.size(); i++)
	{
		double r = d1[i] - d2[i];
		wynik += r * r;
	}

	return (float)wynik;
}
