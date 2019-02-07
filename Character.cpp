#include <iostream>
#include "Character.hpp"


Character::Character(int armorNum, int strengthNum) {
	armor = armorNum;
	strength = strengthNum;
	isAlive = true;
}

bool Character::check_isAlive() {
	return isAlive;
}

std::string Character::getName() {
	return charName;
}

int Character::getStrengthPoints() {
	return strength;
}