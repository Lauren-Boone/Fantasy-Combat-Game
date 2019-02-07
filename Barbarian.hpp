#pragma once
#include <iostream>
#include "Character.hpp"
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Character
{
public:
	Barbarian();

	virtual void attack(Character* defender);
	virtual int defend(int);
	virtual void damageIN(int x);
	virtual void medusaCharm();
};
#endif