/***************************************************************
Program: Medusa.cpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the Medusa class definitions which is
inherited from character class.
***************************************************************/
#include <iostream>
#include "Character.hpp"
#include "Medusa.hpp"
#include <stdlib.h>
#include <string>
#include <iomanip>

Medusa::Medusa() :Character(3,8){
	//isAlive = true;
	charName = "Medusa";
}


void Medusa::attack(Character* defender) {
	int attackRoll = 0;
	for (int x = 0; x < 2; ++x) {
		attackRoll += 1 + rand() % 6;
	}
	std::cout << "Medusa's Attacking Roll: " << attackRoll << std::endl;
	
	if (attackRoll == 12 && defender->getName() !="Vampire") {
		std::cout << "Medusa has glared at her opponet" << std::endl;
		defender->damageIN(1000);
	}
	else if (attackRoll == 12 && defender->getName() == "Vampire") {
		std::cout << "Medusa has glared at her opponet" << std::endl;
		defender->defend(100);
	}
	else {
		defender->defend(attackRoll);
	}
	
}


void Medusa::defend(int roll) {
	int defendRoll = 1 + rand() % 6;
	std::cout << "Medusa's Defending Roll: " << defendRoll << std::endl;;
	int damage = roll - defendRoll - this->armor;
	if (damage < 0) {
		damage = 0;
	}
	std::cout << "Total Damage: " << damage << std::endl;
	std::cout << "Medusa takes " << damage << " points of damage" << std::endl;
	this->damageIN(damage);
}


void Medusa::damageIN(int x) {
	strength -= x;
	
	if (strength <= 0) {
		strength = 0;
		std::cout << "Medusa has " << strength << " strength points" << std::endl;
		std::cout << "Medusa has died" << std::endl;
		isAlive = false;
	}
	else {
		std::cout << "Medusa has " << strength << " strength points" << std::endl;
	}

}

/*
void Medusa::medusaCharm() {
	std::cout << "Medusa has turned the defender to stone" << std::endl;
	this->damageIN(this->strength);
}
*/

