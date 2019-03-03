/**********************************************************
File: Container.hpp
Name: Lauren Boone
Date 2/24/19
Description: This class uses a linked list stack structure
to hold Fantasy Combat Team members
**********************************************************/
//#pragma once
#include <iostream>
#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include "Character.hpp"
#include <string>

class Container
{
private:
	struct Team {
		Team* next;
		Team* prev;
		Character* player;
		Team(Character* playerIn, Team* nextIn, Team* prevIn) {
			player = playerIn;
			//playerIn->setName(name);
			next = nextIn;
			prev = prevIn;
		}
	};
	
	Team* head, *tail;

public:
	Container();
	~Container();
	bool isEmpty();
	void addBack(Character* player);
	Character* getFront();
	void removeFront();
	void moveHeadBack();
	void addFront(Character* player);
	void printData();
};
#endif
