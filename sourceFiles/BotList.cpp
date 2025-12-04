/*
	Shamaan, Alexander (Team leader)
	Cruz, Alejandro
	Truong, Andrew
	Truong, Phillip

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#include "BotList.h"

#include <iostream>
#include <iomanip>

using namespace std;

void BotList::insertBot(const BotType& theBot)
{
	botList.insert(theBot);
}

int BotList::getCount() const
{
	return static_cast<int>(botList.size());
}

bool BotList::getBotByName(const string& name, BotType& outBot) const
{
	BotType tempBotType(name, "", "");
	auto iterSet = botList.find(tempBotType);

	if (iterSet != botList.end())
	{
		outBot = *iterSet;
		return true;
	}

	return false;
}

bool BotList::isEmpty() const
{
	return botList.empty();
}

void BotList::printAllBotsNames() const
{
	cout << "Names:\n";

	for (const auto& aBot : botList)
	{
		aBot.printBotName();
	}
}

void BotList::printAllBotsInfo() const
{
	string dash(34, '-');

	cout << left << "\t" << setw(17) << "BOT NAME"
		 << "(ability, trait)\n\t"
		 << dash << "\n";

	for (const auto& aBot : botList)
	{
		aBot.printBotInfo();
	}
}