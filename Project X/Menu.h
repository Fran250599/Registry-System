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
	void mantenimientoPorEscuela();

	~Menu() {	delete this->u;	}
};

