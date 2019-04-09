/****************************************************************************************
** Class: Vampire.cpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. Suave. Debonair. But vicious and surprisingly
**              resilient!
****************************************************************************************/

#include "Vampire.hpp"
#include <cstdlib>




/************************************************************************************
** Default Constructor:  Vampire()
** Description: Creates a Vampire object with 1 armor and 18 Strength Points.
************************************************************************************/
Vampire::Vampire(std::string n, bool s)
{
	setArmor(1);
	setSP(18);
	setPoints(0);
	setName(n);
	setCreatType("Vampire");
	setShowData(s);
	d6 = new Die(6);
	d12 = new Die(12);
}




// Vampire Destructor deletes d6 and d12
Vampire::~Vampire()
{
	delete d6;
	delete d12;
}




/************************************************************************************
** Function: attack()
** Description: Calls Vampire's attack function. Returns result of 1d12 roll.
************************************************************************************/
int Vampire::attack()
{
	int rawDamage = d12->roll();
	if (showData)
		std::cout << "The Vampire, " << name << ", attacks for: " << rawDamage 
		          << std::endl;
	return rawDamage;
}




/************************************************************************************
** Function: defend(int)
** Description: Calls Vampire's defend function which includes a 50/50 chance that
**              the attacker will be Charmed and miss their attack.
** Parameters: int  -  represents raw damage of incoming attack. Defend function
**                     reduces this amound by 1d6 roll and armor value. Adjusts
**                     Vampire's Strength Points accordingly.
************************************************************************************/
int Vampire::defend(int rD)
{
	int charm = rand() % 2;
	if (charm){
		if (showData){
			std::cout << "But, the Vampire, " << name
				<< ", Charmed their opponent, causing them to miss!" << std::endl;
		}
		return 0;
	}

	else if (rD == 99){  // Medusa glare attack
		if (showData){
			std::cout << "The Vampire, " << name << ", has been turned to stone!"
				<< std::endl;
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
void Vampire::heal()
{
	int life = SP + 9;
	if (life > 18)
		SP = 18;
	else
		SP = life;
}