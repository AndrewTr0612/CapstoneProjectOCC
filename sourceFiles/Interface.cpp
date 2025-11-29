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
    string stars(45, '*');

    cout << stars << "\n"
         << "\t\tMAIN MENU\n"
         << stars << "\n\n"
         << "Select one of the following:\n\n"
         << "\t1: Print all bots\n"
         << "\t2: Print all clubs\n"
         << "\t3: Print a bot's votes from a club\n"
         << "\t4: Print a bot's total votes\n"
         << "\t5: Print winner\n"
         << "\t6: Print final results\n"
         << "\t7: To exit\n" << endl;
}


// Definition function exitMessage
void exitMessage()
{
    // Your code here...
    cout << string(45, '-') << "\n"
         << "  Thanks for running the STEM Bot Election!\n"
         << "   May the best bot serve wisely. Goodbye!\n"
         << string(45, '-') << endl;
}


// Definition function noDataMessage
void noDataMessage()
{
    // Your code here...
    cout << "\t*** No data is available.\n"
         << "\t*** Please contact the administrator." << endl;
}


// Definition function processMenu
void processMenu(const BotList& botList, const Election& election)
{
    int userChoice = 0;

    cout << "Enter your choice: ";
    cin >> userChoice;
    cout << "\n";

    while (userChoice != 7)
    {
        switch (userChoice)
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

                cout << "Enter club's name: ";
                string clubName;
                cin >> clubName;

                election.printBotVotesFromClub(botName, clubName);
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
        cout << endl;
        system("Pause");
        cout << endl;
        displayMenu();

        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << "\n";
    }
    exitMessage();

}