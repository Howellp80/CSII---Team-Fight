/****************************************************************************************
** Class: Medusa.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. Scrawny lady with snakes for hair. They help with
**              fighting. Just don’t look at her!
****************************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"
#include <iostream>

class Medusa : public Creature
{
private:
	Die *d6;    // 6 sided die used for attack and defend rolls.

public:

	/************************************************************************************
	** Default Constructor:  Medusa()
	** Description: Creates a Medusa object with 3 armor and 8 Strength Points.
	************************************************************************************/
	Medusa(std::string, bool);




	// Medusa Destructor deletes d6
	~Medusa();




	/************************************************************************************
	** Function: attack()
	** Description: Calls Medusa's attack function. Returns result of 2d6 rolls, with
	**              the possibility of casting "Glare" - turns opponent to stone.
	************************************************************************************/
	int attack();




	/************************************************************************************
	** Function: defend(int)
	** Description: Calls Medusa's defend function.
	** Parameters: int  -  represents raw damage of incoming attack. Defend function
	**                     reduces this amound by 1d6 roll and armor value. Adjusts
	**                     Medusa's Strength Points accordingly.
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