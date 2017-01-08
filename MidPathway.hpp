/*
Author: Josh Erickson
Description: Child class of Area, pathway connected to Elephant Pit, Lion Cage, South Pathway, North Pathway
*/

#include <string>
#include <iostream>
#include "Area.hpp"

#ifndef MIDPATHWAY_HPP
#define MIDPATHWAY_HPP

class MidPathway : public Area
{
public:
	MidPathway(std::string name);	//Constructor
	void announce();
	bool checkArea();
};

#endif