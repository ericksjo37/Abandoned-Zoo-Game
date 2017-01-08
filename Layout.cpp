/*
Author: Josh Erickson
Description: Layout of the abandoned zoo, will connect all the rooms and initialize parts of them
*/

#include "Layout.hpp"

Zoo *createZoo()	//This will initialize all the zoo areas and create a new zoo and return that zoo
{
	Zoo *zoo = new Zoo;	//creating a new zoo pointer

	zoo->elephantPit = createElephantPit();	//Creating all the areas
	zoo->foodRoom = createFoodRoom();
	zoo->gorillaPit = createGorillaPit();
	zoo->lionCage = createLionCage();
	zoo->midPathway = createMidPathway();
	zoo->northPathway = createNorthPathway();
	zoo->outside = createOutside();
	zoo->snakePit = createSnakePit();
	zoo->southPathway = createSouthPathway();
	zoo->startingRoom = createStartingRoom();
	zoo->toolRoom = createToolRoom();

	setLayout(zoo);
	setHiddenAreas(zoo);
	return zoo;
}

void setLayout(Zoo *zoo)		//This function will connect all the rooms to the areas they should be connected to
{
	Area *elephantPit = getElephantPit(zoo);
	Area *foodRoom = getFoodRoom(zoo);
	Area *gorillaPit = getGorillaPit(zoo);
	Area *lionCage = getLionCage(zoo);
	Area *midPathway = getMidPathway(zoo);
	Area *northPathway = getNorthPathway(zoo);
	Area *outside = getOutside(zoo);
	Area *snakePit = getSnakePit(zoo);
	Area *southPathway = getSouthPathway(zoo);
	Area *startingRoom = getStartingRoom(zoo);
	Area *toolRoom = getToolRoom(zoo);


	elephantPit->setWest(foodRoom);		//Ele area connections
	elephantPit->setEast(midPathway);

	foodRoom->setEast(elephantPit);		//Food area connections

	gorillaPit->setEast(northPathway);	//Gorilla area connections

	lionCage->setWest(midPathway);		//Lion area connections

	midPathway->setNorth(northPathway);	//Mid Path connections
	midPathway->setEast(lionCage);
	midPathway->setSouth(southPathway);
	midPathway->setWest(elephantPit);

	northPathway->setEast(snakePit);	//North Path connections
	northPathway->setSouth(midPathway);
	northPathway->setWest(gorillaPit);

	outside->setNorth(southPathway);	//Outside connections

	snakePit->setWest(northPathway);	//Snake connections

	southPathway->setNorth(midPathway);	//South Path connections
	southPathway->setEast(startingRoom);
	southPathway->setSouth(outside);
	southPathway->setWest(toolRoom);

	startingRoom->setWest(southPathway);	//Starting area connections

	toolRoom->setEast(southPathway);		//Tool area connections

}

void setHiddenAreas(Zoo *zoo)		//Sets the hidden areas in the zoo, the only hidden area in the zoo being the food room connected to the ele pit
{
	ElephantPit *elephantPit = getElephantPitType(zoo);
	Area *foodRoom = getFoodRoom(zoo);

	elephantPit->setHiddenFoodRoom(foodRoom);
}

/*
All create functions below create a new pointer of that type and initialize a couple values
*/

ElephantPit *createElephantPit()	
{
	ElephantPit *elephantPit = new ElephantPit("Elephant Pit");
	std::string desc = "You open the door reading Elephant Pit, walk in to a large enclosure with 5 or 6 elephants roaming"
		"lazily around the room. There's a few trees in the room, but nothing that you can see of any value to you.\n";
	elephantPit->setAreaAnnouncement(desc);
	elephantPit->setCorrectItem(AIRHORN);

	return elephantPit;
}

FoodRoom *createFoodRoom()		
{
	FoodRoom *foodRoom = new FoodRoom("Food Room");
	std::string desc = "You walk through the hole in the wall created by the stampede to view another room containing different types of animal"
		" feed.\n";
	std::string lootDesc = "\nLots of food in this area... Those bananas seem like they could be useful.\n\nBananas added to bag!\n";
	foodRoom->setAreaAnnouncement(desc);
	foodRoom->setLootDesc(lootDesc);
	foodRoom->setItem(BANANAS);

	return foodRoom;
}

GorillaPit *createGorillaPit()
{
	GorillaPit *gorillaPit = new GorillaPit("Gorilla Pit");
	std::string desc = "You open the door reading Gorilla Pit, walk in to an enclosure containing a single huge gorilla resting against a tree."
		" There's a small, dirty stream running close by the gorilla and the lights in the enclosure are dim, flickering.";
	gorillaPit->setAreaAnnouncement(desc);
	gorillaPit->setCorrectItem1(BANANAS);
	gorillaPit->setCorrectItem2(ROCKETBOOTS);
	gorillaPit->setLoot(TRANQGUN);

	return gorillaPit;
}

LionCage *createLionCage()
{
	LionCage *lionCage = new LionCage("Lion Cage");
	std::string desc = "You crack open the door reading Caution, Lion Pit. There's a set of skull and crossbones on the door. Hilarious."
		" You peek inside, noting the single lion napping in front of the cave. As you enter the room, he slowly stands up and looks at you hungrily.\n";
	lionCage->setAreaAnnouncement(desc);
	lionCage->setCorrectItem(TRANQGUN);
	lionCage->setLoot(KEY);

	return lionCage;
}

