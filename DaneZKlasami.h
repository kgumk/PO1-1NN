#pragma once
#include <iostream>
#include "Dane.h"
#include "Klasy.h"
using namespace std;

class DaneZKlasami : public Dane
{
    Klasy klasy;
public:
    void Analizuj(char *linia);
    Klasy Klasy() const { return klasy; }
    string Klasa(int i) const { return klasy.KlasaObiektu(i); }
};

istream& operator >>(istream&, DaneZKlasami&);
