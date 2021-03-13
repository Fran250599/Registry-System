#include "Career.h"

Career::Career() {
	this->name = " ";
	this->code = " ";
	this->grade = " ";
	this->escuela = new std::string();
	this->facultad = new std::string();
}

Career::Career(std::string code, std::string name, std::string grade, std::string* escuela, std::string* facultad){
	this->code = code;
	this->name = name;
	this->grade = grade;
	this->escuela = escuela;
	this->facultad = facultad;
}
