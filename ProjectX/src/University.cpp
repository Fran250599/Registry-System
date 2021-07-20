#include "../include/University.h"

void University::createUser()
{
	Interface::cleanTrash();
	Interface::print("Se procedera a crear un usuario");

	Interface::print("Digite la identificacion");
	std::string id = Interface::getString();

	Interface::print("Digite el nombre");
	std::string name = Interface::getString();

	Interface::print("Digite la contrase�a");
	std::string password = Interface::getString();

	Interface::print("Defina el rol del usuario.");

	Interface::print("\n1- Administrador");
	Interface::print("\n2- Registro");
	Interface::print("\n3- Mantenimiento");
	Interface::print("\n4- Profesor");
	Interface::print("\n5- Estudiante");

	int rol = Interface::getInt();

	if (rol < 1 || rol > 5)
	{
		do
		{
			Interface::printError("Valor invalido.");
			system("PAUSE");

			Interface::cleanScreen();

			Interface::print("Defina el rol del usuario.");

			Interface::print("\n1- Administrador");
			Interface::print("2- Registro");
			Interface::print("3- Mantenimiento");
			Interface::print("4- Profesor");
			Interface::print("5- Estudiante");

			rol = Interface::getInt();

		} while (rol < 1 || rol > 5);
	}

	//Depends on the rol number it'll be added to this specific list

	switch (rol)
	{
	case 1:
	{
		Administrator *a1 = new Administrator(id, name, password, "Administrador");
		this->administradores->insert(a1);
	}
	break;
	case 2:
	{
		Register *r1 = new Register(id, name, password, "Registro");
		this->registros->insert(r1);
	}
	break;
	case 3:
	{
		Maintenance *m1 = new Maintenance(id, name, password, "Mantenimiento");
		this->mantenimientos->insert(m1);
	}
	break;
	case 4:
	{
		Professor *p1 = new Professor(id, name, password, "Profesor");
		this->profesores->insert(p1);
	}
	break;
	case 5:
	{
		Student *e1 = new Student(id, name, password, "Estudiante");
		this->estudiantes->insert(e1);
	}
	break;
	}

	Interface::printSuccess("Usuario creado con exito.");
	system("PAUSE");
	Interface::cleanScreen();
}

void University::showUsers()
{

	//This counter it'll check if the lists are empty
	int cont = 0;

	if (this->administradores->vacia() == false)
	{
		Interface::print("Administradores");
		Interface::print(this->administradores->toString());
		Interface::print("\n--------------------------\n");
	}
	else
	{
		cont++;
	}
	if (this->registros->vacia() == false)
	{
		Interface::print("Registro");
		Interface::print(this->registros->toString());
		Interface::print("\n--------------------------\n");
	}
	else
	{
		cont++;
	}
	if (this->mantenimientos->vacia() == false)
	{
		Interface::print("Mantenimiento");
		Interface::print(this->mantenimientos->toString());
		Interface::print("\n--------------------------\n");
	}
	else
	{
		cont++;
	}
	if (this->profesores->vacia() == false)
	{
		Interface::print("Profesores");
		Interface::print(this->profesores->toString());
		Interface::print("\n--------------------------\n");
	}
	else
	{
		cont++;
	}
	if (this->estudiantes->vacia() == false)
	{
		Interface::print("Estudiantes");
		Interface::print(this->estudiantes->toString());
		Interface::print("\n--------------------------\n");
	}
	else
	{
		cont++;
	}

	if (cont == 5)
	{
		Interface::printError("Todavia no hay usuarios registrados.");
	}

	system("PAUSE");
	Interface::cleanScreen();
}

