#include <iostream>
#include <sstream>

#include "../include/Menu.h"

int main() {

	Menu* menu1 = new Menu();

	menu1->menuPrincipal();

	delete menu1;
	system("PAUSE");
	return 0;
}