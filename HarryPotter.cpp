/***************************************************************
Program: HarryPotter.cpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the HarryPotter class definitions which is
inherited from character class.
***************************************************************/
#include <iostream>
#include "Character.hpp"
#include "HarryPotter.hpp"
#include <stdlib.h>
#include <string>
#include <iomanip>

HarryPotter::HarryPotter(std::string name) :Character(0, 10, name) {
	//isAlive = true;
	
	deathCount = 0;
}

/*************************************
attack()
This functions has instructions for
how the Harry will attack
*******************************************/
void HarryPotter::attack(Character* defender) {
	int attackRoll = 0;
	for (int x = 0; x < 2; ++x) {
		attackRoll += 1 + rand() % 6;
	}
	//std::cout << "Harry's Attacking Roll: " << attackRoll << std::endl;
	defender->defend(attackRoll);
}

/*********************************************
defend()
This functions has instructions for how the
Harry defends attacks based on their roll
damage is calculated and sent to damageIn()
*******************************************/
void HarryPotter::defend(int roll) {
	int defenseRoll = 0;
	for (int i = 0; i < 2; ++i) {
		defenseRoll += 1 + rand() % 6;
	}
	int damage = roll - defenseRoll - this->armor;
	if (damage < 0) {
		damage = 0;
	}
	//std::cout << "Harry's Defending Roll: " << defenseRoll << std::endl;
	//std::cout << "Total Damage: " << damage << std::endl;
	this->damageIN(damage);
}

/********************************
damageIn
This functions calculates strength
based on damage. If strength is 0
the character isAlive = false;
Special Ability: If it is harry's
first life when he dies then he 
comes back to life with 20 strength
points. The next time he dies 
he does not come back to life.
********************************/
void HarryPotter::damageIN(int x) {
	strength -= x;

	if (strength > 0) {
		//std::cout << "Harry has " << strength << " points of strength" << std::endl;
	}
	if (strength <= 0 && deathCount == 0) {
		this->strength = 20;
		deathCount = 1;
		//std::cout << "Harry Potter took " << x << " points of damage" << std::endl;
		std::cout << "Harry Potter has died but came back to life wil 20 strength points" << std::endl;
	}
	else if (strength <= 0 && deathCount >= 0) {
		strength = 0;
		//std::cout << "Harry Potter took " << x << " points of damage" << std::endl;
		std::cout << "Harry Potter has " << strength << " points of strength" << std::endl;
		std::cout << "Harry Potter has died for good." << std::endl;
		strength = 0;
		isAlive = false;
	}
}





