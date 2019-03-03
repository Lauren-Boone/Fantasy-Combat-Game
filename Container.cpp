/**********************************************************
File: Container.cpp
Name: Lauren Boone
Date 2/24/19
Description: This class uses a linked list stack structure
to hold Fantasy Combat Team members
**********************************************************/
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

/***********************************
inEmpty()
This function checks to see if the
stack is empty
**********************************/
bool Container::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

/****************************************
addBack()
This function a a player to the back
of the list
*********************************************/
void Container::addBack(Character* player) {
	if (isEmpty()) {
		Team *playerIn = new Team(player, nullptr, tail);
		head = playerIn;
		tail = playerIn;
	
		head->next = nullptr;
		tail->prev = nullptr;
	}
	else {
		Team* playerIn = new Team(player, nullptr, tail);
		//tail->prev = tail;
		tail->next = playerIn;
		tail = playerIn;
	}
}


/******************************************
moveHeadBack()
This function is called for the winning team.
The head it moved to the end of the list
*******************************************/
void Container::moveHeadBack() {
	if (head != nullptr) {
		Team *tempHead = head;
		head = head->next;
		if (head == nullptr) {
			head = tempHead;
			tail = head;
		}
		else{
			tail->next = tempHead;
			tempHead->prev = tail;
			//tail->prev = tail;
			tail = tempHead;
			tail->next = nullptr;
		}
	}
}


/**********************************************************
addFront()
This function is called to add loosers to the front of 
a list of loosers
*********************************************************/
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


/**********************************************
remvoeFront()
This functions removes the looser from the linked 
list and set the head to next
**********************************************/
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


/****************************************************
printData()
This function prints the names of all the loosers
****************************************************/
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