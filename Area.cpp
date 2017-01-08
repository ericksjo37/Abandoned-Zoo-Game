/*
Author: Josh Erickson
Description: Source file for Area class, will be a parent class for all the other areas that will be created for the player to
move through.
*/

#include "Area.hpp"
#include <iostream>

Area::Area(std::string areaName)	//Constructor
{
	setAreaName(areaName);
	setAreas(NULL, NULL, NULL, NULL);
}

void Area::setAreaType(AREA type)			//Sets the area type with the AREA enum
{
	areaType = type;
}

void Area::setAreaName(std::string name)	//Sets the area name
{
	areaName = name;
}

void Area::setAreas(Area *north, Area *east, Area *south, Area *west)	//Sets all areas, for use in constructor
{
	northArea = north;
	eastArea = east;
	southArea = south;
	westArea = west;
}

void Area::setNorth(Area *north)	//Set the north area
{
	northArea = north;
}

void Area::setEast(Area *east)
{
	eastArea = east;
}

void Area::setSouth(Area *south)
{
	southArea = south;
}

void Area::setWest(Area *west)
{
	westArea = west;
}

void Area::setAreaAnnouncement(std::string announce)		//Set the string that announces the room when the player enters
{
	roomAnnouncement = announce;
}

AREA Area::getAreaType()	//Get the enum type
{
	return areaType;
}

std::string Area::getAreaName()	//Get the area name
{
	return areaName;
}

Area *Area::getNorth()	//Gets the north area
{
	return northArea;
}

Area *Area::getEast()
{
	return eastArea;
}

Area *Area::getSouth()
{
	return southArea;
}

Area *Area::getWest()
{
	return westArea;
}

std::string Area::getAnnouncement()	//Get the room announcement string
{
	return roomAnnouncement;
}
