#pragma once
#include <iostream>
#include <vector>
#include "List.h"
#include "Users.h"
#include "Year.h"
#include "Interface.h"
#include "Career.h"
#include "Courses.h"

class University {
private:
	List<Administrator*>* administradores;
	List<Register*>* registros;
	List<Maintenance*>* mantenimientos;
	List<Professor*>* profesores;
	List<Student*>* estudiantes;

	List<Year*>* annios;
	List<Career*>* carreras;

public:
	University() {
		this->administradores = new List<Administrator*>();
		this->registros = new List<Register*>();
		this->mantenimientos = new List<Maintenance*>();
		this->profesores = new List<Professor*>();
		this->estudiantes = new List<Student*>();

		this->annios = new List<Year*>();
		this->carreras = new List<Career*>();
		
	};

	// Seguridad y administracion de roles
	void createUser();
	void showUsers();

	// Mantenimiento general a nivel de registro

		//Mantenimiento de a�os y ciclos lectivos
		void showYearsAndCycles();
		void addYearsAndCycles();

		//Mantenimiento de Carreras y Cursos
		void addCareers();
		void addCourses();
		
		//Empadronamiento
		void listing();
		void showListing();

	~University() {
		this->administradores->~List();
		delete administradores;

		this->registros->~List();
		delete registros;

		this->mantenimientos->~List();
		delete mantenimientos;

		this->profesores->~List();
		delete profesores;

		this->annios->~List();
		delete annios;

		this->carreras->~List();
		delete carreras;
	}
};