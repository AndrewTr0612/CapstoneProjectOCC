/*
	Shamaan, Alexander (team leader)
	Cruz, Alejandro
	Truong, Andrew
	Truong, Phillip

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#ifndef BOTTYPE_H
#define BOTTYPE_H

#include <string>

class BotType
{
public:
	BotType() {}

	BotType(const std::string& botName, const std::string& botAbility, const std::string& botTrait)
		: name(botName), ability(botAbility), trait(botTrait) {
	}

	std::string getBotName() const { return name; }

	std::string getBotAbility() const { return ability; }

	std::string getBotTrait() const { return trait; }

	void printBotName() const;

	void printBotInfo() const;

	bool operator< (const BotType& paramBot) const;

private:

	std::string name;
	std::string ability;
	std::string trait;
};

#endif