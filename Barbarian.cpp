/****************************************************************************************
** Class: Barbarian.cpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. Think Conan or Hercules from the movies. Big
**              sword, big muscles, bare torso.
****************************************************************************************/

#include "Barbarian.hpp"




/************************************************************************************
** Default Constructor:  Barbarian()
** Description: Creates a Barbarian object with 0 armor and 12 Strength Points.
************************************************************************************/
Barbarian::Barbarian(std::string n, bool s)
{
	setArmor(0);
	setSP(12);
	setPoints(0);
	setName(n);
	setCreatType("Barbarian");
	setShowData(s);
	d6 = new Die(6);
}




// Barbarian Destructor deletes d6
Barbarian::~Barbarian()
{
	delete d6;
}




/************************************************************************************
** Function: attack()
** Description: Calls 'Barbarian's attack function. Returns result of 2d6 rolls.
************************************************************************************/
int Barbarian::attack()
{
	int rawDamage = d6->roll() + d6->roll();
	if (showData){
		std::cout << "The Barbarian, " << name << ", attacks for: " << rawDamage
			<< std::endl;
	}
	return rawDamage;
}




/************************************************************************************
** Function: defend(int)
** Description: Calls Barbarian's defend function.
** Parameters: int  -  represents raw damage of incoming attack. Defend function
**                     reduces this amound by 2d6 rolls and armor value. Adjusts
**                     Barbarian's Strength Points accordingly.
************************************************************************************/
int Barbarian::defend(int rD)
{
	if (rD == 99){  // Medusa glare attack
		if (showData){
			std::cout << "The Barbarian, " << name << ",  has been turned to stone!"
				<< std::endl;
		}
		SP = 0;
		return 20;
	}
	else {
		int def = d6->roll() + d6->roll() + armor;
		int f1pts = defensePrint(name, creatType, rD, def);
		return f1pts;
	}
}




/************************************************************************************
** Function: heal()
** Description: Heals the fighter for about half of their SP. Can't go over starting
**              SP value.
************************************************************************************/
void Barbarian::heal()
{
	int life = SP + 6;
	if (life > 12)
		SP = 12;
	else
		SP = life;
}
