#include <iostream>
#include "Character.hpp"
#include "Vampire.hpp"
#include <stdlib.h>


Vampire::Vampire() : Character(1,18,12,6){
	isAlive = true;
	charName = "Vampire";

}

void Vampire::attack(Character *defender) {
	int attackRoll = 1 + rand() % attackDie;
	std::cout << "Vampire rolls " << attackRoll << " points of damage to " << defender->getName() << std::endl;
	defend(attackRoll);
	
}

int Vampire::defend(int roll) {
	int defendRoll = 1 + rand() % defenseDie;
	std::cout << "The vampire rolled " << defendRoll << " points to defend the attack" << std::endl;
	if (defendRoll > 3) { //activate charm
		std::cout << "The vampire was able to charm the attacker." <<
			" There attack will be useless against this defense" << std::endl;
	}
	else {
		int damage = roll - defendRoll - this->armor; //calculate damage 
		damageIN(damage); //add damage
		std::cout << "The vampire takes " << damage << " points of damage" << std::endl;
	}
	return defendRoll;
}


void Vampire::damageIN(int x) {
	strength -= x;
	std::cout << "The vampire now has " << this->strength << " points left." << std::endl;
	if (strength >= 0) {
		this->isAlive = false;
		std::cout << "The vampire has died" << std::endl;
	}
}




void Vampire::medusaCharm() {
	int defendRoll = 1 + rand() % defenseDie;
	if (defendRoll > 3) {
		std::cout << "The vampire was able to charm Medusa." <<
			" Glare will be useless against the vampire's charm" << std::endl;
	}
	else {
		damageIN(this->strength);
		std::cout << "Vampire has been turned to stone!" << std::endl;
	}
}