#include "Year.h"

Year::Year(){
	this->annio = 0;
	
	this->c = new std::vector<Cycle*>(3);
	
	for (int i = 0; i < 3; i++) {
		this->c->at(i) = new Cycle();
	}
}

Year::Year(int _annio){
	this->annio = _annio;

	this->c = new std::vector<Cycle*>(3);
	for (int i = 0; i < 3; i++) {
		this->c->at(i) = new Cycle();
	}
}

int Year::getAnnio() const
{
    return annio;
}

void Year::setAnnio(int annio){
    this->annio = annio;
}

void Year::setCycleFinishDate(int n, std::string finishDate){
	Cycle* c1 = this->c->at(n);
	c1->setFinal(finishDate);
}

std::string Year::toString()
{
	std::stringstream x;

	x << "Annio: " << this->annio << std::endl;
	int j = 0;

	std::string inicio;
	std::string final;

	for (int i = 0; i < 2; i++) {

		inicio = this->c->at(i)->getInicio();
		final = this->c->at(i)->getFinal();
		j++;

		if (inicio != " ") {
			x << "Inicio ciclo " << j << ":" << inicio << std::endl;
			x << "Final ciclo " << j << ":" << final << std::endl << std::endl;
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

