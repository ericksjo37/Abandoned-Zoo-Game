/*
Author: Josh Erickson
Description: Header file for Area class, will be a parent class for all the other areas that will be created for the player to
move through.
*/

#include <stdio.h>
#include <string>

#ifndef AREA_HPP
#define AREA_HPP

enum AREA {GORILLA_ENCLOSURE, LION_PIT, ELEPHANT_PIT, STARTING, SOUTH_PATHWAY, MID_PATHWAY, NORTH_PATHWAY, TOOLROOM, OUTSIDE, FOODROOM, SNAKE_PIT};

class Area
{
protected:
	AREA areaType;		//Holds the enum AREA 
	std::string areaName;	//Holds the area name
	Area *northArea;	//Pointer to area north of current area
	Area *eastArea;
	Area *southArea;
	Area *westArea;
	std::string roomAnnouncement;	//Will give an announcement when the player enters a room
public:
	Area(std::string areaName);		//Constructor
	void setAreaType(AREA);			//Sets the area type with the AREA enum
	void setAreaName(std::string areaName);	//Sets the area name
	void setAreas(Area *north, Area *east, Area *south, Area *west);	//Sets all areas, for use in constructor
	void setNorth(Area *north);	//Set the north area
	void setEast(Area *east);
	void setSouth(Area *south);
	void setWest(Area *west);
	void setAreaAnnouncement(std::string announce);		//Set the string that announces the room when the player enters
	AREA getAreaType();	//Get the enum type
	std::string getAreaName();	//Get the area name
	Area *getNorth();	//Gets the north area
	Area *getEast();
	Area *getSouth();
	Area *getWest();
	std::string getAnnouncement();	//Get the room announcement string
	virtual void announce() = 0;
	virtual bool checkArea() = 0;



};

#endif