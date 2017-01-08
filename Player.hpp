/*
Author: Josh Erickson
Description: Header file for Player class, will hold data for the player
*/

#include <vector>
#include <string>
#include "ItemUsage.hpp"
#include "Layout.hpp"
#include "Area.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
protected:
	Area *previous;	//Pointer to last area
	Area *current;	//Pointer to current area
	std::vector<ITEMS> *backpack;
public:
	Player();
	void setPreviousArea(Area *prev);
	void setCurrentArea(Area *curr);
	Area *getPreviousArea();
	Area *getCurrentArea();
	std::vector<ITEMS> *getBackpack();
	void pickUpItem(ITEMS item);
	void updateItems(Zoo *zoo, Area *area);
	void useItem(Zoo *zoo, Area *area);
	ITEMS pickItem();
	void useItemInArea(Zoo *zoo, Area *area, ITEMS item);
};

#endif
