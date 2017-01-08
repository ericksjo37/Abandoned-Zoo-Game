/*
Author: Josh Erickson
Description: Outside the zoo area, once the player finds the key and gets out
*/

#include <string>
#include <iostream>
#include "Area.hpp"

#ifndef OUTSIDE_HPP
#define OUTSIDE_HPP

class Outside : public Area
{
private:
	bool locked;	//Variable to say if the door leading outside the zoo is still locked or not
public:
	Outside(std::string name);
	void setLocked(bool lock);
	bool getLocked();
	void announce();
	bool checkArea();
};

#endif