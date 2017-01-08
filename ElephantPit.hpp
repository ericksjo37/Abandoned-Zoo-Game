/*
Name: Josh Erickson
Description: Elephant room, can use the air horn to cause a stampede and open up a new room
*/

#include <string> 
#include <iostream>
#include "Area.hpp"
#include "ItemUsage.hpp"
#include "FoodRoom.hpp"

#ifndef ELEPHANTPIT_HPP
#define ELEPHANTPIT_HPP

class ElephantPit : public Area
{
private:
	bool foodRoomOpened;	//T/F on if the food room has been opened
	ITEMS correctItem;	//Holds the correct item to use in this area
	Area *hidden;	
public:
	ElephantPit(std::string name);		//Constructor
	void setCorrectItem(ITEMS item);	//Sets correct item for this area
	void setHiddenFoodRoom(Area *hid);	//Setter for the hidden room
	void setFoodRoomOpened(bool opened);	//T/F if the food room has been opened yet
	bool getFoodRoomOpened();	//Get T/F for food room opened yet
	ITEMS getCorrectItem();		//Get the correct item for this area
	Area *getHiddenFoodRoom();	//Getter for the hidden room
	void announce();	//Announcement for this area
	bool checkArea();	//Check the area for useful items/info
};

#endif
