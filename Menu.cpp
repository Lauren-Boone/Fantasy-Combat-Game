#include <iostream>
#include "Menu.hpp"
#include <string>
#include <vector>
#include <iomanip>


Menu::Menu() {

}

void Menu::addChoice(std::string input) {
	menu.push_back(input);
}

void Menu::printMenu() {
	for (int i = 0; i < menu.size(); ++i) {
		std::cout << "* " << std::left << std::setw(38) << menu[i] << "*" << std::endl;
	}
	std::cout << "*****************************************" << std::endl;
}