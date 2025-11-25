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
        << "\t7: To exit" << endl;
}


// Definition function exitMessage
void exitMessage()
{
    // Your code here...
    cout << string(45, '-') << endl;
    cout << "  Thanks for running the STEM Bot Election!" << endl;
    cout << "   May the best bot serve wisely. Goodbye!" << endl;
    cout << string(45, '-') << endl;
    cout << endl;
    cout << "Press any key to continue . . . " << endl;
}


// Definition function noDataMessage
void noDataMessage()
{
	// Your code here...
}


// Definition function processMenu
void processMenu(const BotList& botList, const Election& election)
{
	// Your code here...
}
