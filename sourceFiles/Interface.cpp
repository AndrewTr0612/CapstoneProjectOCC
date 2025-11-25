/*
    Shamaan, Alexander (team leader)
    Cruz, Alejandro
    Truong, Andrew
    Truong, Phillip

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "Interface.h"


#include <iostream>
#include <string>


using namespace std;


// Definition function displayMenu
void displayMenu()
{
	// Your code here...
}


// Definition function exitMessage
void exitMessage()
{
	// Your code here...
}


// Definition function noDataMessage
void noDataMessage()
{
	// Your code here...
}


// Definition function processMenu
void processMenu(const BotList& botList, const Election& election)
{
	int userChoice = 0;
    while (userChoice != 7)
    {
        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << "\n\n";
        switch(userChoice)
        {
            case 1:
                if (botList.isEmpty())
                    noDataMessage();
                else
                    botList.printAllBotsInfo();
                break;
            case 2:
                if (election.noDataFound())
                    noDataMessage();
                else
                    election.printAllClubs();
                break;

            case 3:
                if (election.noDataFound())
                    noDataMessage();
                else
                {
                    cout << "Enter bot's name: ";
                    string botName;
                    cin >> botName;

                    cout << "\nEnter club's name: ";
                    string clubName;
                    cin >> clubName;
                    
                    cout << "\n\n";
                    election.printBotVotesFromClub(
                        botName, clubName);
                }
                break;
            case 4:
                if (election.noDataFound())
                    noDataMessage();
                else
                {
                    cout << "Enter bot's name: ";
                    string botName;
                    cin >> botName;

                    election.printBotTotalVotes(botName);
                }
                break;
            case 5:
                if (election.noDataFound())
                    noDataMessage();
                else
                    election.printWinner();
                break;
            case 6:
                if (election.noDataFound())
                    noDataMessage();
                else
                    election.printFinalResults();
                break;
        }
    }
    cout << string(60, '-')
         << "\n  Thanks for running the STEM Bot Election!"
         << "\n   May the best bot serve wisely. Goodbye!\n"
         << string(60, '-') << "\n\n";
    system("Pause");
}
