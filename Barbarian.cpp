#include <iostream>
#include "Character.hpp"
#include "Barbarian.hpp"
/***************************************************************
Program: Barbarian.cpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the Barbarian class definitions which is 
inherited from character class.
***************************************************************/
#include <stdlib.h>
#include <string>
#include <iomanip>

Barbarian::Barbarian(std::string name) : Character(0, 12, name) {
	
}
/*************************************
attack()
This functions has instructions for
how the Barbarian will attack
*******************************************/
void Barbarian::attack(Character* defender) {
	int attackRoll = 0;
	for (int i = 0; i < 2; ++i) { //2D6 (roll twice)
		attackRoll += 1 + rand() % 6;
	}
	std::cout << "Barbarian's Attacking Roll: " << attackRoll << std::endl;
	defender->defend(attackRoll);
}

/*********************************************
defend()
This functions has instructions for how the
barbarian defends attacks based on their roll
damage is calculated and sent to damageIn()
*******************************************/
void Barbarian::defend(int roll) {
	int defendRoll = 0;
	for (int j = 0; j < 2; ++j) {
		defendRoll += 1 + rand() % 6;
	}
	std::cout << "Barbarian's Defending Roll: " << defendRoll << std::endl;
	int damage = roll - defendRoll - this->armor;
	if (damage < 0) {
		damage = 0;
	}
	std::cout << "Total Damage: " << damage << std::endl;
	this->damageIN(damage);
}


/********************************
damageIn
This functions calculates strength
based on damage. If strength is 0
the character isAlive = false;
********************************/
void Barbarian::damageIN(int x) {
	this->strength -= x;
	if (strength > 0) {
		std::cout << "The barbarians now has " << strength << " strength points" << std::endl;
	}
	else if (strength <= 0) {
		strength = 0;
		this->isAlive = false;
		std::cout << "The barabian has died" << std::endl;
	}
}