void University::showYearsAndCycles()
{
	try
	{
		if (this->annios->vacia() == false)
		{
			Interface::print(this->annios->toString());
			system("PAUSE");
		}
		else
		{
			Interface::print("Lista vacia.");
			system("PAUSE");
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
}

void University::addYearsAndCycles()
{
	Interface::cleanTrash();

	Interface::print("Se creara un nuevo annio lectivo.");
	Interface::print("Recordemos que todo annio se compone de 3 ciclos.\n");

	Interface::print("Digite el annio que desea agregar: ");

	int annio = Interface::getInt();

	if (annio < 2021 || annio > 2041)
	{
		do
		{
			Interface::print("Annio invalido. Rango de 2021 a 2041.");
			Interface::print("Digite el annio que desea agregar: ");

			annio = Interface::getInt();
			Interface::cleanTrash();
			Interface::cleanScreen();

		} while (annio < 2021 || annio > 2041);
	}

	Year *newYear = new Year(annio);

	this->annios->insert(newYear);

	Interface::printSuccess("Se ha creado un nuevo annio con su primer ciclo lectivo.");

	Interface::print("\nPor favor digite la fecha de inicio del primer ciclo.");
	Interface::cleanTrash();
	std::string inicio = Interface::getString();
	newYear->setCycleBeginDate(0, inicio);

	Interface::print("Por favor digite la fecha de finalizacion del primer ciclo.");
	std::string final = Interface::getString();
	newYear->setCycleFinishDate(0, final);

	Interface::printSuccess("Primer ciclo agregado con exito. \n");
	Interface::print("Desea agregar el segundo ciclo lectivo? 1-Si 2-No");

	int opcion1 = Interface::getInt();

	if (opcion1 == 1 || opcion1 == 2)
	{
	validData:
		if (opcion1 == 1)
		{
			Interface::cleanTrash();
			Interface::print("\nPor favor digite la fecha de inicio del segundo ciclo.");
			std::string inicio1 = Interface::getString();
			newYear->setCycleBeginDate(1, inicio);

			Interface::print("Por favor digite la fecha de finalizacion del segundo ciclo.");
			std::string final1 = Interface::getString();
			newYear->setCycleFinishDate(1, final);

			Interface::printSuccess("Segundo ciclo agregado con exito. \n");

			// TERCER CICLO LECTIVO
			Interface::print("Desea agregar el tercer ciclo lectivo? 1-Si 2-No");

			int opcion2 = Interface::getInt();

			if (opcion2 == 1 || opcion2 == 2)
			{
			validData1:
				if (opcion2 == 1)
				{
					Interface::cleanTrash();
					Interface::print("\nPor favor digite la fecha de inicio del tercer ciclo.");
					std::string inicio2 = Interface::getString();
					newYear->setCycleBeginDate(2, inicio);

					Interface::print("Por favor digite la fecha de finalizacion del tercer ciclo.");
					std::string final2 = Interface::getString();
					newYear->setCycleFinishDate(2, final);

					Interface::printSuccess("Tercer ciclo agregado con exito. \n");
				}
			}
			else
			{
				do
				{
					Interface::printError("Dato invalido. Digite 1 o 2\n");
					Interface::print("Desea agregar el tercer ciclo lectivo? 1-Si 2-No");
					opcion2 = Interface::getInt();

					Interface::cleanScreen();

				} while (opcion2 != 1 && opcion2 != 2);

				goto validData1;
			}
		}
		Interface::cleanScreen();
	}
	else
	{
		do
		{
			Interface::printError("Dato invalido. Digite 1 o 2\n");
			Interface::print("Desea agregar el segundo ciclo lectivo? 1-Si 2-No");

			opcion1 = Interface::getInt();
			Interface::cleanScreen();

		} while (opcion1 != 1 && opcion1 != 2);

		goto validData;
	}
}

void University::addCareers()
{
	Interface::cleanTrash();

	Interface::print("Se proceder� a crear una nueva carrera.");

	Interface::print("Ingrese el codigo de la carrera: ");
	std::string code = Interface::getString();

	if (this->carreras->buscarEspecificoPorCodigo(code) == false)
	{

	codigoNuevo:
		Interface::print("Inserte el nombre de la carrera: ");
		std::string name = Interface::getString();

		if (this->carreras->buscarEspecificoPorNombre(name) == false)
		{
		carreraNueva:

			Interface::print("Ingrese el grado:");
			std::string grade = Interface::getString();

			Interface::print("Ingrese la escuela: ");
			std::string *school = Interface::getDynamicString();

			Interface::print("Ingrese la facultad: ");
			std::string *facultad = Interface::getDynamicString();

			Career *carrera1 = new Career(code, name, grade, school, facultad);

			this->carreras->insert(carrera1);

			Interface::printSuccess("Carrera creada con exito.");
			system("PAUSE");
			Interface::cleanScreen();
		}
		else
		{
			do
			{
				Interface::cleanScreen();

				Interface::printError("Este carrera ya existe.\n");

				Interface::print("Ingrese el nombre de la carrera.");
				name = Interface::getString();
			} while (this->carreras->buscarEspecificoPorCodigo(code) == true);
			goto carreraNueva;
		}
	}
	else
	{

		do
		{
			Interface::cleanScreen();

			Interface::printError("Este codigo ya esta en uso.\n");
			Interface::print("Ingrese el codigo de la carrera: ");
			code = Interface::getString();

		} while (this->carreras->buscarEspecificoPorCodigo(code) == true);
		goto codigoNuevo;
	}
}

void University::addCourses()
{

	Interface::cleanTrash();

	if (this->carreras->vacia() == false)
	{
		Interface::print("Digite el codigo de la carrera");
		std::string code = Interface::getString();

		if (this->carreras->buscarEspecificoPorCodigo(code) == true)
		{ //Verifies that the career exists

			Interface::cleanScreen();
			Career *auxCareer = this->carreras->obtenerElementoPorCodigo(code);

			Interface::print(auxCareer->getName());

			Interface::print("Digite el codigo del curso");
			std::string courseCode = Interface::getString();

			List<Courses *> *auxCourses = auxCareer->getCourses();

			//Now, we're going to verify that the course code isn't going to repeat
			if (auxCourses->buscarEspecificoPorCodigo(code) == false)
			{

				//If the course doesn't exist we're going to create it
				Interface::print("Digite el nombre del curso ");
				std::string courseName = Interface::getString();

				Interface::print("Digite el tipo de curso ");
				std::string courseType = Interface::getString();

				Interface::print("Cantidad de creditos ");
				int courseCredits = Interface::getInt();

				//If there are no courses yet we didn't need to ask for requisits courses
				if (auxCourses->vacia() == false)
				{

					Interface::print("Cantidad de cursos requisitos");

					int courseReqs = Interface::getInt();
					if (courseReqs < 1 || courseReqs > 3)
					{
						do
						{
							Interface::printError("La cantidad de cursos requisitos tiene un maximo de 3");
							courseReqs = Interface::getInt();
							Interface::cleanScreen();
						} while (courseReqs < 1 || courseReqs > 3);
					}

					std::vector<std::string> *auxReqs = new std::vector<std::string>();
					std::string auxString;

					for (int i = 0; i < courseReqs; i++)
					{
						Interface::print("Digite el codigo del curso requisito ");
						auxString = Interface::getString();

						if (auxCourses->buscarEspecificoPorCodigo(code) == true)
						{

						cursoRequisitoExistente:
							auxReqs->push_back(auxString);
						}
						else
						{
							do
							{
								Interface::cleanScreen();
								Interface::printError("El codigo no coincide con ningun curso.\n");

								Interface::print("Digite el codigo del curso requisito ");
								auxString = Interface::getString();

							} while (auxCourses->buscarEspecificoPorCodigo(code) == false);
							goto cursoRequisitoExistente;
						}
					}
					Interface::print("Horas semanales (Entre 1 y 10)");
					int weeklyHours = Interface::getInt();

					Courses *newCourse = new Courses(code, courseName, courseType, courseCredits, courseReqs, weeklyHours, auxReqs);
					auxCourses->insert(newCourse);
				}
				else
				{
					Interface::print("Horas semanales (Entre 1 y 10)");
					int weeklyHours2 = Interface::getInt();

					Courses *newCourse2 = new Courses(code, courseName, courseType, courseCredits, 0, weeklyHours2, 0);
					auxCourses->insert(newCourse2);

					Interface::printSuccess("Curso agregado con exito.");
					system("PAUSE");
					Interface::cleanScreen();
				}
			}
		}
		else
		{
			Interface::printError("Carrera inexistente.");
			system("PAUSE");
		}
	}
	else
	{
		Interface::printError("Todavia no se han ingresado carreras.");
		Interface::cleanScreen();
	}
}

void University::listing()
{ //We're going to listing students in a career
	Interface::cleanTrash();
	try
	{
		if (!this->carreras->vacia())
		{ //If any career is on the system this method isn't going to be executed
			if (!this->estudiantes->vacia())
			{ //If any student is on the system this method isn't going to be executed
				Interface::print("Se procedera a registrar un estudiante a una carrera \n");

				Interface::print("Digite el numero de cedula: ");
				std::string id = Interface::getString();

				Student *auxStudent = new Student();
				auxStudent->setId(id);

				if (this->estudiantes->buscarEspecificoPorId(id) == true)
				{
					auxStudent = this->estudiantes->obtenerElementoPorId(id);

					Interface::print("Digite el numero de telefono del estudiante");
					std::string phoneNumber = Interface::getString();
					auxStudent->setPhoneNumber(phoneNumber);

					Interface::print("Conoce el codigo de la carrera? 1) Si 2) No");

					int opcion = Interface::getInt(1, 2);
					Interface::cleanTrash();

					if (opcion == 1)
					{
						Interface::print("Por favor digite el codigo ");
						std::string code = Interface::getString();

						if (this->carreras->buscarEspecificoPorCodigo(code) == true)
						{

							//We're going to add the Student to this career students list
							Career *auxCareer = this->carreras->obtenerElementoPorCodigo(code);
							List<Student *> *careerStudentsList = auxCareer->getStudents();
							careerStudentsList->insert(auxStudent);

							//Now, we save the career code in the student information in case we need it in the future
							auxStudent->setCareerCode(code);

							Interface::printSuccess("Estudiante anadido a la carrera de");
							Interface::print(auxCareer->getName());
						}
					}
					else if (opcion == 2)
					{

						int aux = this->carreras->getCantidad();
						if (aux > 0)
						{

							Interface::print("Estas son las carreras disponibles en este momento. ");

							for (int i = 0; i < aux; i++)
							{
								Career *aux = this->carreras->obtenerElemento(i);
								Interface::print(i + ") " + aux->getName());
							}
						}
						else
						{
							Interface::print("No hay carreras disponibles en este momento.");
						}
					}
				}

				else
				{
					Interface::printError("Esta persona no esta registrada en la malla curricular.");
					system("PAUSE");
					Interface::cleanScreen();
				}
			}
			else
			{
				Interface::printError("Todavia no hay estudiantes en el sistema.");
				system("PAUSE");
				Interface::cleanScreen();
			}
		}
		else
		{
			Interface::printError("Todavia no hay carreras registradas.");
			system("PAUSE");
			Interface::cleanScreen();
		}
	}
	catch (std::exception e)
	{
		Interface::print(e.what());
	}
}

void University::showListing()
{
	try
	{

		int i = 0;
		Career *auxCareer = new Career();

		if (!this->carreras->vacia())
		{
			if (!auxCareer->getStudents()->vacia())
			{

				Interface::print("Se procedera a enlistar a todos los estudiantes en sus respectivas carreras");
				while (i < this->carreras->getCantidad())
				{

					auxCareer = this->carreras->obtenerElemento(i);
					Interface::print("------------------------------");
					Interface::print(auxCareer->getName());

					List<Student *> *auxStudents = auxCareer->getStudents();

					Interface::print(auxStudents->toString());

					Interface::print("------------------------------");

					i++;
				}
				system("PAUSE");
			}
			else
			{
				Interface::print("------------------------------");
				Interface::print(auxCareer->getName());
				Interface::print("Todavia no hay estudiantes empadronados en esta carrera.");

				Interface::print("------------------------------");
				i++;
			}
		}
		else
		{
			Interface::print("Todavia no hay carreras registradas.");
			system("PAUSE");
		}
		system("PAUSE");
	}
	catch (std::exception e)
	{
		Interface::print(e.what());
	}
}

//This method will show the specified career study plan
void University::showStudyPlan()
{

	Interface::cleanScreen();
	Interface::cleanTrash();

	try{
		if (!this->carreras->vacia()){
			Interface::print("Digite el codigo de carrera: ");
			std::string careerCode = Interface::getString();

			if (this->carreras->buscarEspecificoPorCodigo(careerCode)){
				if (!this->carreras->vacia())
				{
					Career *auxCareer = this->carreras->obtenerElementoPorCodigo(careerCode);

					Interface::print("Carrera: " + auxCareer->getName());
					Interface::print("Tipo: " + auxCareer->getGrade());
					Interface::print("\nPlan de estudios \n");

					List<Courses *> *auxCourses = auxCareer->getCourses();
					int cant = auxCourses->getCantidad();
					int i = 0;

					while (i < cant){

						Courses *auxCourse = auxCourses->obtenerElemento(i);

						Interface::print(auxCourse->studyPlanString());
						i++;
					}
					system("PAUSE");
				}
				else
				{
					Interface::printError("Esta carrera no tiene cursos ingresados.");
					system("PAUSE");
					Interface::cleanScreen();
					Interface::cleanTrash();
				}
			}
			else
			{
				Interface::printError("Esta carrera no existe.");
				system("PAUSE");
				Interface::cleanScreen();
			}
		}
		else
		{
			Interface::printError("Todavia no hay carreras registradas.");
			system("PAUSE");
			Interface::cleanScreen();
		}
	}
	catch (std::exception e)
	{
		Interface::print(e.what());
		system("PAUSE");
		Interface::cleanScreen();
	}
}

void University::groupCreation()
{
	Interface::cleanScreen();
	Interface::cleanTrash();

	try
	{
		Interface::print("Digite el codigo de carrera: ");
		std::string careerCode = Interface::getString();

		Career *auxCareer = this->carreras->obtenerElementoPorCodigo(careerCode);

		Interface::print("Digite el annio: ");
		std::string year = Interface::getString();

		if (this->annios->buscarEspecificoPorId(year))
		{ ///Comprobacion de ciclos lectivos.
			Year *auxYear = this->annios->obtenerElementoPorId(year);

			Interface::print("Digite el periodo lectivo (I, II o III)");
			std::string cycle = Interface::getString();

			std::vector<Cycle *> *cycles1 = auxYear->getCycles();

			for (int i = 0; i < 3; i++)
			{
				if (cycles1->at(i) != nullptr)
				{
					if (cycles1->at(i)->getId() == cycle)
					{
						Interface::print("Digite el codigo del curso: ");
						std::string courseCode = Interface::getString();

						if (auxCareer->getCourses()->buscarEspecificoPorCodigo(courseCode) != false)
						{
							Courses *auxCourse = auxCareer->getCourses()->obtenerElementoPorCodigo(courseCode);
							List<Group *> *auxCourseGroups = auxCourse->getGroups();
							List<Group *> *auxCycleGroups = cycles1->at(i)->getGroups();

							if (auxCycleGroups->getCantidad() != 0)
							{
								Interface::print("Actualmente existen los siguientes grupos del curso" + courseCode);
								int aux = auxCycleGroups->getCantidad();
								int j = 0;
								while (aux > 0)
								{
									Group *auxCycleGroup = auxCycleGroups->obtenerElemento(j);

									std::string _ncr = Interface::intToString(auxCycleGroup->getNCR());
									std::string _nGroup = Interface::intToString(auxCycleGroup->getNGroup());
									std::string _cupo = Interface::intToString(auxCycleGroup->getCupo());

									Interface::print("Curso			NCR		Grupo	Profesor		Cupo	Horario");
									Interface::printTab1(auxCourse->getCode());
									Interface::printTab1(auxCourse->getName());
									Interface::printTab1(_ncr);
									Interface::printTab1(_nGroup);
									Interface::printTab2(auxCycleGroup->getProfessor());
									Interface::printTab1(_cupo);
									Interface::printTab1(auxCycleGroup->getSchedule());

									aux--;
									j++;
								}
							}

							Interface::print("Cuantos grupos desea agregar: ");
							int nGroups = Interface::getInt();

							Group *auxGroup = new Group();

							std::string courseCode = auxCourse->getCode();

							while (nGroups > 0)
							{

								//NCR
								srand(time(NULL));
								int NCR = rand() % (50000 - 40000 + 1) + 40000;
								Interface::print("NCR: " + NCR);

								//# of group
								int nOfGroup = (auxCycleGroups->getCantidad());
								nOfGroup++;
								{
								}

								Interface::print("Grupo: " + nOfGroup);

								//Professor
								std::string professor = Interface::getString();
								if (this->profesores->buscarEspecificoPorId(professor))
								{
									Professor *auxTeacher = this->profesores->obtenerElementoPorId(professor);

									Interface::print("Profesor " + auxTeacher->getName());

									//Cupo
									Interface::print("Cupo deseado: ");
									int cupo = Interface::getInt();

									//Horario
									Interface::print("Horario:");
									std::string schedule = Interface::getString();

									//Creation of the new group
									Group *auxGroup = new Group(courseCode, NCR, nOfGroup, auxTeacher, cupo, schedule, careerCode);

									//Adding group to respective Lists
									auxCourseGroups->insert(auxGroup);
									auxCycleGroups->insert(auxGroup);

									Interface::printSuccess("Grupo creado exitosamente.");
								}
								else
								{
									Interface::printError("No existe este profesor.");
									system("PAUSE");
								}

								nGroups--;
							}
						}
						else
						{
							Interface::print("Este curso no existe en esta carrera.");
							//Desea intentarlo de nuevo? ...

							system("PAUSE");
						}
					}
				}
			}
		}
		else
		{
			Interface::printError("Este annio no ha sido registrado en el sistema.");
			system("PAUSE");
		}
	}
	catch (std::exception e)
	{
		Interface::print(e.what());
		system("PAUSE");
	}
}

//Consulta general de matricula.
/*
Este módulo solicita la carrera, ciclo lectivo y NCR mostrando así los cursos y
la cantidad de grupos abiertos. Una vez seleccionado el curso deseado,se deberá
mostrar el listado de grupos detallando para cada uno: numero de grupo, horario, NCR,
profesor, capacidad, cupos disponibles. */

void University::generalStudiesRequest()
{
	try
	{
		Interface::print("Consulta general de matricula.\n");

		Interface::print("Digite el codigo de carrera.");
		std::string careerCode = Interface::getString();

		if (this->carreras->buscarEspecificoPorCodigo(careerCode))
		{
			Career *career1 = new Career();
			career1 = this->carreras->obtenerElementoPorCodigo(careerCode);

			Interface::print("Carrera: ");
			Interface::print(career1->getName());
			Interface::print("Digite el annio:");

			std::string year = Interface::getString();

			if (this->annios->buscarEspecificoPorId(year))
			{
				Year *year1 = this->annios->obtenerElementoPorId(year);

				Interface::print("Digite el periodo lectivo (I, II o III)");
				std::string cycle = Interface::getString();

				if (cycle == "I" || "II" || "III")
				{
				true1:
					std::vector<Cycle *> *cycles1 = year1->getCycles();

					for (int i = 0; i < 3; i++)
					{
						if (cycles1->at(i) != nullptr)
						{
							if (cycles1->at(i)->getId() == cycle)
							{

								Cycle *auxCycle = cycles1->at(i);
								Interface::print("Oferta para el periodo " + cycles1->at(i)->getId() + "-" + year1->getId());

								Interface::print("\nNCR		Grupo	Curso		Profesor		Cupo	Horario");
							}
						}
						else
						{
							Interface::print("Ciclo " + Interface::intToString(i) + " no ha sido ingresado al sistema todavia.");
						}
					}
				}
				else
				{
					do
					{
						Interface::cleanScreen();
						Interface::printError("Dato invalido. Digite I, II o III");
						cycle = Interface::getString();

					} while (cycle != "I" || "II" || "III");
					goto true1;
				}
			}
		}
		else
		{
			Interface::printError("Carrera inexistente.");
		}
	}
	catch (std::exception e)
	{
		Interface::printError(e.what());
		system("PAUSE");
	}
}
