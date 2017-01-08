/*
Author: Josh Erickson
Description: Child class of Area, pathway connected to MidHallway, ToolRoom, and StartingRoom
*/

#include <string>
#include <iostream>
#include "Area.hpp"

#ifndef SOUTHPATHWAY_HPP
#define SOUTHPATHWAY_HPP

class SouthPathway : public Area
{
public:
	SouthPathway(std::string name);	//Constructor
	void announce();
	bool checkArea();
};

#endif