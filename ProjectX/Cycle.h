#pragma once
#include <iostream>

class Cycle {
private:
	std::string inicio;
	std::string final;

	std::string cycleName;
public:
	Cycle();
	Cycle(std::string, std::string);

    std::string getInicio() const;
    void setInicio(std::string inicio);

    std::string getFinal() const;
    void setFinal(std::string final);
	std::string getCycleName() { return this->cycleName; }

};