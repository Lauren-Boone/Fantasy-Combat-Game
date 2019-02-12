/***************************************************************
Program: Vampire.hpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the Vampire class which is a inherited
from character class.
***************************************************************/
//#pragma once
#include <iostream>
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"

class Vampire : public Character
{
protected:
	
public:
	Vampire();

	virtual void attack(Character* defender);
	virtual void defend(int roll);
	virtual void damageIN(int x);
	//virtual void medusaCharm();
	//virtual void printInfo();

};
#endif