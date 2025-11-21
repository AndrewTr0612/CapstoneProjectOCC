/*
    Shamaan, Alexander (team leader)
    Cruz, Alejandro
    Truong, Andrew
    Truong, Phillip

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "Election.h"

#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator> 
#include <iomanip> 

using namespace std;

void Election::addClubs(const vector<string>& theClubs)
{
    clubs = theClubs;
}

void Election::addBots(const string& botName, const vector<int>& votesForBot)
{
    electoralVotes[botName] = votesForBot;
}

bool Election::noDataFound() const
{
    return (clubs.empty() || electoralVotes.empty());
}

void Election::printAllBots() const
{
    cout << "Bots participating in the election:\n";

    for (const auto& pair : electoralVotes)
    {
        cout << "- " << pair.first << "\n";
    }
}

void Election::printBotVotesFromClub(const string& botName, const string& clubName) const
{
    bool dataFound = true;
    int clubIndex = -1;
    auto clubIter = find(clubs.begin(), clubs.end(), clubName);

    if (clubIter == clubs.end())
    {
        cout << "Error: Club '" << clubName << "' not found." << endl;
        dataFound = false;
    }
    else
    {
        clubIndex = distance(clubs.begin(), clubIter);
    }

    auto botIter = electoralVotes.find(botName);

    if (botIter == electoralVotes.end())
    {
        cout << "Error: Bot '" << botName << "' not found." << endl;
        dataFound = false;
    }

    if (dataFound)
    {
        const vector<int>& votes = botIter->second;
        int voteCount = votes.at(clubIndex);
        cout << botName << " received " << voteCount << " votes from " << clubName << "." << endl;
    }

}

void Election::printBotTotalVotes(const string& botName) const
{

    bool botFound = true;
    int totalVotes = 0;
    auto botIter = electoralVotes.find(botName);

    if (botIter == electoralVotes.end())
    {
        cout << "Error: Bot " << botName << " not found." << endl;
        botFound = false;
    }

    if (botFound)
    {
        const vector<int>& votes = botIter->second;

        // Use std::accumulate to sum all votes for the selected bot.
        // It starts the sum at the initial value of 0.
        totalVotes = accumulate(votes.begin(), votes.end(), 0);

        cout << botName << " received a total of " << totalVotes << " votes." << endl;
    }
}

void Election::printWinner() const
{
    string winningBot;
    int highestVotes = -1;

    for (const auto& pair : electoralVotes)
    {
        const string& botName = pair.first;
        const vector<int>& votes = pair.second;
        int totalVotes = 0;

        for (int vote : votes)
        {
            totalVotes += vote;
        }

        if (totalVotes > highestVotes)
        {
            highestVotes = totalVotes;
            winningBot = botName;
        }
    }

    if (!winningBot.empty())
    {
        cout << "The winning bot is " << winningBot << " with " << highestVotes << " votes." << endl << endl;
    }
    else
    {
        cout << "No votes were cast." << endl << endl;
    }
}

void Election::printFinalResults() const
{
    cout << setw(20) << left << "Bot Name";

    for (const string& club : clubs)
    {
        cout << setw(10) << left << club;
    }

    cout << setw(5) << right << "Total" << endl;

    for (const auto& pair : electoralVotes)
    {
        const string& botName = pair.first;
        const vector<int>& votes = pair.second;
        int totalVotes = 0;
        cout << setw(20) << left << botName;

        for (int vote : votes)
        {
            cout << setw(10) << left << vote;
            totalVotes += vote;
        }

        cout << setw(10) << left << totalVotes << endl;
    }
}