/****************************************************************************************
** Class: Creature.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Base Class for Medusa, Barbarian, Vampire, BlueMen, and HarryPotter
****************************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "Die.hpp"
#include <string>
#include <iostream>

class Creature
{
protected:
	int points,              // how many points the creature has earned
		armor,               // amout to subtract from incoming attack damage
		SP;                  // Strength Points - basically health...
	bool showData;           // Will the creature display attack/defend info?
	std::string name,        // name of the derived creature
		        creatType;   // what creature is it? Vampire, Harry Potter, Barb, etc.

public:
	// Abstract Class, so not used...
	Creature();
	~Creature();

	// virtual functions. See Derived Classes...
	virtual int attack() = 0;
	virtual int defend(int) = 0;
	virtual void heal() = 0;

	// normal functions
	// calculates damage to deal to a fighter and possibly displays it
	int defensePrint(std::string, std::string, int, int);

	// adds scored points to a cretures points variable
	void addPoints(int);


	// getters
	int getPoints();
	int getArmor();
	int getSP();
	bool getShowData();
	std::string getName();
	std::string getCreatType();

	// setters
	void setPoints(int);
	void setArmor(int);
	void setSP(int);
	void setShowData(bool);
	void setName(std::string);
	void setCreatType(std::string);


};

#endif