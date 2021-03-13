#pragma once
#include "University.h"

class Menu {
private:
	University* u;
public:
	Menu() { u = new University(); }
	void menuPrincipal();

	void seguridadYAdministracion();
	void mantenmientoANivelDeRegistro();

	~Menu() {	delete this->u;	}
};

