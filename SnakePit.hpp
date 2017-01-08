/*
Author: Josh Erickson
Description: Snake Pit area, player can use a ladder to get across the pit to some rocket boots and an air horn
*/

#include <string>
#include <iostream>
#include "Area.hpp"
#include "ItemUsage.hpp"

#ifndef SNAKEPIT_HPP
#define SNAKEPIT_HPP

class SnakePit : public Area
{
private:
	ITEMS correctItem;	//Holds the correct item to use in this room (TRANQGUN)
	ITEMS loot1;		//Holds the loot for this room, (Rocketboots/air horn)
	ITEMS loot2;
	std::string objDesc;
	bool ladderDown;
	bool itemLooted;
public:
	SnakePit(std::string name);	//Constructor
	void setCorrectItem(ITEMS item);
	void setLoot1(ITEMS item);
	void setLoot2(ITEMS item);
	void setObjDesc(std::string obj);
	void setLadderDown(bool ladder);
	void setItemLooted(bool loot);
	bool getItemLooted();
	bool getLadderDown();
	std::string getObjDesc();
	ITEMS getCorrectItem();
	ITEMS getLoot1();
	ITEMS getLoot2();
	void announce();
	bool checkArea();
};

#endif
