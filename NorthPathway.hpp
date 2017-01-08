/*
Author: Josh Erickson
Description: Child class of Area, pathway connected to Debris, Gorilla Pit, Snake Pit, Mid Pathway
*/

#include <string>
#include <iostream>
#include "Area.hpp"

#ifndef NORTHPATHWAY_HPP
#define NORTHPATHWAY_HPP

class NorthPathway : public Area
{
public:
	NorthPathway(std::string name);	//Constructor
	void announce();
	bool checkArea();
};

#endif