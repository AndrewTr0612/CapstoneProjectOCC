/*
    Shamaan, Alexander (Team leader)
    Cruz, Alejandro
    Truong, Andrew
    Truong, Phillip

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "BotList.h"
#include "Election.h"
#include "FileReader.h"
#include "Interface.h"

#include <iostream>

using namespace std;

int main()
{
    BotList aBotList;
    readBotData(aBotList);
    Election botElection;
    readElectionResults(botElection);
    displayMenu();
    processMenu(aBotList, botElection);

    cout << endl;
    system("Pause");
    return 0;
}