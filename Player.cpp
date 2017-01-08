/*
Author: Josh Erickson
Description: Header file for Player class, will hold data for the player
*/

#include "Player.hpp"

Player::Player()	//Constructor for the player
{
	setPreviousArea(NULL);
	setCurrentArea(NULL);
	backpack = new std::vector<ITEMS>;
}

void Player::setPreviousArea(Area *prev)	//Setter for the previous area
{
	previous = prev;
}

void Player::setCurrentArea(Area *curr)		//Setter for the current area
{
	current = curr;
}

Area *Player::getPreviousArea()		//Return the previous area
{
	return previous;
}

Area *Player::getCurrentArea()		//Return the current area
{
	return current;
}

std::vector<ITEMS> *Player::getBackpack()	//Return the players backpack
{
	return backpack;
}

void Player::pickUpItem(ITEMS item)	//Creates a pointer to the backpack vector, checks that the pack isn't at max capacity, then adds the item
{
	std::vector<ITEMS> *pack = getBackpack();
	if (pack->size() > 10)
	{
		std::cout << "You can't carry more than 10 items!" << std::endl;
	}
	pack->push_back(item);
}

void Player::updateItems(Zoo *zoo, Area *area)	//Update the items based on the room that the player is currently in, also sets whether the item has been looted or not
{
	AREA type = area->getAreaType();

	if (type == FOODROOM)		//For food room
	{
		FoodRoom *area1 = getFoodRoomType(zoo);

		if (area1->getItemLooted() == false)	//If the item hasn't been looted yet
		{
			pickUpItem(area1->getItem());		//Add that item to the players backpack
			area1->setItemLooted(true);		//And set the item looted bool to true
		}
	}

	else if (type == LION_PIT)		//Same with the rest of these
	{
		LionCage *area2 = getLionCageType(zoo);

		if (area2->getItemLooted() == false)
		{
			pickUpItem(area2->getLoot());
			area2->setItemLooted(true);
		}
	}

	else if (type == SNAKE_PIT)
	{
		SnakePit *area3 = getSnakePitType(zoo);

		if (area3->getItemLooted() == false)
		{
			pickUpItem(area3->getLoot1());
			pickUpItem(area3->getLoot2());
			area3->setLadderDown(true);
			area3->setItemLooted(true);
		}
	}
	else if (type == TOOLROOM)
	{
		ToolRoom *area4 = getToolRoomType(zoo);

		if (area4->getItemLooted() == false)
		{
			pickUpItem(area4->getItem());
			area4->setItemLooted(true);
			std::cout << "\nLadder added to bag!\n";
		}
	}
	else if (type == GORILLA_ENCLOSURE)
	{
		GorillaPit *area5 = getGorillaPitType(zoo);

		if (area5->getGunGotten() == false)
		{
			pickUpItem(area5->getLoot());
			area5->setGunGotten(true);
		}
	}
}

void Player::useItem(Zoo *zoo, Area *area)	//Creates a pointer to the backpack, checks if the packs size is 0, if it isn't, pick an item to use and use it in the area the player is in
{
	std::vector<ITEMS> *pack = getBackpack();
	if (pack->size() == 0)	//Checking backpack size
	{
		std::cout << "You don't have any items to use.\n" << std::endl;
		return;
	}

	ITEMS item = pickItem();	//Pick an item to use
	useItemInArea(zoo, area, item);		//Use it in an area
}

ITEMS Player::pickItem()		//Function to pick an item to use from the backpack
{
	std::vector<ITEMS> *pack = getBackpack();
	int choice;
	
	for (int i = 0; i < pack->size(); i++)
	{
		std::cout << "[" << i + 1 << "] " << getItemName(pack->at(i)) << std::endl;
	}

	std::cin >> choice;

	while ((choice < 1) || (choice > pack->size()))	//Validation
	{
		std::cout << "No item at that position.\n";
		std::cin >> choice;
	}

	return pack->at(choice - 1);
}

void Player::useItemInArea(Zoo *zoo, Area *area, ITEMS item)		//Use the chosen item in the current area
{
	AREA type = area->getAreaType();		//Variable for the type of room the function is passed
	std::string name = area->getAreaName();	

	bool correctRoom = false;	//Start with the correct room bool being false so that the default output will be the normal item description

	if (type == LION_PIT)		//For lion pit
	{
		LionCage *area1 = getLionCageType(zoo);	//Create a pointer of type LionCage

		if (area1->getLionSleeping() == false)	//If the lion isn't asleep
		{
			if (item == area1->getCorrectItem())	//And the correct item is used
			{
				correctRoom = true;	//set the correctRoom bool to true
				updateItems(zoo, area);	//Give the player the loot from that room
				area1->setLionSleeping(true);	//And set the lion bool to true
			}
		}
	}
	else if (type == SNAKE_PIT)		//Pretty much same with these next ones
	{
		SnakePit *area2 = getSnakePitType(zoo);

		if (area2->getLadderDown() == false)
		{
			if (item == area2->getCorrectItem())
			{
				correctRoom = true;
				updateItems(zoo, area);
			}
		}
	}
	else if (type == GORILLA_ENCLOSURE)
	{
		GorillaPit *area3 = getGorillaPitType(zoo);

		if (area3->getGorillaSleeping() == false)
		{
			if (item == area3->getCorrectItem1())
			{
				correctRoom = true;
				area3->setGorillaSleeping(true);
			}
		}
		if ((item == area3->getCorrectItem2()) && (area3->getGorillaSleeping() == true))
		{
			correctRoom = true;
			updateItems(zoo, area);
		}
	}
	else if (type == ELEPHANT_PIT)
	{
		ElephantPit *area4 = getElephantPitType(zoo);

		if (area4->getFoodRoomOpened() == false)
		{
			if (item == area4->getCorrectItem())
			{
				correctRoom = true;
				area4->setFoodRoomOpened(true);
			}
		}
	}
	else if ((item == KEY) && (name == "South Pathway"))		//If the player is in the south pathway and tries to use the key in the south pathway
	{
		Outside *area5 = getOutsideAreaType(zoo);	//create a pointer of Outside type
		std::cout << getItemCorrectAreaDescription(item);
		area5->setLocked(false);	//Unlock the door
		return;
	}

	if (correctRoom == true)	//If the item ended up being used in the correct room
	{
		std::cout << getItemCorrectAreaDescription(item);	//Output the correct room description for that item
	}
	else //Otherwise, use the default description
	{
		std::cout << getItemDescription(item);	//Output the default item description
	}
}