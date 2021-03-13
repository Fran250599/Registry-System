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
