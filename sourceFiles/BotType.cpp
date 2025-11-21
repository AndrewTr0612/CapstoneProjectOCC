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