//#pragma once
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
	Character* character2;
	Character* character1;
	

public:
	Game();
	~Game();
	void gameMenu();
	void gameCombat();



};
#endif