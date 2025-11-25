/*
	Shamaan, Alexander (team leader)
	Cruz, Alejandro
	Truong, Andrew
	Truong, Phillip

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#include "BotList.h"

#include <iostream>

using namespace std;

void BotList::insertBot(BotType& theBot)
{
	aBotSet.insert(theBot);
}

int BotList::getCount() const
{
	return static_cast<int>(aBotSet.size());
}

bool BotList::getBotByName(const string& name, BotType& outBot)
{
	BotType tempBotType(name, "", "");
	auto iterSet = aBotSet.find(tempBotType);

	if (iterSet != aBotSet.end())
	{
		outBot = *iterSet;
		return true;
	}

	return false;
}

bool BotList::isEmpty() const
{
	return aBotSet.empty();
}

void BotList::printAllBotsNames() const
{
	cout << "Names:\n";

	for (const auto& aBot : aBotSet)
	{
		aBot.printBotName();
	}
}

void BotList::printAllBotsInfo() const
{
	cout << "Name\t\t\tAbility\t\t\tTrait\n";

	for (const auto& aBot : aBotSet)
	{
		aBot.printBotInfo();
	}
}