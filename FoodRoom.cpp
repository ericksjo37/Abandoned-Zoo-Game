/*
Name: Josh Erickson
Description: Hidden room that opens up once the elephants stampede, has bananas for the gorilla
*/

#include "FoodRoom.hpp"

FoodRoom::FoodRoom(std::string name) : Area(name)
{
	setAreaType(FOODROOM);
	setBeenOpened(false);
	setItemLooted(false);
}

void FoodRoom::setBeenOpened(bool opened)
{
	beenOpened = opened;
}

void FoodRoom::setItem(ITEMS ite)
{
	item = ite;
}

void FoodRoom::setItemLooted(bool looted)
{
	itemLooted = looted;
}

void FoodRoom::setLootDesc(std::string desc)
{
	lootDesc = desc;
}

bool FoodRoom::getBeenOpened()
{
	return beenOpened;
}

ITEMS FoodRoom::getItem()
{
	return item;
}

bool FoodRoom::getItemLooted()
{
	return itemLooted;
}

std::string FoodRoom::getLootDesc()
{
	return lootDesc;
}

void FoodRoom::announce()
{
	if (getBeenOpened() == false)
	{
		std::cout << "The room the elephant stampede opened up appears to be some sort of food room for the animals." << std::endl;
		setBeenOpened(true);
	}

	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;
}

bool FoodRoom::checkArea()
{
	if (getItemLooted() == false)
	{
		std::cout << getLootDesc();
		return true;
	}
	else
	{
		std::cout << "\nThere's some other food laying around in here, but nothing that looks all that useful yet.\n" << std::endl;
	}

	return false;
}
