/***************************************************************
Program: Barbarian.hpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the Barbarian class which is a inherited 
from character class. 
***************************************************************/
//#pragma once
#include <iostream>
#include "Character.hpp"
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <string>

class Barbarian : public Character
{
public:
	Barbarian(std::string name);

	virtual void attack(Character* defender);
	virtual void defend(int);
	virtual void damageIN(int x);
	//virtual void medusaCharm();
	//virtual void printInfo();
};
#endif