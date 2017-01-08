/*
Author: Josh Erickson
Description: Toolroom, there is a ladder in here that the player can pick up to use in one of the rooms
*/

#include <string>
#include <iostream>
#include "Area.hpp"
#include "ItemUsage.hpp"

#ifndef TOOLROOM_HPP
#define TOOLROOM_HPP

class ToolRoom : public Area
{
private:
	ITEMS item;
	bool itemLooted;
	std::string itemDescription;
public:
	ToolRoom(std::string name);
	void setItem(ITEMS item);
	void setItemLooted(bool looted);
	void setItemDescription(std::string desc);
	ITEMS getItem();
	bool getItemLooted();
	std::string getItemDescription();
	void announce();
	bool checkArea();
};

#endif