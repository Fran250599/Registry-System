#include "Courses.h"

Courses::Courses(){
	this->code = " ";
	this->name = " ";
	this->type = " ";
	this->credits = 0;
	this->requisites = 0;
	this->weeklyHours = 0;
}

Courses::Courses(std::string c, std::string n, std::string t, int cr, int req, int h, std::vector<std::string>* r){
	this->code = c;
	this->name = n;
	this->type = t;
	this->credits = cr;
	this->requisites = req;
	this->requisitesCourses = r;
	this->weeklyHours = h;
}

std::string Courses::studyPlanString() {

	std::stringstream x;

	x << this->code + "		" + this->name;
	x << "		" + this->credits;
	x << "		";

	for (int i = 0; i < 3; i++) {
		if (this->requisitesCourses->size() != 0) {
			if (!this->requisitesCourses->at(i).empty()) {
				x << this->requisitesCourses->at(i) << std::endl;
			}
		}
	}
	return x.str();
}
