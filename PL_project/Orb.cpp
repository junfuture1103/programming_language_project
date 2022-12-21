#include<iostream>
#include<string.h>
#include"orb.h"

Orb::Orb() {
	this->initialize_Object();
}

Orb::Orb(std::string input_name) {
	this->initialize_Object();
	this->set_name(input_name);

	return;
}

Orb::~Orb() {

}

void Orb::doubling_capacity() {
	int new_capacity = this->name_capacity * 2;
	char* new_value_string = new char[new_capacity]();
	if (new_value_string == NULL) return;

	memcpy(new_value_string, this->name, this->name_length);
	delete[] this->name;

	this->name_capacity = new_capacity;
	this->name = new_value_string;

	return;
}

void Orb::initialize_Object() {
	this->name = new char[this->initial_name_capacity]();
	if (this->name != NULL) {
		this->name_capacity = this->initial_name_capacity;
		this->name_length = 0;
	}

	return;
}

void Orb::set_name(std::string value) {
	while (this->name_capacity <= value.length()) {
		this->doubling_capacity();
	}

	memcpy(this->name, value.c_str(), value.length());
	this->name_length = static_cast<unsigned int>(value.length());

	return;
}

void Orb::get_value() {
	printf("Orbname : %s\n", this->name);
	return;
}

void Orb::add_id() {
	id[0] = name[0];
	id[1] = name[1];
	id[2] = '\0';
}