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
	std::string name; 
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
				std::cout << "*****************************************" << std::endl;
				choice = getIntinRange(0, 6);
				name = getCharName();
				switch (choice) {
				case 1:
					if (i == 1) {
						team1->addBack(new Vampire(name));
					}
					else {
						team2->addBack(new Vampire(name));
					}
					break;
				case 2:
					if (i == 1) {
						team1->addBack(new Barbarian(name));
					}
					else {
						team2->addBack(new Barbarian(name));
					}
					break;
				case 3:
					if (i == 1) {
						team1->addBack(new BlueMen(name));
					}
					else {
						team2->addBack(new BlueMen(name));
					}
					
					break;
				case 4:
					if (i == 1) {
						team1->addBack(new Medusa(name));
					}
					else {
						team2->addBack(new Medusa(name));
					}
					
					break;
				case 5:
					if (i == 1) {
						team1->addBack(new HarryPotter(name));
					}
					else {
						team2->addBack(new HarryPotter(name));
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
	int match = 1;
	do {
		std::cout << "\n\n*****************************************" << std::endl;
		std::cout << "*	   MATCH " << match << " BEGINS	        *" << std::endl;
		std::cout << "*****************************************" << std::endl;
		Character* character1 = team1->getFront();
		Character* character2 = team2->getFront();
		//check to make sure the players are alive

		std::cout << "*---------------------------------------*" << std::endl;
		std::cout << "*|Player 1    Armor   Strength Points  |*" << std::endl;
		character1->printInfo(); //print character info
		std::cout << "*---------------------------------------*" << std::endl;
		std::cout << "*|Player 2	Armor   Strength Points|*" << std::endl;
		character2->printInfo();//print attacker info
		while (character1->check_isAlive() && character2->check_isAlive()) {
			////std::cout << "\n\n------------------------------------------------" << std::endl;
			//std::cout << "		>>>ROUND " << numRound << "<<< " << std::endl;
			//std::cout << "------------------------------------------------" << std::endl;
			//std::cout << "\nCHARACTER 1 ATTACKS" << std::endl;
			//std::cout << "\n------------------------------------------------" << std::endl;
			//std::cout << "-----------------------------------------" << std::endl;
			//std::cout << "|Attacker	Armor	Strength Points |" << std::endl;
			//character1->printInfo(); //print character info
			//std::cout << "-----------------------------------------" << std::endl;
			//std::cout << "|Defender	Armor	Strength Points |" << std::endl;
			//character2->printInfo();//print infor for defender
			character1->attack(character2); //call attack/defend functions

			//before second attack check to make sure both are alive
			if (character1->check_isAlive() && character2->check_isAlive()) {
				//std::cout << "\n\nCHARACTER 2 ATTACKS" << std::endl;
				//std::cout << "-----------------------------------------" << std::endl;
			//	std::cout << "|Attacker	Armor	Strength Points |" << std::endl;
				//character2->printInfo();//print attacker info
				//std::cout << "-----------------------------------------" << std::endl;
				//std::cout << "|Defender	Armor	Strength Points |" << std::endl;
				//character1->printInfo();//print defender info
				character2->attack(character1);//character 2 attacker character 1
			}
			numRound++;
		}

		//Once a character dies determine the winner
		std::cout << "*	    MATCH " << match << " OVER	   	*" << std::endl;
		std::cout << "*****************************************" << std::endl;
		if (character1->check_isAlive()) {
			//character 1 won
			std::cout << "*      " << character1->getName() << " has won the match!!        *" << std::endl;
			team1->moveHeadBack();
			losers->addFront(character2);
			team2->removeFront();
		}
		else {
			//character 2 won
			std::cout << "*      " << character2->getName() << " has won the match!!        *" << std::endl;
			team2->moveHeadBack();
			losers->addFront(character1);
			team1->removeFront();
		}
		std::cout << "*****************************************" << std::endl;
		numRound = 1;
		match++;
		std::cout << "Losers:\n----------\n";
		losers->printData();
		std::cout << std::endl;
	} while (!team1->isEmpty() && !team2->isEmpty());
	std::cout << "\n\n*****************************************" << std::endl;
	std::cout << "*          TOURNAMENT OVER          *" << std::endl;
	if (team1->isEmpty()) {
		std::cout << "*       Team 2 won the tournament        *" << std::endl;
	}
	else {
		std::cout << "*       Team 1 won the tournament     *" << std::endl;
	}
	std::cout << "*****************************************" << std::endl;
}






/**********************************
getNAme()
This functions asks the user for the 
name of the character and returns
the string
***********************************/
std::string Game::getCharName() {
	std::string nameIn;
	std::cout << "What is this characters name?" << std::endl;
	std::getline(std::cin, nameIn);
	return nameIn;
}