#pragma once
#include <iostream>
#ifndef GAME_HPP
#define GAME_HPP
#include "Character.hpp"
#include "Vampire.hpp"


class Game
{
private:
	int numRound;
	Character* attacker;
	Character* defender;

public:
	Game();
	~Game();
	void gameMenu();
	void gameCombat();



};
#endif