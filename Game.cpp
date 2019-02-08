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
	character2 = NULL;
	character1 = NULL;

}


Game::~Game() {
	delete character2;
	delete character1;
}

void Game::gameMenu() {
	int choice = 0;
	while (choice != 6) {
		for (int x = 1; x < 3; ++x) {
			std::cout << "Please select character " << x << std::endl;
			std::cout << "1. Vampire\n2. Barbarian\n3. Blue Men\n4. Medusa\n5. Harry Potter" << std::endl;
			choice = getIntinRange(0, 6);
			switch (choice) {
			case 1:
				if (x == 1) {
					//Vampire vamp1;
					character1 = new Vampire;
				}
				else {
					character2 = new Vampire;
				}
				break;
			case 2:
				if (x == 1) {
					character1 = new Barbarian;
					//Barbarian barbarian1;
					//character2 = &barbarian1;
				}
				else {
					character2 = new Barbarian;
					//Barbarian barbarian2;
					//character1 = &barbarian2;
				}
				break;
			case 3:
				if (x == 1) {
					character1 = new BlueMen;
					//BlueMen bluemen1;
					//character2 = &bluemen1;
				}
				else {
					character2 = new BlueMen;
					//BlueMen bluemen2;
					//character1 = &bluemen2;
				}
				break;
			case 4:
				if (x == 1) {
					character1 = new Medusa;
					//Medusa medusa1;
					//character2 = &medusa1;
				}
				else {
					character2 = new Medusa;
					//Medusa medusa2;
					//character1 = &medusa2;
				}
				break;
			case 5:
				if (x == 1) {
					character1 = new HarryPotter;
					//HarryPotter harry1;
					//character2 = &harry1;
				}
				else {
					character2 = new HarryPotter;
					//HarryPotter harry2;
					//character1 = &harry2;
				}
				break;

			}
		}
		gameCombat();
		std::cout << "\n\nWould you like to \n1. Play Again\n2. Quit" << std::endl;
		int playQuit = getIntinRange(0, 3);
		if (playQuit == 2) {
			choice = 6;
		}
	}
}

void Game::gameCombat() {
	while (character1->check_isAlive() && character2->check_isAlive()) {
		std::cout << "\n------------------------------------------------" << std::endl;
		std::cout << "		ROUND " << numRound << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "\n-----------------------------------------" << std::endl;
		std::cout << "|Attacker	Armor	Strength Points |" << std::endl;
		character1->printInfo();
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "|Defender	Armor	Strength Points |" << std::endl;
		character2->printInfo();
		character1->attack(character2);
		


		std::cout << "\n-----------------------------------------" << std::endl;
		std::cout << "|Attacker	Armor	Strength Points |" << std::endl;
		character2->printInfo();
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "|Defender	Armor	Strength Points |" << std::endl;
		character1->printInfo();
		character2->attack(character1);

		
		
		numRound++;
	}
	std::cout << "\n\n*******************************" << std::endl;
	if (character1->check_isAlive()) {
		
		std::cout << character1->getName() << " has won the game!!" << std::endl;
	}
	else {
		std::cout << character2->getName() << " hass won the game!!" << std::endl;
	}
	std::cout << "*******************************" << std::endl;
}