/****************************************************************************************
** Class: Creature.cpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Base Class for Medusa, Barbarian, Vampire, BlueMen, and HarryPotter
****************************************************************************************/

#include "Creature.hpp"

// Abstract Class, so not used...
Creature::Creature() {}
Creature::~Creature() {}


// calculates damage to deal to a fighter and possibly displays it
int Creature::defensePrint(std::string name, std::string type, int rD, int def)
{
	// raw damage - defense = damage
	int damage = rD - def;
	if (damage < 0)
		damage = 0;

	// subtract damage from Strength Points, can't go below zero
	SP -= damage;
	if (SP < 0)
		SP = 0;

	// display the round attack and damage info?
	if (showData){
		std::cout << "The " << type << ", " << name << " defends for: " << def << std::endl;
		std::cout << "The attack dealt: " << damage << " damage." << std::endl;
		std::cout << name << " has: " << SP << " Strength Point(s)." << std::endl;

	}

	// returns damage dealt to be used for adding points to attacking fighter
	return damage;
}



// adds scored points to a cretures points variable
void Creature::addPoints(int p)
{
	this->points += p;
}





// getters
int Creature::getPoints()
{
	return points;
}

int Creature::getArmor()
{
	return armor;
}

int Creature::getSP()
{
	return SP;
}

bool Creature::getShowData()
{
	return showData;
}

std::string Creature::getName()
{
	return name;
}

std::string Creature::getCreatType()
{
	return creatType;
}




// setters
void Creature::setPoints(int p)
{
	this->points = p;
}

void Creature::setArmor(int a)
{
	this->armor = a;
}
void Creature::setSP(int SP)
{
	this->SP = SP;
}

void Creature::setShowData(bool s)
{
	this->showData = s;
}


void Creature::setName(std::string n)
{
	this->name = n;
}

void Creature::setCreatType(std::string c)
{
	this->creatType = c;
}



