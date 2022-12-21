#pragma once
#include "Orb.h";

class MoveObject : public Orb{
public:
	MoveObject();
	MoveObject(double, double);
	~MoveObject();

	//print value
	void get_value();

	//Orb Object;
	double est_diameter_min;
	double est_diameter_max;
};

