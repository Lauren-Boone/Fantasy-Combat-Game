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
	Character* character1;
	Character* character2;

public:
	Game();
	~Game();
	void gameMenu();
	void gameCombat();



};
#endif