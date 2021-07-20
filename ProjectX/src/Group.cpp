#include "../include/Group.h"

Group::Group(){
	this->courseCode = " ";
	this->ncr = 0;
	this->nGroup = 0;
	this->professor = new Professor();
	this->cupo = 0;
	this->schedule= " ";
}

Group::Group(std::string _code, int _ncr, int _nGroup, Professor* _professor,  int _cupo, std::string _schedule, std::string _careerCode) {

	this->courseCode = _code;
	this->ncr = _ncr;
	this->nGroup = _nGroup;
	this->professor = _professor;
	this->cupo = _cupo;
	this->schedule = _schedule;
	this->careerCode = _careerCode;
}

std::string Group::toString() {

	std::stringstream x;

	x << this->courseCode;

	return x.str();

}