/***************************************************************
Program: Character.hpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the Character class which is a base class for
all the different characters. 
***************************************************************/
//#pragma once
#include<iostream>
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>


class Character
{
protected:
	int armor; 
	int strength;
	bool isAlive;
	std::string charName;
public:
	Character(int armorNum, int strengthNum, std::string name);
	virtual void attack(Character* defender)=0;
	virtual void defend(int roll)=0;
	virtual void damageIN(int) = 0;
	//virtual void medusaCharm() = 0;
	bool check_isAlive();
	std::string getName();
	int getStrengthPoints();
	int getArmor();
	void setName(std::string name);
	void printInfo();

};
#endif