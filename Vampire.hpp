#pragma once
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
	virtual int defend(int );
	virtual void damageIN(int x);
	virtual void medusaCharm();

};
#endif