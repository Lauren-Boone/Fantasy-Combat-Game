#pragma once
#include<iostream>
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>


class Character
{
protected:
	int attackDie; //dice type
	int defenseDie; //dice type
	int armor; 
	int strength;
	bool isAlive;
	std::string charName;
public:
	Character(int armorNum, int strengthNum, int attackDieIN, int defenseDieIN);
	virtual void attack(Character* defender)=0;
	virtual int defend(int roll)=0;
	virtual void damageIN(int) = 0;
	virtual void medusaCharm() = 0;
	bool check_isAlive();
	std::string getName();
	int getStrengthPoints();
};
#endif