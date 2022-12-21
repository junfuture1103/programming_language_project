#include "ObserveObject.h"

ObserveObject::ObserveObject() {
	this->relative_velocity = .0;
	this->miss_distance = .0;
}

ObserveObject::ObserveObject(double vel, double dis) {
	this->relative_velocity = vel;
	this->miss_distance = dis;
}

ObserveObject::~ObserveObject() {
	this->relative_velocity = .0;
	this->miss_distance = .0;
}

void ObserveObject::get_value() {
	printf("\n ========= ObserveObject ID : %s =========\n", this->id);
	printf("Orbname : %s\n", this->name);
	printf("dia : %lf %lf\n", this->relative_velocity, this->miss_distance);
	print_velxdis();
}

void ObserveObject::print_velxdis() {
	printf("science distance : %.5lf\n", this->miss_distance* this->relative_velocity);
}