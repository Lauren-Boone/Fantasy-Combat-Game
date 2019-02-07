#include <iostream>
#include "Game.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "InputValidation.hpp"


Game::Game() {
	numRound = 0;
	character1 = NULL;
	character2 = NULL;

}


void Game::gameMenu() {
	int choice = 0;
	for (int x = 1; x < 3; ++x) {
		std::cout << "Please select character " << x << std::endl;
		std::cout << "1. Vampire\n2. Barbarian\n3. Blue Men\n4. Medusa\n5. Harry Potter" << std::endl;
		choice = getIntinRange(0, 6);
		switch (choice) {
		case 1:
			Vampire vamp;
			character1 = &vamp;
		}
	}
}

void Game::gameCombat() {

}