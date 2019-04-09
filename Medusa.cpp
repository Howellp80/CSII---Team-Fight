/****************************************************************************************
** Class: Medusa.cpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. Scrawny lady with snakes for hair. They help with
**              fighting. Just don’t look at her!
****************************************************************************************/

#include "Medusa.hpp"




/************************************************************************************
** Default Constructor:  Medusa()
** Description: Creates a Medusa object with 3 armor and 8 Strength Points.
************************************************************************************/
Medusa::Medusa(std::string n, bool s)
{
	setArmor(3);
	setSP(8);
	setPoints(0);
	setName(n);
	setCreatType("Medusa");
	setShowData(s);
	d6 = new Die(6);
}




// Medusa Destructor deletes d6
Medusa::~Medusa()
{
	delete d6;
}




/************************************************************************************
** Function: attack()
** Description: Calls Medusa's attack function. Returns result of 2d6 rolls, with
**              the possibility of casting "Glare" - turns opponent to stone.
************************************************************************************/
int Medusa::attack()
{
	int rawDamage = d6->roll() + d6->roll();

	if (rawDamage == 12){
		if (showData)
			std::cout << "Medusa, " << name << ", Glares at her opponent." << std::endl;
		return 99;
	}
	else{
		if (showData)
			std::cout << "The Medusa, " << name << ", attacks for: " << rawDamage 
			          << std::endl;
		return rawDamage;
	}
}




/************************************************************************************
** Function: defend(int)
** Description: Calls Medusa's defend function.
** Parameters: int  -  represents raw damage of incoming attack. Defend function
**                     reduces this amound by 1d6 roll and armor value. Adjusts
**                     Medusa's Strength Points accordingly.
************************************************************************************/
int Medusa::defend(int rD)
{
	if (rD == 99){  // Medusa glare attack
		if (showData){
			std::cout << "Medusa, " << name << ",  has been turned to stone!" << std::endl;
		}
		SP = 0;
		return 20;
	}
	else {
		int def = d6->roll() + armor;
		int f1pts = defensePrint(name, creatType, rD, def);
		return f1pts;
	}
}




/************************************************************************************
** Function: heal()
** Description: Heals the fighter for about half of their SP. Can't go over starting
**              SP value.
************************************************************************************/
void Medusa::heal()
{
	int life = SP + 4;
	if (life > 8)
		SP = 8;
	else
		SP = life;
}
