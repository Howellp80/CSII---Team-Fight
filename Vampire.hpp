/****************************************************************************************
** Class: Vampire.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. Suave. Debonair. But vicious and surprisingly
**              resilient!
****************************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"
#include <iostream>

class Vampire : public Creature
{
private:
	Die *d6,       // 6 sided die used for defend rolls.
		*d12;     // 12 sided die used for attack rolls.

public:

	/************************************************************************************
	** Default Constructor:  Vampire()
	** Description: Creates a Vampire object with 1 armor and 18 Strength Points.
	************************************************************************************/
	Vampire(std::string, bool);




	// Vampire Destructor deletes d6 and d12
	~Vampire();




	/************************************************************************************
	** Function: attack()
	** Description: Calls Vampire's attack function. Returns result of 1d12 roll.
	************************************************************************************/
	int attack();




	/************************************************************************************
	** Function: defend(int)
	** Description: Calls Vampire's defend function which includes a 50/50 chance that
	**              the attacker will be Charmed and miss their attack.
	** Parameters: int  -  represents raw damage of incoming attack. Defend function
	**                     reduces this amound by 1d6 roll and armor value. Adjusts
	**                     Vampire's Strength Points accordingly.
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