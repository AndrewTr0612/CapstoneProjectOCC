/*
    Shamaan, Alexander (Team leader)
    Cruz, Alejandro
    Truong, Andrew
    Truong, Phillip

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "FileReader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void readBotData(BotList& botList)
{
    ifstream inputBotFile("bots.csv");

    if (!inputBotFile.is_open())
    {
        cerr << "*** Error opening bots.csv." << endl;
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

            BotType aBot(botName, botAbility, botTrait);
            botList.insertBot(aBot);
        }

        inputBotFile.close();
    }
}

void readElectionResults(Election& electionResults)
{
    ifstream inputVoteFile("votes.csv");

    if (!inputVoteFile.is_open())
    {
        cerr << "*** Error opening votes.csv." << endl;
    }
    else
    {
        string voteLine;
        getline(inputVoteFile, voteLine);

        stringstream voteStream(voteLine);
        string cell;
        getline(voteStream, cell, ',');

        vector<string> clubNames;
        clubNames.reserve(NUM_CLUBS);

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
            votesForBot.reserve(NUM_CLUBS);

            while (getline(voteStream, cell, ','))
            {
                votesForBot.push_back(stoi(cell));
            }
            
            electionResults.addBots(botName, votesForBot);
        }

        inputVoteFile.close();
    }
}