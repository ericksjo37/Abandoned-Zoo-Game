/*
Author: Josh Erickson
Description: Lion Cage area, contains a lion that the player has to use a tranq gun to get past into a cave behind him, where a key is waiting
*/

#include "LionCage.hpp"


LionCage::LionCage(std::string name) : Area(name)	//Constructor
{
	setAreaType(LION_PIT);
	setLionSleeping(false);
	setItemLooted(false);
}

void LionCage::setLionSleeping(bool sleep)		//Setting whether the lion is asleep or not
{
	lionSleeping = sleep;
}

void LionCage::setCorrectItem(ITEMS item)		//Setting the correct item to use in this area
{
	correctItem = item;
}

void LionCage::setLoot(ITEMS item)		//Setting the item to loot in here
{
	loot = item;
}

void LionCage::setObjDesc(std::string obj)	//Setting the objective description
{
	objectiveDesc = obj;
}

void LionCage::setItemLooted(bool loot)		//Sets whether the item has been looted yet, t/f
{
	itemLooted = loot;
}

bool LionCage::getItemLooted()		//Returns t/f if the items has been looted yet
{
	return itemLooted;
}

std::string LionCage::getObjDesc()	//Get the objective description
{
	return objectiveDesc;
}

bool LionCage::getLionSleeping()	//Return t/f if the lion is sleeping
{
	return lionSleeping;
}

ITEMS LionCage::getCorrectItem()	//Return the correct item to use in this room
{
	return correctItem;
}

ITEMS LionCage::getLoot()			//Return the item that can be looted in this room
{
	return loot;
}

void LionCage::announce()		//Get the announcement for this room
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;
}

bool LionCage::checkArea()	//Check the area for info/items
{
	if (getLionSleeping() == false)	//If the lion hasn't been shot with the tranq gun
	{
		std::cout << "The lion seems like he's guarding that cave... Would be great to find a way past him, but he's just snoozing lightly"
			", better not risk it.\n" << std::endl;
	}
	else //After getting the key
	{
		std::cout << "The lion seems to be coming out of his tranquilizer induced sleep, better not get too close\n";
	}

	return false;
}