#pragma once
#include"Orb.h"

//relative_velocity	miss_distance
class ObserveObject : public Orb
{
public:
	ObserveObject();
	ObserveObject(double, double);
	~ObserveObject();

	//print value
	void get_value();

	//process
	void print_velxdis();

private:
	double relative_velocity;
	double miss_distance;
};

