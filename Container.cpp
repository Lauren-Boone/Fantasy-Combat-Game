#include <iostream>
#include "Character.hpp"
#include "Container.hpp"
#include <string>


Container::Container() {
	head = nullptr;
	tail = nullptr;
}


Container::~Container() {
	Team* temp = head, *garbage;
	while (temp != nullptr) {
		garbage = temp;
		temp = temp->next;
		delete garbage;
	}
	delete temp;
}

bool Container::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void Container::addBack(Character* player, std::string name) {
	if (isEmpty()) {
		Team *playerIn = new Team(player, name, nullptr, tail);
		head = playerIn;
		tail = playerIn;
	}
	else {
		Team* playerIn = new Team(player, name, nullptr, tail);
		tail->next = playerIn;
		tail = playerIn;
	}
}

Character* Container::getFront() {
	return head->player;
}



void Container::removeFront() {
	if (head != nullptr) {
		Team* garbage = head;
		head = head->next;
		delete garbage;
		if (head == nullptr) {
			tail = nullptr;
		}
		else {
			head->prev = nullptr;
		}
	}
	else {
		std::cout << "No more players left" << std::endl;
	}
}



void Container::printData() {
	Team* print = head;
	if (print == nullptr) {
		std::cout << "No players" << std::endl;
	}
	else {
		std::cout << "Players: " << std::endl;
		while (print != nullptr) {
			std::cout << print->player->getName() << " ";
			print = print->next;
		}
		std::cout << std::endl;
	}
}