#pragma once
#include <iostream>
#include <vector>
#include "Dane.h"
#include "Klasy.h"
using namespace std;

template <class ObiektDanych>
class DaneZKlasami : public Dane<ObiektDanych>
{
protected:
    Klasy klasy;
public:
    Klasy Klasy() const { return klasy; }
    string Klasa(int i) const { return klasy.KlasaObiektu(i); }
};

class DaneRnZKlasami : public DaneZKlasami<vector<float>>
{
public:
    void Analizuj(char* linia);
};

istream& operator >>(istream&, DaneRnZKlasami&);
