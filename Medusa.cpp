#include <iostream>
#include "Character.hpp"
#include "Medusa.hpp"
#include <stdlib.h>


Medusa::Medusa() :Character(3,8){
	isAlive = true;
	charName = "Medusa";
}


void Medusa::attack(Character* defender) {
	int attackRoll = 0;
	for (int x = 0; x < 2; ++x) {
		attackRoll = 1 + rand() % 6;
	}
	std::cout << "Medusa Rolled a " << attackRoll << " for attack" << std::endl;
	if (attackRoll == 12) {
		defender->medusaCharm();
	}
	else {
		std::cout << "Medusa has glared at her opponet" << std::endl;
		defender->defend(attackRoll);
	}
	
}


void Medusa::defend(int roll) {
	int defendRoll = 1 + rand() % 6;
	std::cout << "Medusa rolled a " << defendRoll << " in defense" << std::endl;
	int damage = roll - defendRoll - this->armor;
	if (damage < 0) {
		damage = 0;
	}
	this->damageIN(damage);
}


void Medusa::damageIN(int x) {
	strength -= x;
	if (strength <= 0) {
		std::cout << "Medusa has died" << std::endl;
		isAlive = false;
	}

}


void Medusa::medusaCharm() {
	std::cout << "Medusa has turned the defender to stone" << std::endl;
	this->damageIN(this->strength);
}

