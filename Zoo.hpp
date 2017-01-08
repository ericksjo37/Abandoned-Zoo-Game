/*
Author: Josh Erickson
Description: Zoo file, will have functions to run the program
*/

#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include "Area.hpp"
#include "Player.hpp"
#include "Layout.hpp"

#ifndef ZOO_HPP
#define ZOO_HPP

void displayOptions(Zoo *zoo, Player *player);		//Displays the options the player has in that area
void moveAreas(Zoo *zoo, Player *player);	//Gets the move choice from the player, checks that the move doesn't take them outside before it's been unlocked, then moves the player
Area *getMoveChoice(Zoo *zoo, Player *player); //Gets the move choice from the player and returns it
bool checkFoodRoomOpen(Zoo *zoo, Area* current, Area *check);	//Function to check if the food room has been opened yet
void movePlayer(Player *player, Area *next);	//Sets the area the player is currently in as the area they chose to move to and the previous area they were in

#endif
