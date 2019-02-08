#include <iostream>
#include "Character.hpp"
#include "Barbarian.hpp"
#include <stdlib.h>
#include <string>
#include <iomanip>

Barbarian::Barbarian() : Character(0, 12) {
	charName = "Barbarian";

}

void Barbarian::attack(Character* defender) {
	int attackRoll = 0;
	for (int i = 0; i < 2; ++i) { //2D6 (roll twice)
		attackRoll += 1 + rand() % 6;
	}
	std::cout << "Attack: The Barbarian rolled a " << attackRoll << " for attack" << std::endl;
	defender->defend(attackRoll);
}


void Barbarian::defend(int roll) {
	int defendRoll = 0;
	for (int j = 0; j < 2; ++j) {
		defendRoll += 1 + rand() % 6;
	}
	std::cout << "Defend: The barbarian rolled a " << defendRoll << " in defense\n" << std::endl;
	int damage = roll - defendRoll - this->armor;
	if (damage < 0) {
		damage = 0;
	}
	this->damageIN(damage);
}


void Barbarian::damageIN(int x) {
	this->strength -= x;
	std::cout << "The barbarian takes " << x << " points of damage" <<
		"\nThe barbarians now has " << strength << " strength points" << std::endl;
	if (strength <= 0) {
		strength = 0;
		this->isAlive = false;
		std::cout << "The barabian has died" << std::endl;
	}
}


void Barbarian::medusaCharm() {
	std::cout << "The barbarians has been charmed by medusa and turned to stone" << std::endl;
	this->damageIN(this->strength);
}

