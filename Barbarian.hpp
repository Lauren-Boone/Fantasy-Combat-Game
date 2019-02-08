//#pragma once
#include <iostream>
#include "Character.hpp"
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Character
{
public:
	Barbarian();

	virtual void attack(Character* defender);
	virtual void defend(int);
	virtual void damageIN(int x);
	virtual void medusaCharm();
	//virtual void printInfo();
};
#endif