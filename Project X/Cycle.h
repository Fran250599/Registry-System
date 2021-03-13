#pragma once
#include <iostream>

class Cycle {
private:
	std::string inicio;
	std::string final;

public:
	Cycle();
	Cycle(std::string, std::string);

    std::string getInicio() const;
    void setInicio(std::string inicio);

    std::string getFinal() const;
    void setFinal(std::string final);

};