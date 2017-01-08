/*
Author: Josh Erickon
Description: Main file for Abandoned Zoo program/game
*/

#include <string>
#include <iostream>
#include "Area.hpp"
#include "Player.hpp"
#include "Layout.hpp"
#include "Zoo.hpp"


int main()
{
	std::cout << "You wake up in the corner of what looks like a filing closet with a splitting \nheadache... You're not sure how you got here, "
		"but looking around the \ndimly lit room, you see several pieces of faded paper with the words Zoo \nscattered across them. Staggering to your feet, "
		"you reach for the door.." << std::endl;	//Intro

	Zoo *zoo = createZoo();		//Creating the zoo, will create the rooms and connect them
	Player *player = new Player();	//Initializing the player
	int health = 40;

	movePlayer(player, getStartingRoom(zoo));	//Moving the player to the starting room
		
	while ((player->getCurrentArea()->getAreaType()) != OUTSIDE && (health > 0))	//While the player is not outside, continue running the program
	{
		if (player->getCurrentArea() != player->getPreviousArea())	//Before displaying the options to the player again, check if they're still in the same area
		{
			player->getCurrentArea()->announce();		//If they're not, announce the new area
		}
		displayOptions(zoo, player);		//And display their options to them again
		health = health - 1;
		std::cout << "Player has " << health << " health points.\n" << std::endl;
	}
	if (health == 0)
	{
		std::cout << "You took too long and died of fatigue." << std::endl;
	}
	else
	{
		Area *outs = getOutside(zoo);	//Once the player is outside, get an outside pointer
		outs->announce();	//And use it to announce the outside area
	}
	

	return 0;
}