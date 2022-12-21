#pragma once
#include"StarObject.h"
#include"MoveObject.h"

class MovingStar : Orb
{
public:
	MovingStar();
	MovingStar(double, double);
	~MovingStar();

	double light;
	double distance;

	double* twinkle;

	int cal_twinkle();
};

