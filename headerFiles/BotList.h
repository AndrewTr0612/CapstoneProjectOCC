#ifndef BOTLIST_H
#define BOTLIST_H

#include "BotType.h"

#include <set>

class BotList
{
public:
	void insertBot(BotType& theBot);
	int getCount() const;
	std::bool getBotByName(const std::string& name, BotType& outBot);
	std::bool isEmpty() const;
	void printAllBotsNames() const;
	void printAllBotsInfo() const;

private:

	set<BotType> aBotSet;
};

#endif