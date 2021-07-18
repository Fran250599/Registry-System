#pragma once

#include <iostream>
#include <sstream>

#include "Users.h"

class Group {
private:
	std::string courseCode;
	int ncr;
	int nGroup;
	Professor* professor;
	int cupo;
	std::string schedule;
public:
	Group();
	Group(std::string, int, int, Professor*, int,std::string);
	std::string toString();

};
