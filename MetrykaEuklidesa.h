#pragma once

#include <vector>
#include "Metryka.h"

using namespace std;

class MetrykaEuklidesa : public Metryka<vector<float>>
{
public:
	float operator()(const vector<float>& d1, const vector<float>& d2);
};

