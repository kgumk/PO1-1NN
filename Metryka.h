#pragma once

template <class ObiektDanych>
class Metryka
{
public:
	virtual float operator()(const ObiektDanych& d1, const ObiektDanych& d2) = 0;
};

