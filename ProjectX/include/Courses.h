#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "List.h"
#include "Group.h"

class Courses {
private:
	std::string code;
	std::string name;
	std::string type;
	int credits;
	int requisites;
	int weeklyHours;
	bool state = true;

	std::vector<std::string>* requisitesCourses = new std::vector<std::string>(3);
	
	List<Group*>* groups = new List<Group*>();

public:
	Courses();
	Courses(std::string, std::string, std::string, int, int, int, std::vector<std::string>*);

	std::string getCode() { return this->code; }
	std::string getName() { return this->name; }
	List<Group*>* getGroups() { return this->groups; }

	std::string studyPlanString();


	~Courses() { delete this->requisitesCourses, groups; }
};
