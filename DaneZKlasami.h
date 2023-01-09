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
    string Klasa(int i) { return klasy.Klasa(i); }
};

istream& operator >>(istream&, DaneZKlasami&);
