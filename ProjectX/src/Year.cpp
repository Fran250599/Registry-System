#include "../include/Year.h"

Year::Year(){
	this->id = " ";
	
	this->c = new std::vector<Cycle*>(3);
	
	for (int i = 0; i < 3; i++) {
		this->c->at(i) = new Cycle();
	}
}

Year::Year(int _annio){
	this->id = _annio;

	this->c = new std::vector<Cycle*>(3);
	for (int i = 0; i < 3; i++) {
		this->c->at(i) = new Cycle();
	}
}

std::string Year::getId() const
{
    return id;
}
int Year::getAnnio() const{
	int aux = 0;

	std::stringstream ss;  
  	ss << this->id;  
  	ss >> aux; 

	return aux;
}

void Year::setAnnio(std::string annio){
    this->id = annio;
}

void Year::setCycleFinishDate(int n, std::string finishDate){
	Cycle* c1 = this->c->at(n);
	c1->setFinal(finishDate);
}

std::string Year::toString()
{
	std::stringstream x;

	x << "Annio: " << Year::getAnnio() << std::endl;
	int j = 0;

	std::string inicio;
	std::string final;

	for (int i = 0; i < 2; i++) {

		inicio = this->c->at(i)->getInicio();
		final = this->c->at(i)->getFinal();
		j++;

		if (inicio != " ") {
			x << "Inicio ciclo " << j << ":  " << inicio << std::endl;
			x << "Final ciclo " << j << ":  " << final << std::endl << std::endl;
		}
	}

	x << "----------------------------------" << std::endl;
	return x.str();
}

void Year::setCycleBeginDate(int n, std::string beginDate){
	Cycle* c1 = new Cycle();
	c1 = this->c->at(n);
	c1->setInicio(beginDate);
}

