#pragma once
#include <iostream>
#include "List.h"
#include "Group.h"

class Cycle {
private:
	std::string inicio;
	std::string final;

	std::string id;   //I, II o III


	List<Group*>* groups = new List<Group*>();
	
public:
	Cycle();
	Cycle(std::string, std::string);

    std::string getInicio() const;
    void setInicio(std::string inicio);

    std::string getFinal() const;
    void setFinal(std::string final);
	std::string getId() { return this->id; }
	List<Group*>* getGroups(){ return this->groups; }
};