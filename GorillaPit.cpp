/*
Author: Josh Erickson
Description: Gorilla room, player can give the gorilla a banana and then use rocket boots to get the tranq gun from the tree
*/

#include "GorillaPit.hpp"

GorillaPit::GorillaPit(std::string name) : Area(name)	//Constructor
{
	setAreaType(GORILLA_ENCLOSURE);
	setGorillaSleeping(false);
	setGunGotten(false);
}

void GorillaPit::setGorillaSleeping(bool sleep)	//Set whether the gorilla is sleeping or not
{
	gorillaSleeping = sleep;
}

void GorillaPit::setGunGotten(bool gun)	//set whether the gun has been gotten yet or not
{
	gunGotten = gun;
}

void GorillaPit::setCorrectItem1(ITEMS item)	//set the #1 correct item to be used in the room
{
	correctItem1 = item;
}

void GorillaPit::setCorrectItem2(ITEMS item)	//set the #2 correct item to be used in the room
{
	correctItem2 = item;
}

void GorillaPit::setLoot(ITEMS item)	//Function to set the loot in this room
{
	loot = item;
}

bool GorillaPit::getGorillaSleeping()	//bool for whether the gorilla has been knocked out with the bananas yet
{
	return gorillaSleeping;
}

bool GorillaPit::getGunGotten()	//bool for whether the gun has been retrieved yet
{
	return gunGotten;
}

ITEMS GorillaPit::getCorrectItem1()	//Get correct item number 1, the bananas
{
	return correctItem1;
}

ITEMS GorillaPit::getCorrectItem2()	//And item #2, the rocket boots
{
	return correctItem2;
}

ITEMS GorillaPit::getLoot()	//Get the loot in this room, (gun)
{
	return loot;
}

void GorillaPit::announce()	//Announce the room info, changes depending on items used/gotten
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;

	if (getGorillaSleeping() == false)
	{
		std::cout << "That gorilla looks like he's pretty protective of that tree... If only there were a way to distract him." << std::endl;
	}

	if ((getGorillaSleeping() == true) && (getGunGotten() == false))
	{
		std::cout << "The gorilla seems passed out... Should be safe to investigate the tree he was guarding." << std::endl;
	}
}

bool GorillaPit::checkArea()	//Check area for info/items
{
	if (getGorillaSleeping() == false)	//If the gorilla isn't sleeping
	{
		std::cout << "That tree needs investigating, but the gorilla needs to be taken care of first..." << std::endl;
	}
	else if ((getGorillaSleeping() == true) && (getGunGotten() == false))	//If the gorilla is sleeping but the gun hasn't been gotten yet
	{
		std::cout << "The tree that the gorilla was guarding looks like it has something shiny sitting near the top, there's got to be "
			"a way to get up there to check out what it could be." << std::endl;
	}
	else //If both the gun has been gotten and the gorilla has been given bananas
	{
		std::cout << "The gorilla looks like he's waking up again, better give him some space. Nothing else in this room looks useful anyway." << std::endl;
	}
	return false;
}