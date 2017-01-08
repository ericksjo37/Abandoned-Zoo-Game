/*
Author: Josh Erickson
Description: Child class of Area, pathway connected to MidHallway, ToolRoom, and StartingRoom
*/

#include "SouthPathway.hpp"

SouthPathway::SouthPathway(std::string name)  :  Area(name)	//Constructor
{
	setAreaType(SOUTH_PATHWAY);
}

void SouthPathway::announce()	//Announcement for this room
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;
}


bool SouthPathway::checkArea()		//Check the area for items/info
{
	std::cout << "\nNo important items seem to be in this area, but the locked door leading outside is south from here...\n"
		"Best to move on until we find a key\n";
	return false;
}
