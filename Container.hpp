#pragma once
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
		Team(Character* playerIn, std::string name, Team* nextIn, Team* prevIn) {
			player = playerIn;
			playerIn->setName(name);
			next = nextIn;
			prev = prevIn;
		}
	};
	
	Team* head, *tail;
	/*
	struct Team_2 {
		Team_2* next;
		Team_2* prev;
		Team_2(Character* player, std::string name, Team_2* nextIn, Team_2* prevIn) {
			player->setName(name);
			next = nextIn;
			prev = prevIn;
		}
	};
	Team_2* head2, *tail2;

	struct Losers {
		Losers* prev;
		Losers* next;
		Losers(Character* player, Losers* nextIn, Losers* prevIn) {
			next = nextIn;
			prev = prevIn;
		}
	};
	Losers *head_L, *tail_L;*/
public:
	Container();
	~Container();
	bool isEmpty();
	void addBack(Character* player, std::string name);
	Character* getFront();
	void removeFront();
	void printData();
};
#endif
