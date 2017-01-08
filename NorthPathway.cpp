/*
Author: Josh Erickson
Description: Child class of Area, pathway connected to Debris, Gorilla Pit, Snake Pit, Mid Pathway
*/

#include "NorthPathway.hpp"

NorthPathway::NorthPathway(std::string name) : Area(name)	//Constructor
{
	setAreaType(NORTH_PATHWAY);
}

void NorthPathway::announce()	//Announce the info for this area when arriving
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;
}


bool NorthPathway::checkArea()	//Check the area for important items/info
{
	std::cout << "\nNothing important seems to be in this room, probably best to move on. There's the pile of debris to the north, pathway to the south, gorilla"
		" pit and snake pit to our left and right.\n";
	return false;
}
