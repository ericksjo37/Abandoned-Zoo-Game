/*
Author: Josh Erickson
Description: Zoo file, will have functions to run the program
*/

#include "Zoo.hpp"

void displayOptions(Zoo *zoo, Player *player)	//Displays the options the player has at each area
{
	Area *area = player->getCurrentArea();
	AREA type = area->getAreaType();

	int choice;

	do
	{
		std::cout << "\nMake your next choice." << std::endl;		//Menu
		std::cout << "[1] Look around the " << area->getAreaName() << " for helpful items or information" << std::endl;
		std::cout << "[2] Use an item in your possession." << std::endl;
		std::cout << "[3] Move to another area in the zoo." << std::endl;
		std::cin >> choice;		//Getting their choice
		while ((choice < 1) || (choice > 3))	//Validation check
		{
			std::cout << "\nThat's not one of the options, try again." << std::endl;
			std::cin >> choice;
		}

		if (choice == 1)
		{
			if ((area->checkArea() == true) && (type == TOOLROOM || type == FOODROOM))	//The two rooms where you obtain an item by just checking the area
			{
				player->updateItems(zoo, area);	//So update the items in bag in those areas with the relevant items
			}
		}
		else if (choice == 2)	//Using an item, passing the area the player is currently in
		{
			player->useItem(zoo, area);
		}
	} while (choice != 3);	//If choice is 3, move areas

	moveAreas(zoo, player);
}

void moveAreas(Zoo *zoo, Player *player)	//Gets the move choice from the player, checks that the move doesn't take them outside before it's been unlocked, then moves the player
{
	Area *next = getMoveChoice(zoo, player);	//Gets move choice

	if (next->getAreaType() == OUTSIDE)
	{
		Outside *outs = getOutsideAreaType(zoo);

		if (outs->getLocked() == true)
		{
			std::cout << "\nYou attempt to open the door leading outside, but it's locked. Hopefully there's a key somewhere." << std::endl;
			player->setPreviousArea(player->getCurrentArea());
			return;
		}
	}
	movePlayer(player, next);	//Actually moves the player
}

void movePlayer(Player *player, Area *next)	//Sets the area the player is currently in as the area they chose to move to and the previous area they were in
{
	std::string nextAreaName = next->getAreaName();
	if (player->getCurrentArea() != NULL)
	{
		std::cout << "Leaving the " << player->getCurrentArea()->getAreaName() << "." << std::endl;
	}
	player->setPreviousArea(player->getCurrentArea());
	player->setCurrentArea(next);
	if ((player->getPreviousArea() != NULL) && (player->getCurrentArea() != NULL))	//Checking that the current and previous area aren't NULL before calling a member function
	{
		if ((player->getPreviousArea()->getAreaType() == STARTING) && (player->getCurrentArea()->getAreaType() == SOUTH_PATHWAY))	//If the player just moved from the starting area
		{
			std::cout << "\nBOOM!!!!!!\nAs you walk out of the room you woke up in, the entire room collapses with a huge crash! Good thing you got out when you did."
				" Looks like there's no going back in there!\n";
			player->getCurrentArea()->setEast(NULL);	//Collapse/delete the starting area
			delete(player->getCurrentArea()->getEast());
		}
	}
	
	std::cout << "\nEntering the " << nextAreaName << "\n" << std::endl;	//Telling them which area they're entering
}

Area *getMoveChoice(Zoo *zoo, Player *player)	//Gets the move choice from the player and returns it
{
	int choice;
	int adjAreas = 0;	//Counter for how many available areas there are to move to
	Area *current = player->getCurrentArea();	//Variable for where the player currently is
	Area *areas[4];	//Array to hold the choices and number that correllates with the choice
	Area *temp;

	std::cout << "\nWhere would you like to go?" << std::endl;
	if (current->getNorth() != NULL)	//Getting North option if it doesn't equal NULL
	{
		temp = current->getNorth();

		if (checkFoodRoomOpen(zoo, current, temp) == true)
		{
			*(areas + adjAreas) = temp;
			adjAreas++;
			std::cout << "[" << adjAreas << "] North: " << temp->getAreaName() << std::endl;
		}
	}
	if (current->getEast() != NULL)	//East option
	{
		temp = current->getEast();

		if (checkFoodRoomOpen(zoo, current, temp) == true)
		{
			*(areas + adjAreas) = temp;
			adjAreas++;
			std::cout << "[" << adjAreas << "] East: " << temp->getAreaName() << std::endl;
		}
	}
	if (current->getSouth() != NULL)	//South option
	{
		temp = current->getSouth();

		if (checkFoodRoomOpen(zoo, current, temp) == true)
		{
			*(areas + adjAreas) = temp;
			adjAreas++;
			std::cout << "[" << adjAreas << "] South: " << temp->getAreaName() << std::endl;
		}
	}
	if (current->getWest() != NULL)	//West option
	{
		temp = current->getWest();

		if (checkFoodRoomOpen(zoo, current, temp) == true)
		{
			*(areas + adjAreas) = temp;
			adjAreas++;
			std::cout << "[" << adjAreas << "] West: " << temp->getAreaName() << std::endl;
		}
	}

	std::cin >> choice;	//Getting choice
	while ((choice < 1) || (choice > adjAreas))	//Validating
	{
		std::cout << "\nThat's not one of the options, try again." << std::endl;
		std::cin >> choice;
	}

	return *(areas + (choice - 1));	//Returning array and corresponding number
}

bool checkFoodRoomOpen(Zoo *zoo, Area* current, Area *check)		//Function to check if the food room has been opened yet
{
	bool areaOpen = true;

	if (current->getAreaType() == ELEPHANT_PIT)	//If the player is currently in the ele room
	{
		ElephantPit *eleArea = getElephantPitType(zoo);	

		if ((eleArea->getFoodRoomOpened() == false) && (eleArea->getHiddenFoodRoom() == check))
		{
			areaOpen = false;
		}
	}
	return areaOpen;
}
