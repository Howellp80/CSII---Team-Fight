/****************************************************************************************
** Program Filename: Main.cpp
** Author: Parker Howell
** Date: 2-28-16
** Description: Main menu gets amount of fighter per team and if user wants to see fight
**              data, then starts the tournament.
****************************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Game.hpp"

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

int main(){

	int choice;       // how many fighters are on each team, or to exit 
	char data;        // user input for showData
	bool showData;    // does the user want to see fight data?

	do
	{
		// main menu
		system(CLEAR_SCREEN);
		std::cout << "Welcome to the Tournament of Champions Team Fight!" << std::endl;
		std::cout << "Please enter the number of fighters on both teams (1 - 10)," 
			      << std::endl;
		std::cout << "or zero to exit." << std::endl;
		std::cin >> choice;

		// validate choice
		while (choice < 0 || choice > 10){
			std::cout << "Please enter a value between 0 and 10." << std::endl;
			std::cin >> choice;
		}

		// if the user didn't exit
		if (choice != 0){
			//does the user want to see fight output for each round?
			std::cout << "Would you like to see fight details as combat occurs? (y/n)" 
				      << std::endl;
			std::cin >> data;

			// validate data
			while ((data != 'y' && data != 'Y') && (data != 'n' && data != 'N')){
				std::cout << "Pleae enter a \"y\" or an \"n\"." << std::endl;
				std::cin >> data;
			}

			// convert data to bool value
			if (data == 'y' || data == 'Y')
				showData = true;
			else
				showData = false;

			// create a game and run it
			Game myGame(choice, showData);
			myGame.init();
			myGame.play();
			}

	// did the user exit?
	} while (choice != 0);
	

	return 0;
}