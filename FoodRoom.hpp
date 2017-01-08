/*
Name: Josh Erickson
Description: Hidden room that opens up once the elephants stampede, has bananas for the gorilla
*/

#include <string>
#include <iostream>
#include "Area.hpp"
#include "ItemUsage.hpp"

#ifndef FOODROOM_HPP
#define FOODROOM_HPP

class FoodRoom : public Area
{
private:
	bool beenOpened;
	ITEMS item;
	bool itemLooted;
	std::string lootDesc;
public:
	FoodRoom(std::string name);
	void setBeenOpened(bool opened);
	void setItem(ITEMS item);
	void setItemLooted(bool looted);
	void setLootDesc(std::string desc);
	bool getBeenOpened();
	ITEMS getItem();
	bool getItemLooted();
	std::string getLootDesc();
	void announce();
	bool checkArea();
};

#endif