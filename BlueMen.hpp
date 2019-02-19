/***************************************************************
Program: BlueMen.hpp
Name: Lauren Boone
Date: 2/8/19
Description: This is the BlueMen class which is a inherited
from character class.
***************************************************************/
//#pragma once
#include <iostream>
#include "Character.hpp"
#include <string>

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
protected:
	int numDefense_die;

public:
	BlueMen(std::string name);
	virtual void attack(Character* defender);
	virtual void defend(int);
	virtual void damageIN(int x);
	//virtual void medusaCharm();
	//virtual void printInfo();
};
#endif