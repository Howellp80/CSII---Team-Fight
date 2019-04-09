/****************************************************************************************
** Class: Barbarian.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. Think Conan or Hercules from the movies. Big
**              sword, big muscles, bare torso.
****************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"
#include <iostream>

class Barbarian : public Creature
{
private:
	Die *d6;   // 6 sided die used for attack and defend rolls.

public:

	/************************************************************************************
	** Default Constructor:  Barbarian()
	** Description: Creates a Barbarian object with 0 armor and 12 Strength Points.
	************************************************************************************/
	Barbarian(std::string, bool);




	// Barbarian Destructor deletes d6
	~Barbarian();




	/************************************************************************************
	** Function: attack()
	** Description: Calls 'Barbarian's attack function. Returns result of 2d6 rolls.
	************************************************************************************/
	int attack();




	/************************************************************************************
	** Function: defend(int)
	** Description: Calls Barbarian's defend function.
	** Parameters: int  -  represents raw damage of incoming attack. Defend function
	**                     reduces this amound by 2d6 rolls and armor value. Adjusts
	**                     Barbarian's Strength Points accordingly.
	************************************************************************************/
	int defend(int);



	/************************************************************************************
	** Function: heal()
	** Description: Heals the fighter for about half of their SP. Can't go over starting
	**              SP value.
	************************************************************************************/
	void heal();

};

#endif