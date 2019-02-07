#include <iostream>
#include "Character.hpp"


Character::Character(int armorNum, int strengthNum, int attackDieIN, int defenseDieIN) {
	armor = armorNum;
	strength = strengthNum;
	attackDie = attackDieIN;
	defenseDie = defenseDieIN;

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