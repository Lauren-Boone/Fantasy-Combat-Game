/***************************************************************
Program: HarryPotter.hpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the HarryPotter class which is a inherited
from character class.
***************************************************************/
//#pragma once
#include <iostream>
#include "Character.hpp"
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP


class HarryPotter : public Character
{
protected:
	int deathCount;

public:
	HarryPotter();
	virtual void attack(Character* defender);
	virtual void defend(int roll);
	virtual void damageIN(int x);
	//virtual void medusaCharm();
	//virtual void printInfo();
};
#endif
