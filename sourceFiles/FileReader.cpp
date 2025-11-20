/*
	Shamaan, Alexander (team leader)
	Cruz, Alejandro
	Truong, Andrew
	Truong, Phillip

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#include "FileReader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void readBotData(BotList& botList)
{
	ifstream inputBotFile("bots.csv");
	if (!inputBotFile.is_open())
	{
		cerr << "*** Error opening bots.csv" << endl;
	}
	else
	{
		string botLine,
			botName,
			botAbility,
			botTrait;

		getline(inputBotFile, botLine);
		while (getline(inputBotFile, botLine))
		{
			stringstream botStream(botLine);
			getline(botStream, botName, ',');
            getline(botStream, botAbility, ',');
            getline(botStream, botTrait);

            botList.insertBot(
                BotType(botName, botAbility, botTrait));
		}
	}
    inputBotFile.close();
}
void readElectionResults(Election& electionResults)
{
    ifstream inputVoteFile("votes.csv");
    if (!inputVoteFile.is_open())
    {
        cerr << "*** Error opening votes.csv" << endl;
    }
    else
    {
        string voteLine;
        getline(inputVoteFile, voteLine);
        stringstream voteStream(voteLine);

        string cell;
        vector<string> clubNames;
        getline(voteStream, cell, ',');
        while (getline(voteStream, cell, ','))
        {
            clubNames.push_back(cell);
        }
        electionResults.addClubs(clubNames);

        string botName;
        while (getline(inputVoteFile, voteLine))
        {
            voteStream.clear();
            voteStream.str(voteLine);
            getline(voteStream, botName, ',');

            vector<int> votesForBot;
            while (getline(voteStream, cell, ','))
            {
                votesForBot.push_back(stoi(cell));
            }

            electronResults.addBots(botName, votesForBot);
        }

    }
    inputVoteFile.close();
}