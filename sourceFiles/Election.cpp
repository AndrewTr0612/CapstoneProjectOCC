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
#include <vector>
#include <iomanip> 

using namespace std;

const int BOT_TITLE_WIDTH = 15;
const int BOT_NAME_WIDTH = 16;
const int ABBREV_VOTE_WIDTH = 3;
const int TOTAL_VOTE_WIDTH = 2;
const int ALL_CLUBS_WIDTH = 9;

const vector<string> CLUB_ABBREVIATIONS = {
    "NL", "RG", "EC", "AE", "CH", "NC", "AX", "BL", "CY", "DL"
};

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
        clubIndex = static_cast<int>(distance(clubs.begin(), clubIter));
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
        cout << "\t" << botName << " received " << voteCount << " vote(s) from " << clubName << "." << endl;
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

        cout << "\n\t" botName << " received a total of " << totalVotes << " vote(s)." << endl;
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
        cout << "\tWinner: " << winningBot << " with " << highestVotes << " vote(s)." << endl;
    }
    else
    {
        cout << "\tNo votes were cast." << endl;
    }
}

void Election::printFinalResults() const
{
    cout << "\t" << left << setw(BOT_TITLE_WIDTH) << "Bot";

    for (const string& abbr : CLUB_ABBREVIATIONS)
    {
        cout << setw(ABBREV_VOTE_WIDTH) << abbr;
    }

    string stars(52, '*');

    cout << setw(TOTAL_VOTE_WIDTH) << "" << "Total\n\t"
        << stars << endl;

    for (const auto& pair : electoralVotes)
    {
        const string& botName = pair.first;
        const vector<int>& votes = pair.second;

        cout << "\t" << setw(BOT_NAME_WIDTH) << left << botName;

        for (int vote : votes)
        {
            cout << setw(ABBREV_VOTE_WIDTH) << vote;
        }

        int totalVotes = accumulate(votes.begin(), votes.end(), 0);
        cout << setw(4) << "" << right << totalVotes << endl;
    }
}

void Election::printAllClubs() const
{
    string divider(23, '-');

    cout << "\t" << setw(ALL_CLUBS_WIDTH) << left << "CLUB"
         << "(abbreviation)\n"
         << "\t" << divider << endl;

    for (size_t i = 0; i < clubs.size(); ++i)
    {
        cout << "\t" << setw(ALL_CLUBS_WIDTH) << left << clubs[i]
             << "(" << CLUB_ABBREVIATIONS[i] << ")" << endl;
    }
}