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
	
}

bool BotList::isEmpty() const
{
	return aBotSet.empty();
}

void BotList::printAllBotsNames() const
{
	for (const auto& aBot : aBotSet)
	{
		aBot.printBotName();
	}
}

void BotList::printAllBotsInfo() const
{
	for (const auto& aBot : aBotSet)
	{
		aBot.printBotInfo();
	}
}