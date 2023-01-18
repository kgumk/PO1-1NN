#pragma once
#include "Klasyfikator.h"
#include "DaneZKlasami.h"
#include "Metryka.h"

template <class ObiektDanych>
class Klasyfikator1NN :
    public Klasyfikator<ObiektDanych>
{
	const DaneZKlasami<ObiektDanych> *daneTrn;
    string Klasyfikuj(const ObiektDanych&dane);
    Metryka<ObiektDanych> *metryka;
public:
    Klasyfikator1NN(Metryka<ObiektDanych> *metryka);
    void Naucz(const DaneZKlasami<ObiektDanych> *dane);
    Klasy Klasyfikuj(const Dane<ObiektDanych> &dane);
};

template <class ObiektDanych>
Klasyfikator1NN<ObiektDanych>::Klasyfikator1NN(Metryka<ObiektDanych> *metryka)
	: metryka(metryka)
{
}

template <class ObiektDanych>
void Klasyfikator1NN<ObiektDanych>::Naucz(const DaneZKlasami<ObiektDanych>* dane)
{
	daneTrn = dane;
}

template <class ObiektDanych>
Klasy Klasyfikator1NN<ObiektDanych>::Klasyfikuj(const Dane<ObiektDanych>& dane)
{
	Klasy klasy;
	for (int i = 0; i < dane.LiczbaObiektow(); i++)
	{
		string klasa = Klasyfikuj(dane.Obiekt(i));
		klasy.Dodaj(klasa);
	}
	return klasy;
}

template <class ObiektDanych>
string Klasyfikator1NN<ObiektDanych>::Klasyfikuj(const ObiektDanych& dane)
{
	int indeksNN = 0;
	float odleglosc = (*metryka)(dane, daneTrn->Obiekt(0));
	for (int i = 1; i < daneTrn->LiczbaObiektow(); i++)
	{
		float odl = (*metryka)(dane, daneTrn->Obiekt(i));
		if (odl < odleglosc)
		{
			indeksNN = i;
			odleglosc = odl;
		}
	}
	return daneTrn->Klasa(indeksNN);
}
