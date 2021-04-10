#pragma once
#include <iostream>
#include "List.h"
#include "Courses.h"
#include "Users.h"

class Career {
private:
	std::string code;
	std::string name;
	std::string grade;

	std::string* escuela;
	std::string* facultad;
	
	List<Courses*>* c = new List<Courses*>();
	List<Student*>* s = new List<Student*>();

	bool status = false;

public:
	Career();
	Career(std::string, std::string, std::string, std::string*, std::string*);

	std::string getCode() { return this->code; }
	std::string getName() { return this->name; }

	List<Courses*>* getCourses() { return this->c; }
	List<Student*>* getStudents() { return this->s; }

	~Career() { delete escuela, facultad; }
};
