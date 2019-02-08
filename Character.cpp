#include <iostream>
#include "Character.hpp"
#include <string>
#include <iomanip>


Character::Character(int armorNum, int strengthNum) {
	armor = armorNum;
	strength = strengthNum;
	isAlive = true;
	//charName = name;
}

bool Character::check_isAlive() {
	return isAlive;
}

std::string Character::getName() {
	return charName;
}

int Character::getStrengthPoints() {
	return strength;
}


int Character::getArmor() {
	return armor;
}


void Character::setName(std::string name) {
	charName = name;
}


void Character::printInfo(){
//std::cout << "\n-----------------------------------------" << std::endl;
//std::cout << "|----------------------------------------" << std::endl;
std::cout << "|" << std::left << std::setw(11) << charName
<< std::right << std::setw(5) << armor << std::setw(9) << strength << std::setw(14) << "|" <<
std::endl;
std::cout << "-----------------------------------------" << std::endl;
}