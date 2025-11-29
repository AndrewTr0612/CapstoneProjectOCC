/*
    Shamaan, Alexander (team leader)
    Cruz, Alejandro
    Truong, Andrew
    Truong, Phillip

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "BotType.h"
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
    Election election1;
    readElectionResults(election1);
    displayMenu();
    processMenu(aBotList, election1);

    cout << endl;
    system("Pause");
    return 0;
}