#include <iostream>
#include "Character.hpp"
#include "HarryPotter.hpp"
#include <stdlib.h>


HarryPotter::HarryPotter() :Character(0, 10) {
	isAlive = true;
	charName = "Harry Potter";
	deathCount = 0;
}


void HarryPotter::attack(Character* defender) {
	int attackRoll = 0;
	for (int x = 0; x < 2; ++x) {
		attackRoll += 1 + rand() % 6;
	}
	std::cout << "Harry Potter has rolled a " << attackRoll << " for attack " << std::endl;
	defender->defend(attackRoll);
}

void HarryPotter::defend(int roll) {
	int defenseRoll = 0;
	for (int i = 0; i < 2; ++i) {
		defenseRoll += 1 + rand() % 6;
	}
	int damage = roll - defenseRoll - this->armor;
	std::cout << "Harry Pooter rolled a " << defenseRoll << " in defense" << std::endl;
	this->damageIN(damage);
}


void HarryPotter::damageIN(int x) {
	strength -= x;
	std::cout << "Harry Potter took " << x << " points of damage" << std::endl;
	if (strength <= 0 && deathCount == 0) {
		this->strength = 20;
		deathCount = 1;
		std::cout << "Harry Potter has died but came back to life wil 20 strength points" << std::endl;
	}
	else if (strength <= 0 && deathCount != 0) {
		std::cout << "Harry Potter has died for good." << std::endl;
		isAlive = false;
	}
}


void HarryPotter::medusaCharm() {
	this->damageIN(this->strength);
}
