/*
Author: Josh Erickson
Description: Gorilla room, player can give the gorilla a banana and then use rocket boots to get the tranq gun from the tree
*/

#include <string>
#include <iostream>
#include "Area.hpp"
#include "ItemUsage.hpp"

#ifndef GORILLAPIT_HPP
#define GORILLAPIT_HPP

class GorillaPit : public Area
{
private:
	bool gorillaSleeping;
	bool gunGotten;
	ITEMS correctItem1;
	ITEMS correctItem2;
	ITEMS loot;
public:
	GorillaPit(std::string name);
	void setGorillaSleeping(bool sleep);
	void setGunGotten(bool gun);
	void setCorrectItem1(ITEMS item);
	void setCorrectItem2(ITEMS item);
	void setLoot(ITEMS item);
	bool getGorillaSleeping();
	bool getGunGotten();
	ITEMS getCorrectItem1();
	ITEMS getCorrectItem2();
	ITEMS getLoot();
	void announce();
	bool checkArea();
};

#endif
