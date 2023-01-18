#pragma once

template<class ObiektDanych>
class Klasyfikator
{
public:
	virtual void Naucz(const DaneZKlasami<ObiektDanych> *dane) = 0;
	virtual Klasy Klasyfikuj(const Dane<ObiektDanych> &dane) = 0;
};

