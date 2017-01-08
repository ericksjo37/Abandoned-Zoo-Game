/*
Name: Josh Erickson
Description: Elephant room, can use the air horn to cause a stampede and open up a new room
*/

#include "ElephantPit.hpp"

ElephantPit::ElephantPit(std::string name) : Area(name)
{
	setAreaType(ELEPHANT_PIT);
	setFoodRoomOpened(false);
}

void ElephantPit::setCorrectItem(ITEMS item)
{
	correctItem = item;
}
void ElephantPit::setHiddenFoodRoom(Area *hid)
{
	hidden = hid;
}
void ElephantPit::setFoodRoomOpened(bool opened)
{
	foodRoomOpened = opened;
}

bool ElephantPit::getFoodRoomOpened()
{
	return foodRoomOpened;
}

ITEMS ElephantPit::getCorrectItem()
{
	return correctItem;
}
Area *ElephantPit::getHiddenFoodRoom()
{
	return hidden;
}

void ElephantPit::announce()
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;

	if (getFoodRoomOpened() == false)
	{
		std::cout << "\nThe far wall seems fragile, like it could collapse pretty easily...\n";
	}
}

bool ElephantPit::checkArea()
{
	if (getFoodRoomOpened() == false)
	{
		std::cout << "\nThink there's a way to break that far wall down?\n" << std::endl;
	}
	else
	{
		std::cout << "\nThe elephants seem to have calmed down from their stampede, doesn't look like there's much more important left in this room.\n";
	}
	return false;
}

