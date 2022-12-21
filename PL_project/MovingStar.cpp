#include "MovingStar.h"

MovingStar::MovingStar() {
	this->twinkle = new double;
}

MovingStar::MovingStar(double lig, double dis) {
	this->twinkle = new double;

	this->light = lig;
	this->distance = dis;
}

MovingStar::~MovingStar() {
	delete this->twinkle;
}

int MovingStar::cal_twinkle() {
	(*this->twinkle) = light * distance;
	return (*this->twinkle);
}


