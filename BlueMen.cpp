/***************************************************************
Program: BlueMen.cpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the blueMen class definitions which is
inherited from character class.
***************************************************************/
#include <iostream>
#include "Character.hpp"
#include "BlueMen.hpp"
#include <stdlib.h>
#include <string>
#include <iomanip>

BlueMen::BlueMen() : Character(3, 12) {
	numDefense_die = 3;
	charName = "Blue Men";
	
}


void BlueMen::attack(Character* defender) {
	int attackRoll=0;
	for (int x = 0; x < 2; ++x) {
		attackRoll += 1 + rand() % 10;
	}
	std::cout << "Blue Men's Attacking Roll: " << attackRoll << std::endl;
	defender->defend(attackRoll);
}


void BlueMen::defend(int roll) {
	int defenseRoll = 0;
	for (int i = 0; i < numDefense_die; ++i) {
		defenseRoll += 1 + rand() % 6;
	}
	std::cout << "Blue Men's Defense Roll: " << defenseRoll << std::endl;
	int damage = roll - defenseRoll - this->armor;
	if (damage < 0) {
		damage = 0;
	}
	std::cout << "Total Damage: " << damage << std::endl;
	this->damageIN(damage);

}


void BlueMen::damageIN(int x) {
	strength -= x;
	if (x >= 4) { //mob
		numDefense_die--;
	}
	else if (x >= 8) {
		numDefense_die -= 2;
	}
	else if (x >= 12) {
		numDefense_die -= 3;
	}
	
	if (strength <= 0) {
		strength = 0;
		std::cout << "Blue Men take " << x << " points of damage. \nStrength is " << strength << std::endl;
		std::cout << "The blue men have died" << std::endl;
		isAlive = false;
	}
	else {
		std::cout << "Blue Men take " << x << " points of damage. \nStrength is " << strength << std::endl;
	}
}



/*void BlueMen::medusaCharm() {
	std::cout << "the blue men have been turned to stone" << std::endl;
	damageIN(this->strength);
}
*/



