#ifndef BOTLIST_H
#define BOTLIST_H

#include "BotType.h"

#include <set>

class BotList
{
public:
	void insertBot(BotType& theBot);
	int getCount() const;
	bool getBotByName(const std::string& name, BotType& outBot);
	bool isEmpty() const;
	void printAllBotsNames() const;
	void printAllBotsInfo() const;

private:

	std::set<BotType> aBotSet;
};

#endif