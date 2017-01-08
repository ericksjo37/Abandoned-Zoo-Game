/*
Author: Josh Erickson
Description: Snake Pit area, player can use a ladder to get across the pit to some rocket boots and an air horn
*/

#include "SnakePit.hpp"

SnakePit::SnakePit(std::string name) : Area(name)	//Constructor
{
	setAreaType(SNAKE_PIT);
	setLadderDown(false);
}

void SnakePit::setCorrectItem(ITEMS item)	//Setter for the correct item to use in this room
{
	correctItem = item;
}

void SnakePit::setLoot1(ITEMS item)		//Setter for the first item you can loot
{
	loot1 = item;
}

void SnakePit::setLoot2(ITEMS item)		//Setter for the second item you can loot
{
	loot2 = item;
}

void SnakePit::setObjDesc(std::string obj)	//Setter for the objective description
{
	objDesc = obj;
}

void SnakePit::setLadderDown(bool ladder)		//Bool for whether the ladder has been put down yet or not
{
	ladderDown = ladder;
}

void SnakePit::setItemLooted(bool loot)		//Bool for whether the item(s) have been looted  yet
{
	itemLooted = loot;
}

bool SnakePit::getItemLooted()		//Get the bool on whether the items have been looted yet
{
	return itemLooted;
}

bool SnakePit::getLadderDown()		//Return if the ladder is down yet
{
	return ladderDown;
}

std::string SnakePit::getObjDesc()	//Get the objective description
{
	return objDesc;
}

ITEMS SnakePit::getCorrectItem()	//Return the correct item to use in this room
{
	return correctItem;
}

ITEMS SnakePit::getLoot1()	//Get the first item that can be looted here
{
	return loot1;
}

ITEMS SnakePit::getLoot2()	//And the second item
{
	return loot2;
}

void SnakePit::announce()	//Get the announcements for this room dependent on the ladder being down
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;

	if (getLadderDown() == false)
	{
		std::cout << "There's got to be a way across that pit of snakes... Maybe if there was something to lay across it." << std::endl;
	}
}

bool SnakePit::checkArea()	//Check the area for useful items/info, output dependent on ladder being down/loot being gotten yet
{
	if (getLadderDown() == false)
	{
		std::cout << "It looks like there might be some useful items on the other side of that snake pit... It would probably be a good idea to find a way"
			" across" << std::endl;
	}
	else
	{
		std::cout << "I think we got everything in here, unless we want a pet snake from the pit." << std::endl;
	}
	return false;
}