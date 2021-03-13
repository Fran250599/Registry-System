#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include "Cycle.h"

class Year {
private:
	int annio;
	std::vector<Cycle*>* c;
	//Donde 1 es primer ciclo, 2 es segundo ciclo y 3 es clases de verano
	
public:
	Year();
	Year(int);
public:
    int getAnnio() const;
    void setAnnio(int annio);

	void setCycleBeginDate(int, std::string);
	void setCycleFinishDate(int, std::string);

	std::string toString();

	~Year() { delete this->c; }
};
