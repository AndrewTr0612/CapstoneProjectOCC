#ifndef BOTTYPE_H
#define BOTTYPE_H

#include <string>

using namespace std;

class BotType
{
public:
	BotType() {}
	BotType(const string& botName, const string& botAbility, const string& botTrait)
		: name(botName), ability(botAbility), trait(botTrait) {
	}

	string getBotName() const { return name; }
	string getBotAbility() const { return ability; }
	string getBotTrait() const { return trait; }

	void printBotName() const;
	void printBotInfo() const;

	bool operator< (const BotType& paramBot) const;

private:

	string name;
	string ability;
	string trait;
};

#endif