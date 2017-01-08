/*
Author: Josh Erickson
Description: Lion Cage area, contains a lion that the player has to use a tranq gun to get past into a cave behind him, where a key is waiting
*/

#include <string>
#include <iostream>
#include "Area.hpp"
#include "ItemUsage.hpp"

#ifndef LIONCAGE_HPP
#define LIONCAGE_HPP

class LionCage : public Area
{
private:
	bool lionSleeping;	//True if the lion is sleeping, false if not
	bool itemLooted;	
	ITEMS correctItem;	//Holds the correct item to use in this room (TRANQGUN)
	ITEMS loot;		//Holds the loot for this room, (KEY)
	std::string objectiveDesc;
public:
	LionCage(std::string name);	//Constructor
	void setLionSleeping(bool sleep);
	void setCorrectItem(ITEMS item);
	void setLoot(ITEMS item);
	void setObjDesc(std::string obj);
	void setItemLooted(bool loot);
	bool getItemLooted();
	std::string getObjDesc();
	bool getLionSleeping();
	ITEMS getCorrectItem();
	ITEMS getLoot();
	void announce();
	bool checkArea();
};

#endif
