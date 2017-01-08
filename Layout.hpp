/*
Author: Josh Erickson
Description: Layout of the abandoned zoo, will connect all the rooms and initialize parts of them
*/

#include <string>
#include <iostream>
#include "ItemUsage.hpp"
#include "Area.hpp"
#include "ElephantPit.hpp"
#include "FoodRoom.hpp"
#include "GorillaPit.hpp"
#include "LionCage.hpp"
#include "MidPathway.hpp"
#include "NorthPathway.hpp"
#include "Outside.hpp"
#include "SnakePit.hpp"
#include "SouthPathway.hpp"
#include "StartingRoom.hpp"
#include "ToolRoom.hpp"

#ifndef LAYOUT_HPP
#define LAYOUT_HPP

struct Zoo {		//Zoo structure
	ElephantPit *elephantPit;
	FoodRoom *foodRoom;
	GorillaPit *gorillaPit;
	LionCage *lionCage;
	MidPathway *midPathway;
	NorthPathway *northPathway;
	Outside *outside;
	SnakePit *snakePit;
	SouthPathway *southPathway;
	StartingRoom *startingRoom;
	ToolRoom *toolRoom;
};

Zoo *createZoo();	//Creates the zoo
void setLayout(Zoo *zoo);	//Sets the layout of the zoo, area associations and all that
void setHiddenAreas(Zoo *zoo);	//Sets the hidden area(s) in the zoo
ElephantPit *createElephantPit();	//Below creates all the object/pointers
FoodRoom *createFoodRoom();
GorillaPit *createGorillaPit();
LionCage *createLionCage();
MidPathway *createMidPathway();
NorthPathway *createNorthPathway();
Outside *createOutside();
SnakePit *createSnakePit();
SouthPathway *createSouthPathway();
StartingRoom *createStartingRoom();
ToolRoom *createToolRoom();
Area *getElephantPit(Zoo *zoo);	//Below are all the getters for the Area pointers 
Area *getFoodRoom(Zoo *zoo);
Area *getGorillaPit(Zoo *zoo);
Area *getLionCage(Zoo *zoo);
Area *getMidPathway(Zoo *zoo);
Area *getNorthPathway(Zoo *zoo);
Area *getOutside(Zoo *zoo);
Area *getSnakePit(Zoo *zoo);
Area *getSouthPathway(Zoo *zoo);
Area *getStartingRoom(Zoo *zoo);
Area *getToolRoom(Zoo *zoo);
ElephantPit *getElephantPitType(Zoo *zoo);	//Below are all the getters to return the same type as the getter
FoodRoom *getFoodRoomType(Zoo *zoo);
GorillaPit *getGorillaPitType(Zoo *zoo);
LionCage *getLionCageType(Zoo *zoo);
SnakePit *getSnakePitType(Zoo *zoo);
SouthPathway *getSouthPathwayType(Zoo *zoo);
ToolRoom *getToolRoomType(Zoo *zoo);
Outside *getOutsideAreaType(Zoo *zoo);

#endif