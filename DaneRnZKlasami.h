#pragma once
#include "DaneZKlasami.h"

class DaneRnZKlasami : public DaneZKlasami<vector<float>>
{
public:
    void Analizuj(char* linia);
};

istream& operator >>(istream&, DaneRnZKlasami&);
