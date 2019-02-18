/***************************************************************
Program: Medusa.cpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the Medusa class definitions which is
inherited from character class.
***************************************************************/
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

/*************************************
attack()
This functions has instructions for
how Medusa will attack. If she rolls
a 12 she turns the defender into stone
and they die unless the defender is a vampire
that has charmed her.
*******************************************/
void Medusa::attack(Character* defender) {
	int attackRoll = 0;
	if (defender->getName() == "Vampire") { //if defender is vampire
		for (int x = 0; x < 2; ++x) {
			attackRoll += 1 + rand() % 6;
		}
		
		if (attackRoll == 12) {
			std::cout << "Medusa rolled: 12" << std::endl;
			std::cout << "Medusa thinks about glaring at the vampire" << std::endl;
			defender->defend(100);//check to see if vamprie charmed
		}
		else {
			std::cout << "Medusa's attack Roll: " << attackRoll << std::endl;
			defender->defend(attackRoll);
		}
	}
	else { //if defender is not a vampire. 
		for (int x = 0; x < 2; ++x) {
			attackRoll += 1 + rand() % 6;
		}
		std::cout << "Medusa's Attacking Roll: " << attackRoll << std::endl;

		if (attackRoll == 12) {
			std::cout << "Medusa has glared at her opponet" << std::endl;
			defender->damageIN(1000);
		}
		else {
			defender->defend(attackRoll);
		}
	}
	
}

/*********************************************
defend()
This functions has instructions for how the
MEdusa defends attacks based on their roll
damage is calculated and sent to damageIn()
*******************************************/
void Medusa::defend(int roll) {
	int defendRoll = 1 + rand() % 6;
	std::cout << "Medusa's Defending Roll: " << defendRoll << std::endl;;
	int damage = roll - defendRoll - this->armor;
	if (damage < 0) {
		damage = 0;
	}
	std::cout << "Total Damage: " << damage << std::endl;
	std::cout << "Medusa takes " << damage << " points of damage" << std::endl;
	this->damageIN(damage);
}

/********************************
damageIn
This functions calculates strength
based on damage. If strength is 0
the character isAlive = false;
********************************/
void Medusa::damageIN(int x) {
	strength -= x;
	
	if (strength <= 0) {
		strength = 0;
		std::cout << "Medusa has " << strength << " strength points" << std::endl;
		std::cout << "Medusa has died" << std::endl;
		isAlive = false;
	}
	else {
		std::cout << "Medusa has " << strength << " strength points" << std::endl;
	}

}


