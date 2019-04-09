/****************************************************************************************
** Class file: Game.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Creates and runs a fighting tournament between various Creature derived
**              objects. Winners and losers(optional) are displated at the end.
****************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

class Game
{
public:

	int numOfFighters,       // how many fighters are on both teams
		t1fighters,          // how many fighters are left on team 1
		t2fighters,          // how many fighters are left on team 2
		round;               // what round it is
	bool showData,           // does the user want to see tournament output?
		showLosers;          // does the user want to see the defeated fighters?
	char lp;                 // stores Yes or No user selection
	Queue *t1,               // Queue Linked List for Team 1
	      *t2;               // Queue Linked List for Team 2
	Stack *losers;           // Stack Linked List for defeated fighters
	Creature *fighter1,      // fighter from team 1
		     *fighter2;      // fighter from team 2


	Game();
	Game(int, bool);
	~Game();
	void init();
	void makeTeam(int);
	void play();
	void f1attack();
	void f2attack();
	void seeLosers();

	// getters 
	int getNumOfFighters();
	bool getShowData();
	int getRound();


	// setters 
	void setNumofFighters(int);
	void setShowData(bool);
	void setRound(int);


};

#endif
