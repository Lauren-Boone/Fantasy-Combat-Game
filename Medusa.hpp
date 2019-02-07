#pragma once
#include <iostream>
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"

class Medusa : public Character
{
public:
	Medusa();
	virtual void attack(Character* defender);
	virtual void defend(int);
	virtual void damageIN(int x);
	virtual void medusaCharm();
};
#endif