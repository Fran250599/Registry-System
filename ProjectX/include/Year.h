#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include "Cycle.h"
#include "Group.h"

class Year {
private:
	std::string id;
	std::vector<Cycle*>* c;
	//Donde 1 es primer ciclo, 2 es segundo ciclo y 3 es clases de verano
	
	

public:
	Year();
	Year(int);
public:
    std::string getId() const;
	int getAnnio() const;
	std::vector<Cycle*>* getCycles() { return this->c ; }
    void setAnnio(std::string annio);

	void setCycleBeginDate(int, std::string);
	void setCycleFinishDate(int, std::string);

	std::string toString();

	~Year() { delete this->c; }
};
