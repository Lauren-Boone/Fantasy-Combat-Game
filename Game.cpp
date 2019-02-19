/******************************************************************
File: Game.cpp
Name:Lauren Boone
Date: 2/13/19
Description: This files contains the class definitions for the game
class. It class the functions needed to execute the fantasy combat
game
*******************************************************************/
#include <iostream>
#include "Game.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "InputValidation.hpp"
#include <string>


Game::Game() {
	numRound = 1;
	team1 = nullptr;
	team2 = nullptr;
	losers = nullptr;
	//character2 = NULL;
	//character1 = NULL;
	menu1.addChoice("1. Vampire");
	menu1.addChoice("2. Barbarian");
	menu1.addChoice("3. Blue Menu");
	menu1.addChoice("4. Medusa");
	menu1.addChoice("5. HarryPotter");

}


Game::~Game() {
	delete team1;
	delete team2;
	delete losers;

}

/***************************************************************
gameMenu
This function allows the user to select two characters for combat.
After selection the gameCombat functions is called.
****************************************************************/
void Game::gameMenu() {
	int choice = 0;
	int numPlayers;
	
	while (choice != 6) {//loop
		team1 = new Container;
		team2 = new Container;
		losers = new Container;
		std::cout << "*****************************************" << std::endl;
		std::cout << "*	Welcome to Fantasy Combat!	*" << std::endl;
		std::cout << "*****************************************\n" << std::endl;
		for (int i = 1; i < 3; ++i) {
			std::cout << "How many characters do you want in team " << i << " ?" << std::endl;
			numPlayers = getPositiveInt();
			for (int x = 0; x < numPlayers; ++x) {
				std::cout << "*****************************************" << std::endl;
				std::cout << "* Please select character " << x << ":	        *" << std::endl;
				std::cout << "*---------------------------------------*" << std::endl;
				menu1.printMenu();
				choice = getIntinRange(0, 6);
				switch (choice) {
				case 1:
					if (i == 1) {
						team1->addBack(new Vampire("vampy"), "vampy");
					}
					else {
						team2->addBack(new Vampire("vampy"), "vampy");
					}
					break;
				case 2:
					if (i == 1) {
						team1->addBack(new Barbarian("barby"), "barby");
					}
					else {
						team2->addBack(new Barbarian("barby"), "barby");
					}
					break;
				case 3:
					if (i == 1) {
						team1->addBack(new BlueMen("smurf"), "smirf");
					}
					else {
						team2->addBack(new BlueMen("smurf"), "smirf");
					}
					
					break;
				case 4:
					if (i == 1) {
						team1->addBack(new Medusa("zuesy"), "zuesy");
					}
					else {
						team2->addBack(new Medusa("zuesy"), "zuesy");
					}
					
					break;
				case 5:
					if (i == 1) {
						team1->addBack(new HarryPotter("snotter"), "snotter");
					}
					else {
						team2->addBack(new HarryPotter("snotter"), "snotter");
					}
					
					break;
				}
			}
		}
		


		gameCombat();//run the combat
		//after combat ask user if they would like to play again
		std::cout << "\n\nWould you like to \n1. Play Again\n2. Quit" << std::endl;
		int playQuit = getIntinRange(0, 3);
		if (playQuit == 2) {
			choice = 6;
			
		}
		else {//play agin
			numRound = 1;// reset round counter
			delete team1;
			delete team2;
			delete losers;
		}
	}
}

/***************************************
gameCombat
This functions prints the info for the
attacker and defender.
Character1 attacks first.
Character 2 attacks second
Each character is checked before combat
to make sure they are still alive.
If one is dead the winner is determined.
****************************************/
void Game::gameCombat() {
	while (!team1->isEmpty() && !team2->isEmpty()) {
		Character* character1 = team1->getFront();
		Character* character2 = team2->getFront();
		//check to make sure the players are alive
		while (character1->check_isAlive() && character2->check_isAlive()) {
			std::cout << "\n\n------------------------------------------------" << std::endl;
			std::cout << "		>>>ROUND " << numRound << "<<< " << std::endl;
			std::cout << "------------------------------------------------" << std::endl;
			std::cout << "\nCHARACTER 1 ATTACKS" << std::endl;
			//std::cout << "\n------------------------------------------------" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "|Attacker	Armor	Strength Points |" << std::endl;
			character1->printInfo(); //print character info
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "|Defender	Armor	Strength Points |" << std::endl;
			character2->printInfo();//print infor for defender
			character1->attack(character2); //call attack/defend functions

			//before second attack check to make sure both are alive
			if (character1->check_isAlive() && character2->check_isAlive()) {
				std::cout << "\n\nCHARACTER 2 ATTACKS" << std::endl;
				std::cout << "-----------------------------------------" << std::endl;
				std::cout << "|Attacker	Armor	Strength Points |" << std::endl;
				character2->printInfo();//print attacker info
				std::cout << "-----------------------------------------" << std::endl;
				std::cout << "|Defender	Armor	Strength Points |" << std::endl;
				character1->printInfo();//print defender info
				character2->attack(character1);//character 2 attacker character 1
			}



			numRound++;
		}

		//Once a character dies determine the winner
		std::cout << "\n\n*******************************" << std::endl;
		if (character1->check_isAlive()) {
			//character 1 won
			std::cout << character1->getName() << " has won the game!!" << std::endl;
			losers->addBack(character2, character2->getName());
			team2->removeFront();
		}
		else {
			//character 2 won
			std::cout << character2->getName() << " hass won the game!!" << std::endl;
			losers->addBack(character1, character1->getName());
			team1->removeFront();
		}
		std::cout << "*******************************" << std::endl;

		std::cout << "Losers:\n----------\n";
		losers->printData();
		std::cout << std::endl;
	}
	if (team1->isEmpty()) {
		std::cout << "Team 2 won the tournament" << std::endl;
	}
	else {
		std::cout << "Team 1 won the tournament" << std::endl;
	}
}




