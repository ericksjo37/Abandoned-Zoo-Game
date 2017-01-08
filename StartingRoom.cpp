/*
Author: Josh Erickson
Description: Child class of Area, room that the player starts in
*/

#include "StartingRoom.hpp"

StartingRoom::StartingRoom(std::string name)  : Area(name)	//Constructor
{
	setAreaType(STARTING);
}

void StartingRoom::announce()	//Gets the announcement for this room and outputs it
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;
}

bool StartingRoom::checkArea()		//Just prints a generic message and returns false, since this is the starting room
{
	std::cout << "\nNothing important seems to be in this room, probably best to move on.";
	return false;
}