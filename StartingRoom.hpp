/*
Author: Josh Erickson
Description: Child class of Area, room that the player starts in
*/

#include <string>
#include <iostream>
#include "Area.hpp"
#include "ItemUsage.hpp"

#ifndef STARTINGROOM_HPP
#define STARTINGROOM_HPP

class StartingRoom : public Area
{
public:
	StartingRoom(std::string name);
	void announce();
	bool checkArea();
};

#endif