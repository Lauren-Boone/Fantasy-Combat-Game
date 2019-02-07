#pragma once
#include <iostream>
#ifndef GAME_HPP
#define GAME_HPP
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"


class Game
{
private:
	int numRound;
	Character* attacker;
	Character* defender;
	Vampire vamp;
	Barbarian barbarian;
	BlueMen bluemen;
	Medusa medusa;
	HarryPotter harry;

public:
	Game();
	~Game();
	void gameMenu();
	void gameCombat();



};
#endif