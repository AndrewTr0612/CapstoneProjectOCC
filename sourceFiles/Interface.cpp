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
   
    cout << "*********************************************" << endl;
    cout << "              MAIN MENU                      " << endl;
    cout << "*********************************************" << endl; 
    cout << "Select one of the following:" << endl;
    cout << "\n";
    
    cout << "\t1: Print all bots" << endl;
    cout << "\t2: Print all clubs" << endl;
    cout << "\t3: Print a bot's votes from a club" << endl;
    cout << "\t4: Print a bot's total votes" << endl;
    cout << "\t5: Print winner" << endl;
    cout << "\t6: Print final results" << endl;
    cout << "\t7: To exit" << endl;
    cout << "\n";
    cout << "Enter your choice: ";
}


// Definition function exitMessage
void exitMessage()
{
	cout << "\nThank you for using the Election Program. Goodbye!" << endl;
}


// Definition function noDataMessage
void noDataMessage()
{
    displayMenu();

	cout << "*** No data is available." << endl;
	cout << "*** Please contact the administrator." << endl;
}


// Definition function processMenu
void processMenu(const BotList& botList, const Election& election)
{
    int choice = 0;

    while (choice != 7)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                if (botList.isEmpty())
                {
                    noDataMessage(); 
                }
                else
                {
                    botList.printAllBotsInfo(); 
                }
                break; 
            case 2:
            
                if (election.noDataFound())
                {
                    noDataMessage();
                }
                else
                {
                    election.printAllClubs();
                }
                break;
            
            case 3:

                if (election.noDataFound())
                {
                    noDataMessage();
                }
                else
                {
                    string botName, clubName;
                    cout << "Enter bot's name: ";
                    getline(cin >> ws, botName);
                    cout << "Enter club's name: ";
                    getline(cin >> ws, clubName);
                    election.printBotVotesFromClub(botName, clubName);
                }

                break;
            
            case 4:
                if(election.noDataFound())
                { 
                    noDataMessage();
                }
                else
                {
                    string botName;
                    cout << "Enter bot's name: ";
                    getline(cin >> ws, botName);
                    election.printBotTotalVotes(botName);
                }
                break;
            case 5:
                if (election.noDataFound())
                {
                    noDataMessage(); 
                }
                else
                {
                    election.printWinner();
                }
                break;
            case 6:
				if (election.noDataFound())
                {
                    noDataMessage();
                }
                else
                {
					election.printFinalResults();
                }
                break;
            case 7:
                exitMessage();
                break;
        }
		if (choice >= 1 && choice <= 6)
        {
            cout << "\nPress any key to continue... ";
            cin.ignore(); 
        }
    
	}
}
