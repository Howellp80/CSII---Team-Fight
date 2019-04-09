/****************************************************************************************
** Class file: Game.hpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Creates and runs a fighting tournament between various Creature derived
**              objects. Winners and losers(optional) are displated at the end.
****************************************************************************************/

#include "Game.hpp"
#include <ctime>

// unused default constructor
Game::Game()
{
}


Game::Game(int numOfFighters, bool showData)
{
	this->numOfFighters = numOfFighters;
	this->t1fighters = numOfFighters;
	this->t2fighters = numOfFighters;
	this->showData = showData;

	//seed the psudo-random num generator
	srand(static_cast<unsigned long>(time(0)));
}



Game::~Game()
{
	delete t1;
	delete t2;
	delete losers;
}


void Game::init()
{
	// make the team queues and loser stack
	t1 = new Queue;
	t2 = new Queue;
	losers = new Stack;

	//have user fill in the two teams
	makeTeam(1);
	makeTeam(2);

}


void Game::makeTeam(int teamNum)
{
	int fighterChoice;        // the type of fughter the user chooses
	std::string tempName;     // the name of chosen fighter
    Creature *tempCreature;   // a creature derived obj made 
	                          // with fighterChoice and tempName

	// for each of the slots on the team, choose a fighter
	for (int i = 0; i < numOfFighters; i++){
		system(CLEAR_SCREEN);
		std::cout << "Please select Fighter " << i + 1 << " of Team " << teamNum 
			      << "." << std::endl << std::endl;
		std::cout << " [1] Medusa" << std::endl;
		std::cout << " [2] Barbarian" << std::endl;
		std::cout << " [3] Vampire" << std::endl;
		std::cout << " [4] Blue Men" << std::endl;
		std::cout << " [5] Harry Potter" << std::endl << std::endl;
		std::cin >> fighterChoice;

		// validate fighterChoice
		while (fighterChoice < 1 || fighterChoice > 5){
			std::cout << "Please choose a number 1 - 5." << std::endl;
			std::cin >> fighterChoice;
		}

		// get the name of the fighter
		std::cout << "Please enter the name of Fighter " << i + 1 << "." << std::endl;
		std::cin.ignore();
		std::getline(std::cin, tempName);
		

		// create new fighter
		if (fighterChoice == 1)
			tempCreature = new Medusa(tempName, showData);
		else if (fighterChoice == 2)
			tempCreature = new Barbarian(tempName, showData);
		else if (fighterChoice == 3)
			tempCreature = new Vampire(tempName, showData);
		else if (fighterChoice == 4)
			tempCreature = new BlueMen(tempName, showData);
		else // (fighterChoice == 5)
			tempCreature = new HarryPotter(tempName, showData);

		//add that fighter to the appropriate queue
		if (teamNum == 1)
			t1->add(tempCreature);
		else // (teamNum == 2)
			t2->add(tempCreature);

	}
}



void Game::play()
{
	// while both teams have at least 1 fighter each
	do {
		
		// get fighters for both teams and remove them from their queues
		fighter1 = t1->getP2Head()->fighterPtr;
		t1->remove();

		fighter2 = t2->getP2Head()->fighterPtr;
		t2->remove();
		
		// display the round and fighter info
		system(CLEAR_SCREEN);
		if (showData){
			std::cout << "****************************************************"
				      << "*****************" << std::endl;
			std::cout << "Round " << round + 1 << " :  " << fighter1->getCreatType() << ", "
				      << fighter1->getName() << "   - Vs. -   " << fighter2->getCreatType()
				      << ", " << fighter2->getName() << std::endl;
			std::cout << "****************************************************"
				<< "*****************" << std::endl << std::endl;
		}

		// fighter 1 starts round by attacking first
		f1attack();

		// do both teams have a fighter left to fight?
		} while ((t1->getP2Head() != NULL) && (t2->getP2Head() != NULL));
		
	system(CLEAR_SCREEN);
	// if team 1 lost
	if (t1->getP2Head() == NULL){
		std::cout << "  - Team 2 won the tournament! -" << std::endl << std::endl;
		t2->print();
		seeLosers();
	}

	// if team 2 lost
	else { // (t2->getP2Head() == NULL)
		std::cout << "  - Team 1 won the tournament! -" << std::endl << std::endl;
		t1->print();
		seeLosers();
	}
}


