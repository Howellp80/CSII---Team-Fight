/****************************************************************************************
** Class: HarryPotter.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. You do know who Harry Potter is, right?  :P
****************************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"
#include <iostream>

class HarryPotter : public Creature
{
private:
	bool hogwarts;
	Die *d6;   // 6 sided die used for attack and defend rolls.

public:

	/************************************************************************************
	** Default Constructor:  HarryPotter()
	** Description: Creates a HarryPotter object with 0 armor and 10/20* Strength Points.
	**              * Hogwarts - When Harry reaches 0 Strength Points, he instantly
	**                revives with 20. Can only be used once, and fails aganist Medusa's
	**                Glare.
	************************************************************************************/
	HarryPotter(std::string, bool);




	// HarryPotter Destructor deletes d6
	~HarryPotter();




	/************************************************************************************
	** Function: attack()
	** Description: Calls Harry Potter's attack function. Returns result of 2d6 rolls.
	************************************************************************************/
	int attack();




	/************************************************************************************
	** Function: defend(int)
	** Description: Calls Harry Potter's defend function.
	** Parameters: int  -  represents raw damage of incoming attack. Defend function
	**                     reduces this amound by 2d6 rolls and armor value. Adjusts
	**                     Harry Potter's Strength Points accordingly.
	**               * Hogwarts - When Harry reaches 0 Strength Points, he instantly
	**                 revives with 20. Can only be used once, and fails aganist Medusa's
	**                 Glare.
	************************************************************************************/
	int defend(int);





	/************************************************************************************
	** Function: heal()
	** Description: Heals the fighter for about half of their SP. Can't go over starting
	**              SP value. Restores Hogwarts ability
	************************************************************************************/
	void heal();



	// getter
	bool getHogwarts();

	// setter
	void setHogwarts(bool);



};

#endif