MidPathway *createMidPathway()
{
	MidPathway *midPathway = new MidPathway("Middle Pathway");
	std::string desc = "You enter another part of the pathway between the animal exhibits. North is simply more pathway, south is more pathway, but to your "
		"right and left, you see doors that read Elephant Cage and Lion Pit.\n";
	midPathway->setAreaAnnouncement(desc);

	return midPathway;
}

NorthPathway *createNorthPathway()
{
	NorthPathway *northPathway = new NorthPathway("North Pathway");
	std::string desc = "You enter another part of the pathway between the animal exhibits. Ahead of you is a huge pile of debris. No going that way. To your "
		"right and left are doors reading Gorilla Pit and Snake Pit. To the south is more pathway, leading back to where you started.\n";
	northPathway->setAreaAnnouncement(desc);

	return northPathway;
}

Outside *createOutside()
{
	Outside *outside = new Outside("Outside");
	std::string desc = "You're finally outside that abandoned zoo.";
	outside->setAreaAnnouncement(desc);

	return outside;
}

SnakePit *createSnakePit()
{
	SnakePit *snakePit = new SnakePit("Snake Pit");
	std::string desc = "You open the door that reads Snake Pit. As you enter, you note the gigantic pit of snakes. This doesn't seem very zoo-like to "
		"just get a bunch of snakes and dump them into a single pit, but what do you know.\n";
	snakePit->setAreaAnnouncement(desc);
	snakePit->setCorrectItem(LADDER);
	snakePit->setLoot1(AIRHORN);
	snakePit->setLoot2(ROCKETBOOTS);

	return snakePit;
}

SouthPathway *createSouthPathway()
{
	SouthPathway *southPathway = new SouthPathway("South Pathway");
	std::string desc = "You walk into a section of pathway with 3 doors, one to the south, another to \nthe east, and another to the west."
		"The door to the south leads outside, but \nit's locked. The room to the east that collapsed must have "
		"been some sort of utility closet. The \ndoor to the west reads Tool Room. To the north, the pathway continues.\n";
	southPathway->setAreaAnnouncement(desc);

	return southPathway;
}

StartingRoom *createStartingRoom()
{
	StartingRoom *startingRoom = new StartingRoom("Starting Room");
	std::string desc = "It looks like some sort of utility closet, too dark to see if anything useful \nis in here. Maybe the light switch is outside.\n";
	startingRoom->setAreaAnnouncement(desc);

	return startingRoom;
}

ToolRoom *createToolRoom()
{
	ToolRoom *toolRoom = new ToolRoom("Tool Room");
	std::string desc = "There's numerous tools hanging on the wall and placed in shelves. Pruning shears, rakes, those kinds of things.\n";
	toolRoom->setAreaAnnouncement(desc);
	toolRoom->setItem(LADDER);

	return toolRoom;
}

/*
All get functions below return a pointer to that object within the zoo
*/

Area *getElephantPit(Zoo *zoo)
{
	ElephantPit *elephantPit = zoo->elephantPit;
	return elephantPit;
}

Area *getFoodRoom(Zoo *zoo)
{
	FoodRoom *foodRoom = zoo->foodRoom;
	return foodRoom;
}

Area *getGorillaPit(Zoo *zoo)
{
	GorillaPit *gorillaPit = zoo->gorillaPit;
	return gorillaPit;
}

Area *getLionCage(Zoo *zoo)
{
	LionCage *lionCage = zoo->lionCage;
	return lionCage;
}

Area *getMidPathway(Zoo *zoo)
{
	MidPathway *midPathway = zoo->midPathway;
	return midPathway;
}

Area *getNorthPathway(Zoo *zoo)
{
	NorthPathway *northPathway = zoo->northPathway;
	return northPathway;
}

Area *getOutside(Zoo *zoo)
{
	Outside *outside = zoo->outside;
	return outside;
}

Area *getSnakePit(Zoo *zoo)
{
	SnakePit *snakePit = zoo->snakePit;
	return snakePit;
}

Area *getSouthPathway(Zoo *zoo)
{
	SouthPathway *southPathway = zoo->southPathway;
	return southPathway;
}

Area *getStartingRoom(Zoo *zoo)
{
	StartingRoom *startingRoom = zoo->startingRoom;
	return startingRoom;
}

Area *getToolRoom(Zoo *zoo)
{
	ToolRoom *toolRoom = zoo->toolRoom;
	return toolRoom;
}

/*
The get "Type" functions return an object of the class type that they refer to, for ease of use in other functions later
*/

ElephantPit *getElephantPitType(Zoo *zoo)
{
	return zoo->elephantPit;
}

FoodRoom *getFoodRoomType(Zoo *zoo)
{
	return zoo->foodRoom;
}

GorillaPit *getGorillaPitType(Zoo *zoo)
{
	return zoo->gorillaPit;
}

LionCage *getLionCageType(Zoo *zoo)
{
	return zoo->lionCage;
}

SnakePit *getSnakePitType(Zoo *zoo)
{
	return zoo->snakePit;
}

SouthPathway *getSouthPathwayType(Zoo *zoo)
{
	return zoo->southPathway;
}

ToolRoom *getToolRoomType(Zoo *zoo)
{
	return zoo->toolRoom;
}

Outside *getOutsideAreaType(Zoo *zoo)
{
	return zoo->outside;
}