void Game::f1attack()
{
	//fighter 1 attacks and fighter 2 defends, fighter 1 scores points for damage dealt
	int rawDam = fighter1->attack();
	int pts = fighter2->defend(rawDam);
	fighter1->addPoints(pts);

	if (showData && pts > 0)
		std::cout << fighter1->getName() << " earned " << pts << " point(s)." << std::endl
		          << std::endl;
	if (pts == 0)
		std::cout << std::endl;
	std::cout << std::endl;

	// if fighter 2 was knocked out
	if (fighter2->getSP() == 0){
		if (showData){
			std::cout << std::endl << "************************************************"
				      << "*********************" << std::endl << std::endl;
			std::cout << fighter2->getCreatType() << ", " << fighter2->getName()
				      << ", has been K.O.'d" << std::endl;

			std::cout << "Team 1 has " << t1fighters << " fighter(s) left."
				      << std::endl;
			std::cout << "Team 2 has " << --t2fighters << " fighter(s) left."
				      << std::endl;

			std::cout << fighter1->getCreatType() << ", " << fighter1->getName()
				<< ", had: " << fighter1->getSP()
				<< " Strength Point(s) remaining." << std::endl << std::endl;
		}
		
		// fighter 2 added to loser stack, fighter 1 heals 
		// and is added to back of team queue
		losers->add(fighter2);
		fighter1->heal();
		t1->add(fighter1);

		round++;

		// pause after each round
		if (showData){
			std::cout << "Please press \"Enter\"." << std::endl;
			std::cin.get();
		}
	}
	// else fighter 2 attacks fighter 1
	else
		f2attack();
}



void Game::f2attack()
{
	//fighter 2 attacks and fighter 1 defends, fighter 2 scores points for damage dealt
	int rawDam = fighter2->attack();
	int pts = fighter1->defend(rawDam);
	fighter2->addPoints(pts);

	if (showData && pts > 0)
		std::cout << fighter2->getName() << " earned " << pts << " points." << std::endl  
		          << std::endl;
	if (pts == 0)
		std::cout << std::endl;
	std::cout << std::endl;

	// if fighter 1 was knocked out
	if (fighter1->getSP() == 0){
		if (showData){
			std::cout << "***************************************" << std::endl 
				      << std::endl;
			std::cout << fighter1->getCreatType() << ", " << fighter1->getName()
				      << ", has been K.O.'d" << std::endl;

			std::cout << " - Team 1 has " << --t1fighters << " fighter(s) left."
				      << std::endl;
			std::cout << " - Team 2 has " << t2fighters << " fighter(s) left."
				      << std::endl;

			std::cout << fighter2->getCreatType() << ", " << fighter2->getName()
				      << ", had: " << fighter2->getSP()
				      << " Strength Point(s) remaining." << std::endl << std::endl;
		}
			
		// fighter 1 added to loser stack, fighter 2 heals 
		// and is added to back of team queue
		losers->add(fighter1);
		fighter2->heal();
		t2->add(fighter2);

		round++;

		
		// pause after each round
		if (showData){
			std::cout << "Please press \"Enter\"." << std::endl;
			std::cin.get();
		}
	}
	// else fighter 1 attacks fighter 2
	else
		f1attack();
}




void Game::seeLosers()
{
	// ask if the user wants to see the defeated fighters?
	std::cout << "Would you like to see a list of the defeated fighters? (y/n)"
		<< std::endl;
	std::cin >> lp;

	// validate losers
	while ((lp != 'y' && lp != 'Y') && (lp != 'n' && lp != 'N')){
		std::cout << "Pleae enter a \"y\" or an \"n\"." << std::endl;
		std::cin >> lp;
	}
	// if yes, print the defeated fighters
	if (lp == 'y' || lp == 'Y')
		losers->print();

	// pause before returning to the main menu
	std::cout << "Please press \"Enter\" to return to the main menu." << std::endl;
	std::cin.ignore();
	std::cin.get();

}



// getters 
int Game::getNumOfFighters()
{
	return numOfFighters;
}


bool Game::getShowData()
{
	return showData;
}

int Game::getRound()
{
	return round;
}




// setters 
void Game::setNumofFighters(int n)
{
	this->numOfFighters = n;
}


void Game::setShowData(bool d)
{
	this->showData = d;
}

void Game::setRound(int r)
{
	this->round = r;
}




