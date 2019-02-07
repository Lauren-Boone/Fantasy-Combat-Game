#pragma once
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
	virtual void medusaCharm();
};
#endif
