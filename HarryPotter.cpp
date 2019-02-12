#include <iostream>
#include "Character.hpp"
#include "HarryPotter.hpp"
/***************************************************************
Program: HarryPotter.cpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the HarryPotter class definitions which is
inherited from character class.
***************************************************************/
#include <stdlib.h>
#include <string>
#include <iomanip>

HarryPotter::HarryPotter() :Character(0, 10) {
	//isAlive = true;
	charName = "Harry Potter";
	deathCount = 0;
}


void HarryPotter::attack(Character* defender) {
	int attackRoll = 0;
	for (int x = 0; x < 2; ++x) {
		attackRoll += 1 + rand() % 6;
	}
	std::cout << "Harry's Attacking Roll: " << attackRoll << std::endl;
	defender->defend(attackRoll);
}

void HarryPotter::defend(int roll) {
	int defenseRoll = 0;
	for (int i = 0; i < 2; ++i) {
		defenseRoll += 1 + rand() % 6;
	}
	int damage = roll - defenseRoll - this->armor;
	if (damage < 0) {
		damage = 0;
	}
	std::cout << "Harry's Defending Roll: " << defenseRoll << std::endl;
	std::cout << "Total Damage: " << damage << std::endl;
	this->damageIN(damage);
}


void HarryPotter::damageIN(int x) {
	strength -= x;

	if (strength > 0) {
		std::cout << "Harry has " << strength << " points of strength" << std::endl;
	}
	if (strength <= 0 && deathCount == 0) {
		this->strength = 20;
		deathCount = 1;
		//std::cout << "Harry Potter took " << x << " points of damage" << std::endl;
		std::cout << "Harry Potter has died but came back to life wil 20 strength points" << std::endl;
	}
	else if (strength <= 0 && deathCount != 0) {
		strength = 0;
		//std::cout << "Harry Potter took " << x << " points of damage" << std::endl;
		std::cout << "Harry Potter has " << strength << " points of strength" << std::endl;
		std::cout << "Harry Potter has died for good." << std::endl;
		strength = 0;
		isAlive = false;
	}
}


/*void HarryPotter::medusaCharm() {
	this->damageIN(this->strength);
}
*/


