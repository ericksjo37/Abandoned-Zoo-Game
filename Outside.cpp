/*
Author: Josh Erickson
Description: Outside the zoo area, once the player finds the key and gets out
*/

#include "Outside.hpp"

Outside::Outside(std::string name) : Area(name)	//Constructor
{
	setLocked(true);
	setAreaType(OUTSIDE);
}

void Outside::setLocked(bool lock)	//Setting whether the door leading outside is locked or not
{
	locked = lock;
}

bool Outside::getLocked()	//Get the locked variable
{
	return locked;
}

void Outside::announce()	//Get the announcement that should show when the player goes outside
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;
}

bool Outside::checkArea()	//Check the area for items or useful info (not relevant here, game ends when outside)
{
	return false;
}
