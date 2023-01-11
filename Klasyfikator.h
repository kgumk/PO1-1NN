#pragma once
class Klasyfikator
{
public:
	virtual void Naucz(const DaneZKlasami *dane) = 0;
	virtual Klasy Klasyfikuj(const Dane &dane) = 0;
};

