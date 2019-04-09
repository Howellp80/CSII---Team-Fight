/****************************************************************************************
** Class: HarryPotter.cpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. You do know who Harry Potter is, right?  :P
****************************************************************************************/

#include "HarryPotter.hpp"




/************************************************************************************
** Default Constructor:  HarryPotter()
** Description: Creates a HarryPotter object with 0 armor and 10/20* Strength Points.
**              * Hogwarts - When Harry reaches 0 Strength Points, he instantly
**                revives with 20. Can only be used once, and fails aganist Medusa's
**                Glare.
************************************************************************************/
HarryPotter::HarryPotter(std::string n, bool s)
{
	setArmor(0);
	setSP(10);
	setPoints(0);
	setName(n);
	setCreatType("Harry Potter");
	setShowData(s);
	setHogwarts(true);
	d6 = new Die(6);
}




// HarryPotter Destructor deletes d6
HarryPotter::~HarryPotter()
{
	delete d6;
}




/************************************************************************************
** Function: attack()
** Description: Calls Harry Potter's attack function. Returns result of 2d6 rolls.
************************************************************************************/
int HarryPotter::attack()
{
	int rawDamage = d6->roll() + d6->roll();
	if (showData)
		std::cout << "The Harry Potter, " << name << ", attacks for: " << rawDamage 
		          << std::endl;
	return rawDamage;
}




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
int HarryPotter::defend(int rD)
{
	if (rD == 99){  // Medusa glare attack
		if (showData){
			std::cout << "Harry Potter, " << name << ",  has been turned to stone!"
				<< std::endl;
		}
		SP = 0;
		return 20;
	}
	else {
		int def = d6->roll() + d6->roll() + armor;
		int f1pts = defensePrint(name, creatType, rD, def);

		if (SP == 0 && hogwarts){
			if (showData){
				std::cout << "Harry Potter, " << name << ",  was K.O'd, but used his "
					<< "Hogwarts power to recover." << std::endl;
			}
			setSP(20);
			setHogwarts(0);
		}
		return f1pts;
	}
}




/************************************************************************************
** Function: heal()
** Description: Heals the fighter for about half of their SP. Can't go over starting
**              SP value. Restores Hogwarts ability
************************************************************************************/
void HarryPotter::heal()
{
		int life = SP + 5;
		if (life > 10)
			SP = 10;
		else
			SP = life;

		// restore hogwarts
		hogwarts = true;
}



// getters
bool HarryPotter::getHogwarts()
{
	return hogwarts;
}

// setters
void HarryPotter::setHogwarts(bool h)
{
	this->hogwarts = h;
}



