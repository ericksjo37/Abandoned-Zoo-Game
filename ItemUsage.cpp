/*
Author: Josh Erickson
Description: Source file for ItemUsage, will have functions to use items picked up
*/

#include "ItemUsage.hpp"

std::string getItemName(ITEMS item)	//Gets the item name based on the enum passed
{
	if (item == LADDER)
	{
		return "Ladder";
	}
	else if (item == AIRHORN)
	{
		return "Air Horn";
	}
	else if (item == BANANAS)
	{
		return "Bananas";
	}
	else if (item == TRANQGUN)
	{
		return "Tranquilizer Gun";
	}
	else if (item == KEY)
	{
		return "Key";
	}
	else if (item == ROCKETBOOTS)
	{
		return "Rocket Boots";
	}
}

std::string getItemDescription(ITEMS item)	//Gets a regular description for an item if the player is in the incorrect area for usage
{
	if (item == LADDER)
	{
		return getLadderDescription();
	}
	else if (item == AIRHORN)
	{
		return getAirHornDescription();
	}
	else if (item == BANANAS)
	{
		return getBananasDescription();
	}
	else if (item == TRANQGUN)
	{
		return getTranqGunDescription();
	}
	else if (item == KEY)
	{
		return getKeyDescription();
	}
	else if (item == ROCKETBOOTS)
	{
		return getRocketBootsDescription();
	}
}

std::string getItemCorrectAreaDescription(ITEMS item)	//Gets the correct room description for an item, if the player is in the correct room
{
	if (item == LADDER)
	{
		return getLadderCorrectAreaDescription();
	}
	else if (item == AIRHORN)
	{
		return getAirHornCorrectAreaDescription();
	}
	else if (item == BANANAS)
	{
		return getBananasCorrectAreaDescription();
	}
	else if (item == TRANQGUN)
	{
		return getTranqGunCorrectAreaDescription();
	}
	else if (item == KEY)
	{
		return getKeyCorrectAreaDescription();
	}
	else if (item == ROCKETBOOTS)
	{
		return getRocketBootsCorrectAreaDescription();
	}
}

/*
A bunch of item descriptions, 2 for each item, used based on the item used and area the player is in
*/

std::string getLadderDescription()
{
	std::string description;
	description = "\nYou pull the ladder off your back and put it against the wall. Not really \nmuch to climb here.";
	return description;
}


std::string getLadderCorrectAreaDescription()
{
	std::string description;
	description = "\nThis ladder looks just long enough to lay across the snake pit... You place the ladder across the snake pit "
		"and walk across to the other side.\nThe items on this side of the snake pit turned out to be an air horn and some rocket boots!How convenient.\n"
		"\nAir Horn added to bag!\n"
		"\nRocket Boots added to feet!\n";
	return description;
}

std::string getAirHornDescription()
{
	std::string description;
	description = "You sound the air horn for a good 10 seconds, waking up the animals in that room and really annoying them. They look at "
		"you for a moment, as if considering eating you, but go back to sleep instead.";
	return description;
}


std::string getAirHornCorrectAreaDescription()
{
	std::string description;
	description = "\nYou sound the air horn for a good 10 seconds, startling the elephants in the room and causing them to stampede in the other direction!"
		"One of the elephants hits the opposite wall with some significant force, causing it to collapse, revealing another room.";
	return description;
}


std::string getBananasDescription()
{
	std::string description;
	description = "\nYou look down at the bananas hungrily. You know you'll probably need them later, but you have so many, just eating one can't hurt. You sit down, eat one,"
		" and begin to feel very drowsy. You pass out for what was probably about 10 minutes, wake up, and realize that the bananas must have some sort of sleeping medicine in them."
		"\nBetter not eat another!";
	return description;
}


std::string getBananasCorrectAreaDescription()
{
	std::string description;
	description = "\nYou throw the banana at the angry gorilla, causing him to lose interest in you, begin eating the banana, and fall asleep."
		" The banana must have been laced with some sleeping drug. The room should be safe to explore now."
		"You notice the tree that the gorilla was protecting has something shiny up top.";
	return description;
}


std::string getTranqGunDescription()
{
	std::string description;
	description = "\nYou accidentally shoot yourself in the foot with the tranq gun and pass out for a unknown amount of time.";
	return description;
}


std::string getTranqGunCorrectAreaDescription()
{
	std::string description;
	description = "\nThe lion... Seems like a good target for the tranq gun. You take careful aim, pull the trigger, and a tranq dart sticks the lion in the leg."
		"He passes out into a coma-like slumber, enabling you to sneak past him to check out the cave behind.\nYou carefully step past the lion into the cave, looking around. There's not much light, but"
		" you can see something glinting in the back of the cave. Investigating, you find a key that is conveniently labeled 'Outside'"
		"\nKey added to bag!\n";
	return description;
}


std::string getKeyDescription()
{
	std::string description;
	description = "\nYou pull the key out of your pocket and look around for somewhere to use it. Nothing stands out, so you place the key back into your pocket.";
	return description;
}

std::string getKeyCorrectAreaDescription()
{
	std::string description;
	description = "\nYou pull the key out of your pocket, studying the lock on the door leading outside... Deciding to test the key, you insert it into the lock,\n"
		"give it a turn, unlocking the door, opening the way out of the abandoned zoo.";
	return description;
}

std::string getRocketBootsDescription()
{
	std::string description;
	description = "\nYou press the button to activate the rocket boots, blasting off from the floor with a bit more force than you expected, slamming your head on the ceiling, "
		"adding to your already splitting headache.";
	return description;
}

std::string getRocketBootsCorrectAreaDescription()
{
	std::string description;
	description = "\nYou activate the rocket boots, zip up to the top of the tree and land gracefully at the top. You realize the shiny object was a tranq gun.\n"
		"\nTranq gun added to inventory!\n";
	return description;
}