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
	std::string careerCode;
public:
	Group();
	Group(std::string, int, int, Professor*, int,std::string, std::string);
	std::string toString();

	std::string getCourseCode(){ return this->courseCode; }
	int getNCR(){ return this->ncr; }
	int getNGroup() { return this->nGroup; }
	std::string getProfessor(){ return this->professor->getName(); }
	int getCupo(){ return this->cupo; }
	std::string getSchedule(){ return this->schedule; }

};
