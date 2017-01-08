/*
Author: Josh Erickson
Description: Header file for ItemUsage, will have functions to use items picked up
*/

#include <string>

#ifndef ITEMUSAGE_HPP
#define ITEMUSAGE_HPP

enum ITEMS {LADDER, AIRHORN, BANANAS, TRANQGUN, KEY, ROCKETBOOTS};	//All item types

std::string getItemName(ITEMS item);	//Gets the item name based on the enum passed
std::string getItemDescription(ITEMS item);	//Gets the item description in the wrong rooms or wrong time
std::string getItemCorrectAreaDescription(ITEMS item);	//Correct room description getter
std::string getLadderDescription();	//Descriptions below for all the items
std::string getLadderCorrectAreaDescription();
std::string getAirHornDescription();
std::string getAirHornCorrectAreaDescription();
std::string getBananasDescription();
std::string getBananasCorrectAreaDescription();
std::string getTranqGunDescription();
std::string getTranqGunCorrectAreaDescription();
std::string getKeyDescription();
std::string getKeyCorrectAreaDescription();
std::string getRocketBootsDescription();
std::string getRocketBootsCorrectAreaDescription();

#endif
