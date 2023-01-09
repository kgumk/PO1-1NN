#pragma once
#include "Klasyfikator.h"
#include "DaneZKlasami.h"

template <class Metryka>
class Klasyfikator1NN :
    public Klasyfikator
{
    DaneZKlasami *daneTrn;
    string Klasyfikuj(const vector<float> &dane);
    Metryka metryka;
public:
    Klasyfikator1NN(Metryka metryka);
    void Naucz(DaneZKlasami *dane);
    Klasy Klasyfikuj(const Dane &dane);
};

template <class Metryka>
Klasyfikator1NN<Metryka>::Klasyfikator1NN(Metryka metryka)
	: metryka(metryka)
{
}

template <class Metryka>
void Klasyfikator1NN<Metryka>::Naucz(DaneZKlasami* dane)
{
	daneTrn = dane;
}

template <class Metryka>
Klasy Klasyfikator1NN<Metryka>::Klasyfikuj(const Dane& dane)
{
	Klasy klasy;
	for (int i = 0; i < dane.LiczbaObiektow(); i++)
	{
		string klasa = Klasyfikuj(dane.Obiekt(i));
		klasy.Dodaj(klasa);
	}
	return klasy;
}

template <class Metryka>
string Klasyfikator1NN<Metryka>::Klasyfikuj(const vector<float>& dane)
{
	int indeksNN = 0;
	float odleglosc = metryka(dane, daneTrn->Obiekt(0));
	for (int i = 1; i < daneTrn->LiczbaObiektow(); i++)
	{
		float odl = metryka(dane, daneTrn->Obiekt(i));
		if (odl < odleglosc)
		{
			indeksNN = i;
			odleglosc = odl;
		}
	}
	return daneTrn->Klasa(indeksNN);
}
