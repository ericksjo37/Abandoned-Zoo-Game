/*
Author: Josh Erickson
Description: Toolroom, there is a ladder in here that the player can pick up to use in one of the rooms
*/

#include "ToolRoom.hpp"

ToolRoom::ToolRoom(std::string name) : Area(name)	//Constructor
{
	setAreaType(TOOLROOM);
	setItemLooted(false);
}

void ToolRoom::setItem(ITEMS ite)	//Set the item that can be gotten here
{
	item = ite;
}

void ToolRoom::setItemLooted(bool looted)	//Bool for whether the item here has been looted yet or not
{
	itemLooted = looted;
}

void ToolRoom::setItemDescription(std::string desc)	//Set the description for the item
{
	itemDescription = desc;
}

ITEMS ToolRoom::getItem()	//Return the item that can be gotten here
{
	return item;
}

bool ToolRoom::getItemLooted()	//Return t/f for the item having been looted
{
	return itemLooted;
}

std::string ToolRoom::getItemDescription()	//Get the description for the item here
{
	return itemDescription;
}

void ToolRoom::announce()	//Announcement for this room when entering
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;
}

bool ToolRoom::checkArea()	//Check the area for useful items/info, get a ladder
{
	if (getItemLooted() == false)
	{
		std::cout << "There's a useful looking expandable stepladder in this toolroom, surprisingly small when folded. You add the ladder to your"
			" backpack" << std::endl;
		std::cout << getItemDescription();
		return true;
	}
	else
	{
		std::cout << "There's other tools in this room, but you can't think of a use for them yet." << std::endl;
	}

	return false;
}
