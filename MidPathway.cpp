/*
Author: Josh Erickson
Description: Child class of Area, pathway connected to Elephant Pit, Lion Cage, South Pathway, North Pathway
*/


#include "MidPathway.hpp"

MidPathway::MidPathway(std::string name) : Area(name)	//Constructor
{
	setAreaType(MID_PATHWAY);
}

void MidPathway::announce()		//Announce the info for this area when arriving
{
	std::string desc = getAnnouncement();
	std::cout << desc << std::endl;
}


bool MidPathway::checkArea()	//Check the area for important items/info
{
	std::cout << "\nNothing important seems to be in this area, probably best to move on.";
	return false;
}
