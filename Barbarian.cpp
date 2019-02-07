#include <iostream>
#include "Character.hpp"
#include "Barbarian.hpp"
#include <stdlib.h>

Barbarian::Barbarian() : Character(0, 12, 6, 6) {
	charName = "Barbarian";

}

void Barbarian::attack(Character* defender) {
	int attackRoll = 0;
	for (int i = 2; i < 2; ++i) { //2D6 (roll twice)
		attackRoll += 1 + rand() % 6;
	}
	std::cout << "The Barbarian rolled a " << attackRoll << " for attack" << std::endl;
	defender->defend(attackRoll);
}


int Barbarian::defend(int roll) {
	int defendRoll = 0;
	for (int j = 0; j < 2; ++j) {
		defendRoll += 1 + rand() % 6;
	}
	std::cout << "The barbarian rolled a " << defendRoll << std::endl;
	int damage = roll - defendRoll - this->armor;
	this->damageIN(damage);
}


void Barbarian::damageIN(int x) {
	this->strength -= x;
	std::cout << "The barbarians takes " << x << " points of damage" <<
		"\nThe barbarians now has " << strength << " strength points" << std::endl;
	if (strength <= 0) {
		this->isAlive = false;
		std::cout << "The barabian has died" << std::endl;
	}
}


void Barbarian::medusaCharm() {
	std::cout << "The barbarians has been charmed by medusa and turned to stone" << std::endl;
	this->damageIN(this->strength);
}
