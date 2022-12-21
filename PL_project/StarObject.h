#pragma once
#include"Orb.h"

class StarObject : public Orb {
public:
	StarObject();
	StarObject(double);
	~StarObject();

	double* absolute_magnitude;
	void get_value();
};

