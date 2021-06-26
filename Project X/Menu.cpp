#include "Menu.h"

void Menu::menuPrincipal(){

	bool menu = true;

	while (menu == true) {
		Interface::print("Bienvenido al sistema de registro.\n");
		Interface::print("1- Seguridad y administracion de roles");
		Interface::print("2- Mantenimiento General a Nivel de Registro");
		Interface::print("3- Mantenimiento por Escuela");
		Interface::print("4- Matricula e historiales");
		Interface::print("5- Registro de actas");
		Interface::print("6- Archivos");
		Interface::print("7- Salir\n");

		Interface::print("Por favor digite una opcion: ");

		int opcion = Interface::getInt();

		switch (opcion) {
		case 1: {

			Menu::seguridadYAdministracion();

		} break;

		case 2: {
			Menu::mantenmientoANivelDeRegistro();
		} break;
		case 3: {
		
		}break;
		case 7: { menu = false; } break;
		}
		
	}
}

void Menu::seguridadYAdministracion(){
	Interface::cleanScreen();
	Interface::cleanTrash();

	bool menu = true;
	while (menu == true) {

		Interface::print("1- Crear usuario.");
		Interface::print("2- Mostrar usuarios.");
		Interface::print("3- Volver");

		int opcion = Interface::getInt();

		switch (opcion) {
		case 1: {
			Interface::cleanScreen();
			u->createUser();

		}break;
		case 2: {
			Interface::cleanScreen();
			u->showUsers();
		}break;
		case 3: {
			Interface::cleanScreen();
			menu = false;
		}break;
		}
	}
}

void Menu::mantenmientoANivelDeRegistro() {

	Interface::cleanScreen();
	Interface::cleanTrash();

	bool menu = true;

	while (menu == true) {
		Interface::print("Mantenimiento general a nivel de registro.\n");
		Interface::print("1- Mantenimiento de annios y ciclos lectivos");
		Interface::print("2- Mantenimiento de carreras y cursos");
		Interface::print("3- Empadronamiento");
		Interface::print("4- Volver\n");

		Interface::print("Por favor digite una opcion: ");

		int opcion = Interface::getInt();

		switch (opcion) {
		case 1: {
			bool menu1 = true;
			while (menu1 == true) {
				Interface::cleanScreen();
				Interface::cleanTrash();

				Interface::print("Mantenimiento de annios y ciclos lectivos\n");
				Interface::print("1- Ver ciclos lectivos");
				Interface::print("2- Ingresar ciclo lectivo");
				Interface::print("3- Volver");

				int opcion1 = Interface::getInt();

		
				if (opcion1 == 1 || opcion1 == 2 || opcion1 == 3) {
					if (opcion1 == 1) {
						Interface::cleanScreen();
						this->u->showYearsAndCycles();
					}
					if (opcion1 == 2) {
						Interface::cleanScreen();
						this->u->addYearsAndCycles();
					}
					if (opcion1 == 3) {
						menu1 = false;
						Interface::cleanScreen();
					}
				}
				else {
					do {
						Interface::printError("Dato invalido.");
						system("PAUSE");
						Interface::cleanScreen();

						Interface::print("Mantenimiento de annios y ciclos lectivos\n");
						Interface::print("1- Ver ciclos lectivos");
						Interface::print("2- Ingresar ciclo lectivo");
						Interface::print("3- Volver");

						opcion1 = Interface::getInt();
					} while (opcion1 != 1 && opcion1 != 2 && opcion1 != 3);
				}
			}

		}break;
		case 2: {
			bool menu2 = true;
			while (menu2 == true) {
				Interface::cleanScreen();
				Interface::cleanTrash();

				Interface::print("Mantenimiento de carreras y cursos");
				Interface::print("1- Ingreso de carreras nuevas.");
				Interface::print("2- Ingresar cursos.");
				Interface::print("3- Volver.");

				int opcion2 = Interface::getInt();

				switch (opcion2) {
				case 1: {
					Interface::cleanScreen();
					this->u->addCareers();
				}break;
				case 2: {
					Interface::cleanScreen();
					this->u->addCourses();
				}break;
				case 3: {
					menu2 = false;
					Interface::cleanScreen();
				}
				}
			}
		}break;
		case 3: {
			bool menu3 = true;
			while (menu3 == true) {
				Interface::cleanScreen();
				Interface::cleanTrash();

				Interface::print("Empadronamiento.");
				Interface::print("1) Empadronamiento de estudiantes.");
				Interface::print("2) Mostrar estudiantes empadronados.");
				Interface::print("3) Volver.");


				int opcion3 = Interface::getInt(1, 3);


				switch (opcion3) {
				case 1: {
					Interface::cleanScreen();
					this->u->listing();
				}break;
				case 2: {
					Interface::cleanScreen();
					this->u->showListing();
				}break;
				case 3: {
					menu3 = false;
					Interface::cleanScreen();			
				}break;

				}
			}
		}break;
		case 4: {
			menu = false;
			Interface::cleanScreen();
		}
		}
	}
}
	
