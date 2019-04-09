/****************************************************************************************
** Class: BlueMen.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. They are small (6” tall), fast and tough. So they
**              are hard to hit and can take some damage.
****************************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"
#include <iostream>

class BlueMen : public Creature
{
private:
	Die *d6,      // 6 sided die used for defend rolls.
		*d10;    // 10 sided die used for attack rolls.

public:

	/************************************************************************************
	** Default Constructor:  BlueMen()
	** Description: Creates a BlueMen object with 3 armor and 12 (*Mob) Strength Points.
	************************************************************************************/
	BlueMen(std::string, bool);




	// BlueMen Destructor deletes d6 and d10
	~BlueMen();




	/************************************************************************************
	** Function: attack()
	** Description: Calls 'BlueMen's attack function. Returns result of 2d10 rolls.
	************************************************************************************/
	int attack();




	/************************************************************************************
	** Function: defend(int)
	** Description: Calls BlueMen's defend function.
	** Parameters: int  -  represents raw damage of incoming attack. Defend function
	**                     reduces this amound by 3d6* rolls and armor value. Adjusts
	**                     BlueMen's Strength Points accordingly.
	**                   * For every 4 points of damage (round down) they lose one
	**                     defense die. For example, when they reach strength of 8 they
	**                     only have 2d6 for defense.
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