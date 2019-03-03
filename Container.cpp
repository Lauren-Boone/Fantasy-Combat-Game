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
		if (garbage->player != nullptr) {
			delete garbage->player;
		}
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

void Container::addBack(Character* player) {
	if (isEmpty()) {
		Team *playerIn = new Team(player, nullptr, tail);
		head = playerIn;
		tail = playerIn;
		//playerIn->prev = head;
		//playerIn->next = tail;
		//tail->next = nullptr;
		//if (tail != nullptr) {
		//	tail->prev = playerIn;
	//	}
		head->next = playerIn;
		tail->prev = playerIn;
	}
	else {
		Team* playerIn = new Team(player, nullptr, tail);
		//tail->prev = tail;
		tail->next = playerIn;
		tail = playerIn;
	}
}

void Container::moveHeadBack() {
	if (head != nullptr) {
		Team *tempHead = head;
		head = head->next;
		//tempHead->prev = tail->prev;
		/*if (head == tail) {
			tail = head;
			tail->next = nullptr;
			head->prev = nullptr;
			//head->next = tail;
			//tail->prev = head;
		}*/
		 
			tail->next = tempHead;
			tempHead->prev = tail;
			//tail->prev = tail;
			tail = tempHead;
			tail->next = nullptr;
			if (head == nullptr) {
				head = tail;
		}
	}
}

void Container::addFront(Character* player) {
	if (isEmpty()) {
		//Team* playerIn = player->getFront();
		Team *playerIn = new Team(player, nullptr, nullptr);
		head = playerIn;
		tail = playerIn;
		head->next = nullptr;
		tail->next = nullptr;
	}
	else {
		Team* playerIn = new Team(player, head, nullptr);
		//head->next = head;
		head->prev = playerIn;
		//playerIn-> next = head;
		//playerIn->prev = nullptr;
		head = playerIn;
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
		//std::cout << "Players: " << std::endl;
		while (print != nullptr) {
			std::cout << print->player->getName() << "\n";
			print = print->next;
		}
		std::cout << std::endl;
	}
}