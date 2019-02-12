/***************************************************************
Program: Vampire.cpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the Vampire class definitions which is
inherited from character class.
***************************************************************/
#include <iostream>
#include "Character.hpp"
#include "Vampire.hpp"
#include <stdlib.h>
#include <string>
#include <iomanip>


Vampire::Vampire() : Character(1,18){
	//isAlive = true;
	setName("Vampire");

}

void Vampire::attack(Character *defender) {
	int attackRoll = 1 + rand() % 12;
	std::cout << "Vampire's Attacking Roll: " << attackRoll << std::endl;
	defender->defend(attackRoll);
	
}

void Vampire::defend(int roll) {
	int defendRoll = 1 + rand() % 6;
	std::cout << "Vampire's Defending Roll: " << defendRoll << std::endl;
	if (defendRoll > 3) { //activate charm
		std::cout << "The vampire was able to charm the attacker." <<
			"\n There attack will be useless against this defense" << std::endl;
	}
	else if (roll !=100 && defendRoll <=3){
		int damage = roll - defendRoll - this->armor; //calculate damage 
		if (damage < 0) {
			damage = 0;
		}
		std::cout << "Total Damage: " << damage << std::endl;
		std::cout << "The vampire takes " << damage << " points of damage" << std::endl;
		damageIN(damage); //add damage
		
	}
	else if (roll ==100) {
		std::cout << " The vampire was unable to charm Medusa's glare" << std::endl;
		damageIN(100000);
	}
	
}


void Vampire::damageIN(int x) {
	strength -= x;
	
	if (strength <= 0) {
		strength = 0;
		this->isAlive = false;
		std::cout << "The vampire now has " << this->strength << " strength points." << std::endl;
		std::cout << "The vampire has died" << std::endl;
	}
	else {
		std::cout << "The vampire now has " << this->strength << " points left." << std::endl;
	}
}




/*void Vampire::medusaCharm() {
	int defendRoll = 1 + rand() % 6;
	if (defendRoll > 3) {
		std::cout << "The vampire was able to charm Medusa." <<
			" Glare will be useless against the vampire's charm" << std::endl;
	}
	else {
		damageIN(this->strength);
		std::cout << "Vampire has been turned to stone!" << std::endl;
	}
}
*/

