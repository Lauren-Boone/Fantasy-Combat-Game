#pragma once
#include <iostream>
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"

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
};
#endif