#include "BotType.h"

#include <iostream>

using namespace std;

void BotType::printBotName() const
{
	cout << "Name: " << name << endl;
}

void BotType::printBotInfo() const
{
	cout << "Name: " << name
		<< "\nAbility: " << ability
		<< "\nTrait: " << trait << endl;
}

bool BotType::operator< (const BotType& paramBot) const
{
	return name < paramBot.name;
}