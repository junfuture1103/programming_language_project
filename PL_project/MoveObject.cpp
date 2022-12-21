#include "MoveObject.h"

MoveObject::MoveObject() {
	add_id();
	est_diameter_min = 0;
	est_diameter_max = 0;
}

MoveObject::MoveObject(double min, double max) {
	add_id();
	est_diameter_min = min;
	est_diameter_max = max;
}
MoveObject::~MoveObject() {

}

void MoveObject::get_value() {
	printf("\n ========= MoveObject ID : %s =========\n", this->id);
	printf("Orbname : %s\n", this->name);
	printf("dia : %lf %lf\n", this->est_diameter_min, this->est_diameter_max);
}
