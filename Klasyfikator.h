#pragma once
class Klasyfikator
{
public:
	virtual void Naucz(DaneZKlasami dane) = 0;
	virtual Klasy Klasyfikuj(DaneZKlasami dane) = 0;
};

