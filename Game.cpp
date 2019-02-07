#include <iostream>
#include "Game.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "InputValidation.hpp"


Game::Game() {
	numRound = 1;
	attacker = NULL;
	defender = NULL;

}


Game::~Game() {
	delete attacker;
	delete defender;
}

void Game::gameMenu() {
	int choice = 0;
	for (int x = 1; x < 3; ++x) {
		std::cout << "Please select character " << x << std::endl;
		std::cout << "1. Vampire\n2. Barbarian\n3. Blue Men\n4. Medusa\n5. Harry Potter" << std::endl;
		choice = getIntinRange(0, 6);
		switch (choice) {
		case 1:
			if (x == 1) {
				attacker = &vamp;
			}
			else {
				defender = &vamp;
			}
			break;
		case 2:
			if (x == 1) {
				attacker = &barbarian;
			}
			else {
				defender = &barbarian;
			}
			break;
		case 3:
			if (x == 1) {
				attacker = &bluemen;
			}
			else {
				defender = &bluemen;
			}
			break;
		case 4:
			if (x == 1) {
				attacker = &medusa;
			}
			else {
				defender = &medusa;
			}
			break;
		case 5:
			if (x == 1) {
				attacker = &harry;
			}
			else {
				defender = &harry;
			}

		}
	}
	gameCombat();
}

void Game::gameCombat() {
	while (defender->check_isAlive() && attacker->check_isAlive()) {
		std::cout << "ROUND " << numRound << std::endl;
		attacker->attack(defender);
		defender->attack(attacker);
		
	
	}
}