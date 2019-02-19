/******************************************************************
File: Game.hpp
Name:Lauren Boone
Date: 2/13/19
Description: This files contains the class Game. This class
runs the combat for the characters.
*******************************************************************/
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
#include "Menu.hpp"
#include "Container.hpp"


class Game
{
private:
	int numRound;
	//Character* character2;
	//Character* character1;
	Menu menu1;
	Container* team1;
	Container* team2;
	Container* losers;
	

public:
	Game();
	~Game();
	void gameMenu();
	void gameCombat();
	//void setTeamSize(int num);



};
#endif