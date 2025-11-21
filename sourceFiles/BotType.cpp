/*
	Shamaan, Alexander (team leader)
	Cruz, Alejandro
	Truong, Andrew
	Truong, Phillip

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#include "BotType.h"

#include <iostream>

using namespace std;

void BotType::printBotName() const
{
	cout << name << endl;
}

void BotType::printBotInfo() const
{
	cout << name << "\t\t" << ability << "\t\t" << trait << endl;
}

bool BotType::operator< (const BotType& paramBot) const
{
	return name < paramBot.name;
}