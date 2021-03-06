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


Vampire::Vampire(std::string name) : Character(1,18, name){
	type = "Vampire";


}



/*************************************
attack()
This functions has instructions for 
how the vampire will attack
*******************************************/
void Vampire::attack(Character *defender) {
	int attackRoll = 1 + rand() % 12;
	//std::cout << "Vampire's Attacking Roll: " << attackRoll << std::endl;
	defender->defend(attackRoll);//no special attack abilitys simply call defend
	
}

/*********************************************
defend()
This functions has instructions for how the 
vampire defends attacks based on their roll
damage is calculated and sent to damageIn().
If charm is activated the attacker is nullified
*******************************************/
void Vampire::defend(int roll) {
	int defendRoll = 1 + rand() % 6;
	
	if (defendRoll > 3) { //activate charm (50% of the time)
		//std::cout << "Vampire's Defending Roll: " << defendRoll << std::endl;
		//std::cout << "The vampire was able to charm the attacker." <<
		//	"\n They attacker decided to not attack." << std::endl;
	}
	else if (roll !=100 && defendRoll <=3){//does not charm attacker
	//	std::cout << "Vampire's Defending Roll: " << defendRoll << std::endl;
		int damage = roll - defendRoll - this->armor; //calculate damage 
		if (damage < 0) {
			damage = 0;
		}
		//std::cout << "Total Damage: " << damage << std::endl;
		//std::cout << "The vampire takes " << damage << " points of damage" << std::endl;
		damageIN(damage); //add damage
		
	}
	else if (roll ==100 && defendRoll <=3) { //if medusa is attack and rolls a 12 and the vampire did not charm
		//std::cout << "Vampire's Defending Roll: " << defendRoll << std::endl;
		//std::cout << " The vampire was unable to charm Medusa" << std::endl;
		damageIN(100000);
	}
	
}

/********************************
damageIn
This functions calculates strength
based on damage. If strength is 0 
the character isAlive = false;
********************************/
void Vampire::damageIN(int x) {
	strength -= x;
	
	if (strength <= 0) {
		strength = 0;
		this->isAlive = false;
		//std::cout << "The vampire now has " << this->strength << " strength points." << std::endl;
		//std::cout << "The vampire has died" << std::endl;
	}
	else {
		//td::cout << "The vampire now has " << this->strength << " points left." << std::endl;
	}
}





