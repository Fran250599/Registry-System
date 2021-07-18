#include "../include/Cycle.h"

Cycle::Cycle() {
	this->inicio = " ";
	this->final = " ";
}

Cycle::Cycle(std::string i, std::string f){
	this->inicio = i;
	this->final = f;
}

std::string Cycle::getInicio() const
{
    return inicio;
}

void Cycle::setInicio(std::string inicio)
{
    this->inicio = inicio;
}

std::string Cycle::getFinal() const
{
    return final;
}

void Cycle::setFinal(std::string final)
{
    this->final = final;
}

