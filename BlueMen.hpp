//#pragma once
#include <iostream>
#include "Character.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
protected:
	int numDefense_die;

public:
	BlueMen();
	virtual void attack(Character* defender);
	virtual void defend(int);
	virtual void damageIN(int x);
	virtual void medusaCharm();
	//virtual void printInfo();
};
#endif