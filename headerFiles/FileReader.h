/*
	(name header)
*/

#ifndef FILEREADER_H
#define FILEREADER_H

#include "BotList.h"
#include "Election.h"

void readBotData(BotList& botList);
void readElectionResults(Election& electionResults);

#endif