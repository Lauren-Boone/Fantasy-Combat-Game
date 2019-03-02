/***************************************************************
Program: Character.cpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the Character class which is a base class for
all the different characters.
***************************************************************/
#include <iostream>
#include "Character.hpp"
#include <string>
#include <iomanip>
#include <stdlib.h>


Character::Character(int armorNum, int strengthNum, std::string name) {
	armor = armorNum;
	strength = strengthNum;
	isAlive = true;
	setName(name);
}

Character::~Character()
{

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



std::string Character::getType() {
	return type;
}

void Character::setName(std::string name) {
	charName = name;
}



void Character::setStrength(int num) {
	strength += num;
	std::cout << "Points Recovered during rest: " << num << std::endl;
	std::cout << "Total Strength " << strength << std::endl;
}

/***********************************************
This function is used to print the defender/attacker
infor before battle
***************************************************/
void Character::printInfo(){
std::cout << "*|" << std::left << std::setw(11) << charName
<< std::right << std::setw(5) << armor << std::setw(9) << strength << std::setw(14) << " |*" <<
std::endl;
std::cout << "*---------------------------------------*" << std::endl;
}



/***********************************************
recoverPoints()
This functiosn randomly recovers a certain amount
of strength points for a character
************************************************/
void Character::recoverPoints(Character* player) {
	int random= 1 + rand() % 5;
	player->setStrength(random);
}