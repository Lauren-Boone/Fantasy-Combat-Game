#include <iostream>
#include "Character.hpp"
#include "BlueMen.hpp"
#include <stdlib.h>

BlueMen::BlueMen() : Character(3, 12, 10, 6) {
	numDefense_die = 3;
	charName = "Blue Men";
}


void BlueMen::attack(Character* defender) {
	int attackRoll=0;
	for (int x = 0; x < 2; ++x) {
		attackRoll += 1 + rand() % 10;
	}
	std::cout << "Blue men rolled " << attackRoll << " points in attack" << std::endl;
	defender->defend(attackRoll);
}


int BlueMen::defend(int roll) {
	int defenseRoll = 0;
	for (int i = 0; i < numDefense_die; ++i) {
		defenseRoll += 1 + rand() % 6;
	}
	std::cout << "Blue men rolled " << defenseRoll << " in defending" << std::endl;
	int damage = roll - defenseRoll - this->armor;
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
	std::cout << "Blue Men take " << x << " points of damage. \nStrength is " << strength << std::endl;
	if (strength <= 0) {
		std::cout << "The blue men have died" << std::endl;
		isAlive = false;
	}
}



void BlueMen::medusaCharm() {
	std::cout << "the blue men have been turned to stone" << std::endl;
	damageIN(this->strength);
}

