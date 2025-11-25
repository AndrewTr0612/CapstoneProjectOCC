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

#include <iostream>

using namespace std;

int main()
{
    // IMPORTANT TESTING RULES:
    //
    // 1. DO NOT delete or change any of the provided test comments.
    // 2. Replace each comment with the appropriate C++ test code.
    // 3. Each test must PRODUCE OUTPUT--silent or skipped tests will lose points.
    // 4. If a test fails, fix YOUR implementation, not the test.
    // 5. You may add additional tests for clarity, but do not remove any required ones.

    cout << "===== PHASE 1: Testing BotType =====\n\n";

    // Test default constructor, BotType::printBotInfo().
    // Your code here...
    BotType aBot1;
    aBot1.printBotInfo();

    // Test parameterized constructor + all accessors + all print functions.
    // Your code here...
    aBot1 = BotType("TestBot", "TestingAbility", "TestingTrait");
    aBot1.getBotName();
    aBot1.getBotAbility();
    aBot1.getBotTrait();
    aBot1.printBotName();
    aBot1.printBotInfo();

    BotType aBot2("AlphaBot", "AlphaAbility", "AlphaTrait");
    cout << (aBot1 < aBot2) << endl; // Expected: 0 (false)

    cout << "===== PHASE 2: Testing BotList (manual insert) =====\n\n";

    // Create BotList object.
    // Your code here...
    BotList botList1;

    // Test BotList::isEmpty() on an empty list
    // Your code here...
    cout << botList1.isEmpty() << endl;

    // Create and insert a few bots in the list.
    // Your code here...
    BotType aBot3("ChatGPT", "Language Model", "OpenAI");
    botList1.insertBot(aBot3);
    BotType aBot4("DALL-E", "Image Generation", "OpenAI");
    botList1.insertBot(aBot4);
    BotType aBot5("AlphaGo", "Game Playing", "DeepMind");
    botList1.insertBot(aBot5);

    // Test BotList::getCount()
    // Your code here...
    cout << botList1.getCount() << endl;

    // Test BotList::isEmpty()
    // Your code here...
    cout << botList1.isEmpty() << endl;

    // Test BotList::printAllBotsNames()
    // Your code here...
    botList1.printAllBotsNames();

    // Test BotList::printAllBotsInfo()
    // Your code here...
    botList1.printAllBotsInfo();

    // Test BotList::getBotByName() - found case
    // Your code here...
    cout << botList1.getBotByName("ChatGPT", aBot1) << endl;
    cout << aBot1.getBotName() << endl;

    // Create a BotList object.   
    // Your code here...
    BotList botList2;

    // Test BotList::getBotByName() - not found case 
    // Expected result: returns false AND outBot must remain unchanged.
    // Your code here...
    cout << botList2.getBotByName("ChatGPT", aBot2) << endl;
    cout << aBot2.getBotName() << endl;

    cout << "===== PHASE 3: Testing FileReader with bots.csv =====\n\n";

    // Create a BotList object.
    // Your code here...
    BotList botList3;

    // Test BotList::getCount
    // Your code here...
    botList3.getCount();

    // Call readBotData
    // Your code here...
    readBotData(botList3);

    // After calling readBotData, verify:
    // fileBotList.getCount() == number of bots in bots.csv
    // AND printed bot info matches the file data exactly.
    // Your code here...
    int numberOfBotsInFile = 15;

    if (botList3.getCount() == numberOfBotsInFile)
        cout << "Number of bots matches." << endl;
    else
        cout << "Number of bots do not match." << endl;

    botList3.printAllBotsInfo();

    cout << "===== PHASE 4: Testing Election and FileReader with votes.csv =====\n\n";

    // Create an Election object.
    // Your code here...
    Election election1;

    // Before reading any data, test Election::noDataFound
    // Your code here...
    cout << election1.noDataFound() << endl;

    // Test readElectionResults
    // Your code here...
    readElectionResults(election1);

    // Test Election::noDataFound
    // Your code here...
    cout << election1.noDataFound() << endl;

    // Test Election::printAllBots
    // Your code here...
    election1.printAllBots();

    cout << "===== PHASE 5: Testing Election menu operations with specific bot/club =====\n\n";

    // Choose an existing bot name and club name and test all print function of the Election class
    // Your code here...
    election1.printAllBots();
    election1.printBotVotesFromClub("EcoMentor", "NetClub");
    election1.printBotTotalVotes("EcoMentor");
    election1.printWinner();
    election1.printFinalResults();

    cout << "===== All tests completed. =====\n";

    cout << endl;
    system("Pause");
    return 0;
}