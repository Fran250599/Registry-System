#pragma once
#include <iostream>
#include <vector>

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

public:
	Courses();
	Courses(std::string, std::string, std::string, int, int, int, std::vector<std::string>*);

	std::string getCode() { return this->code; }

	~Courses() { delete this->requisitesCourses; }
};
