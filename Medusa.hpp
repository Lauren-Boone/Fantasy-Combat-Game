/***************************************************************
Program: Medusa.hpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the Medusa class which is a inherited
from character class.
***************************************************************/
//#pragma once
#include <iostream>
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"
#include <string>

class Medusa : public Character
{
public:
	Medusa(std::string name);
	virtual void attack(Character* defender);
	virtual void defend(int);
	virtual void damageIN(int x);
	//virtual void medusaCharm();
	//virtual void printInfo();
};
#endif