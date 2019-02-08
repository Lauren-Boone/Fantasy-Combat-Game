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
		attackRoll = 1 + rand() % 6;
	}
	std::cout << "Attack: Medusa Rolled a " << attackRoll << " for attack" << std::endl;
	if (attackRoll == 12) {
		std::cout << "Medusa has glared at her opponet" << std::endl;
		defender->medusaCharm();
	}
	else {
		defender->defend(attackRoll);
	}
	
}


void Medusa::defend(int roll) {
	int defendRoll = 1 + rand() % 6;
	std::cout << "Defend: Medusa rolled a " << defendRoll << " in defense" << std::endl;
	int damage = roll - defendRoll - this->armor;
	if (damage < 0) {
		damage = 0;
	}
	std::cout << "Medusa takes " << damage << " points of damage" << std::endl;
	this->damageIN(damage);
}


void Medusa::damageIN(int x) {
	strength -= x;
	std::cout << "Medusa has " << strength << " strength points" << std::endl;
	if (strength <= 0) {
		strength = 0;
		std::cout << "Medusa has died" << std::endl;
		isAlive = false;
	}

}


void Medusa::medusaCharm() {
	std::cout << "Medusa has turned the defender to stone" << std::endl;
	this->damageIN(this->strength);
}

