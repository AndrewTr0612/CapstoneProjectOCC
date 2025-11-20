/*
	(name header)
*/

#include <iostream>
#include "BotType.h"
#include "BotList.h"
#include "Election.h"
#include "FileReader.h"

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
    // Test parameterized constructor + all accessors + all print functions.
    // Your code here...
    aBot1 = BotType("TestBot", "TestingAbility", "TestingTrait");
    aBot1.printBotName();
    aBot1.printBotInfo();
    aBot1.getBotName();
    aBot1.getBotAbility();
    aBot1.getBotTrait();
    
    BotType aBot2("AlphaBot", "AlphaAbility", "AlphaTrait");
    cout << aBot1 < aBot2;
    cout << "===== PHASE 2: Testing BotList (manual insert) =====\n\n";

    // Create BotList object.
    // Your code here...
    BotList botList1 = BotList();
    
    // Test BotList::isEmpty() on an empty list
    // Your code here...
    cout << botList.isEmpty() << endl;
    // Create and insert a few bots in the list.
    // Your code here...
    botList.insertBot("ChatGPT", "OpenAI", 2022, "Language Model");
    botList.insertBot("DALL-E", "OpenAI", 2021, "Image Generation");
    botList.insertBot("AlphaGo", "DeepMind", 2015, "Game Playing");
    // Test BotList::getCount()
    // Your code here...
    cout << botList.getCount() << endl;
    // Test BotList::isEmpty()
    // Your code here...
    cout << botList.isEmpty() << endl;
    // Test BotList::printAllBotsNames()
    // Your code here...
    botList.printAllBotsNames();
    // Test BotList::printAllBotsInfo()
    // Your code here...
    botList.printAllBotsInfo();
    // Test BotList::getBotByName() - found case
    // Your code here...
    cout << botList.getBotByName("ChatGPT", botList1) << endl;
    // Create a BotList object.   
    // Your code here...
    BotList botList2;
    // Test BotList::getBotByName() - not found case 
    // Expected result: returns false AND outBot must remain unchanged.
    // Your code here...
    cout << getBotByName("Pollo", botList2);

    cout << "===== PHASE 3: Testing FileReader with bots.csv =====\n\n";

    // Create a BotList object.
    // Your code here...

    // Test BotList::getCount
    // Your code here...

    // Call readBotData
    // Your code here...

    // After calling readBotData, verify:
    // fileBotList.getCount() == number of bots in bots.csv
    // AND printed bot info matches the file data exactly.
    // Your code here...

    cout << "===== PHASE 4: Testing Election and FileReader with votes.csv =====\n\n";

    // Create an Election object.
    // Your code here...

    // Before reading any data, test BotList::noDataFound
    // Your code here...

    // Test readElectionResults
    // Your code here...

    // Test BotList::noDataFound
    // Your code here...

    // Test BotList::printAllBots
    // Your code here...

    cout << "===== PHASE 5: Testing Election menu operations with specific bot/club =====\n\n";

    // Choose an existing bot name and club name and test all print function of the Election class
    // Your code here...

    cout << "===== All tests completed. =====\n";

    cout << endl;
	system("Pause");
    return 0;
}
