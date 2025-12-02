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
#include <iomanip>
#include <numeric> 

using namespace std;

void Election::addClubs(const vector<string>& theClubs)
{
    clubs = theClubs;
}

void Election::addBots(const string& botName,
                       const vector<int>& votesForBot)
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
void Election::printBotVotesFromClub(const string& botName,
                                     const string& clubName) const
{
    auto clubIter = find(clubs.begin(), clubs.end(), clubName);
    int clubIndex =
        static_cast<int>(distance(clubs.begin(), clubIter));

    auto botIter = electoralVotes.find(botName);
    const vector<int>& votes = botIter->second;

    int voteCount = votes.at(clubIndex);

    cout << "\n\t" << botName << " received " << voteCount
         << " vote(s) from " << clubName << "." << endl;
}

void Election::printBotTotalVotes(const string& botName) const
{
    int totalVotes = 0;
    auto botIter = electoralVotes.find(botName);

    const vector<int>& votes = botIter->second;

    totalVotes = accumulate(votes.begin(), votes.end(), 0);

    cout << "\n\t" << botName << " received a total of " 
         << totalVotes << " vote(s)." << endl;
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

    cout << "\tWinner: " << winningBot << " with "
         << highestVotes << " vote(s)." << endl;
}

void Election::printFinalResults() const
{
    cout << "\t" << left << setw(15) << "Bot";

    for (const string& abbr : CLUB_ABBREVIATIONS)
    {
        cout << setw(3) << abbr;
    }

    string stars(52, '*');

    cout << setw(2) << "" << "Total\n\t"
        << stars << endl;

    for (const auto& pair : electoralVotes)
    {
        const string& botName = pair.first;
        const vector<int>& votes = pair.second;

        cout << "\t" << setw(16) << left << botName;

        for (int vote : votes)
        {
            cout << setw(3) << vote;
        }

        int totalVotes = accumulate(votes.begin(), votes.end(), 0);
        cout << setw(4) << "" << right << totalVotes << endl;
    }
}

void Election::printAllClubs() const
{
    string divider(23, '-');

    cout << "\t" << setw(9) << left << "CLUB"
         << "(abbreviation)\n"
         << "\t" << divider << endl;

    for (size_t i = 0; i < clubs.size(); ++i)
    {
        cout << "\t" << setw(9) << left << clubs[i]
             << "(" << CLUB_ABBREVIATIONS[i] << ")" << endl;
    }
}