#include "StarObject.h"

StarObject::StarObject() {
	this->absolute_magnitude = new double;
}

StarObject::StarObject(double value) {
	this->absolute_magnitude = new double;
	(*this->absolute_magnitude) = value;
}

StarObject::~StarObject() {
	delete this->absolute_magnitude;
}


void StarObject::get_value() {
	printf("\n ========= StarObject ID : <STAR>%s =========\n", this->id);
	printf("Orbname : %s\n", this->name);
	printf("absolute_magnitude : %.2lf\n", *(this->absolute_magnitude));
}
