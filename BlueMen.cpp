/****************************************************************************************
** Class: BlueMen.cpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Derived from Creature. They are small (6” tall), fast and tough. So they
**              are hard to hit and can take some damage.
****************************************************************************************/

#include "BlueMen.hpp"




/************************************************************************************
** Default Constructor:  BlueMen()
** Description: Creates a BlueMen object with 3 armor and 12 (*Mob) Strength Points.
************************************************************************************/
BlueMen::BlueMen(std::string n, bool s)
{
	setArmor(3);
	setSP(12);
	setPoints(0);
	setName(n);
	setCreatType("Blue Men");
	setShowData(s);
	d6 = new Die(6);
	d10 = new Die(10);
}




// BlueMen Destructor deletes d6 and d10
BlueMen::~BlueMen()
{
	delete d6;
	delete d10;
}




/************************************************************************************
** Function: attack()
** Description: Calls 'BlueMen's attack function. Returns result of 2d10 rolls.
************************************************************************************/
int BlueMen::attack()
{
	int rawDamage = d10->roll() + d10->roll();
	if (showData)
		std::cout << "The Blue Men, " << name << ", attack for: " << rawDamage 
		          << std::endl;
	return rawDamage;
}




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
int BlueMen::defend(int rD)
{
	if (rD == 99){  // Medusa glare attack
		if (showData){
			std::cout << "One of the Blue Men have been turned to stone!" << std::endl;
			std::cout << "The petrified fighter is dragged off the field "
				<< "of battle by his comrades." << std::endl;
		}
		SP = 0;
		return 20;
	}
	else {
		int def;

		// Mob defense calculation...
		if (SP <= 4)
			def = d6->roll() + armor;
		else if (SP <= 8)
			def = d6->roll() + d6->roll() + armor;
		else // (SP <= 12)
			def = d6->roll() + d6->roll() + d6->roll() + armor;
		
		int f1pts = defensePrint(name, creatType, rD, def);
		return f1pts;
	}
}





/************************************************************************************
** Function: heal()
** Description: Heals the fighter for about half of their SP. Can't go over starting
**              SP value.
************************************************************************************/
void BlueMen::heal()
{
	int life = SP + 6;
	if (life > 12)
		SP = 12;
	else
		SP = life;
}