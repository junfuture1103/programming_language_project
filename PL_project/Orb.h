#pragma once
#include"Object.h"
#include <iostream>
using namespace std;

class Orb : Object {
public:
	Orb();
	Orb(std::string);
	~Orb();
	void initialize_Object();
	void doubling_capacity();
	void set_name(std::string);
	void get_value();
	void add_id();
public:
	char* name;
	char id[3];

private:
	static const unsigned int initial_name_capacity = 10;
	unsigned int name_capacity;
	unsigned int name_length;
};