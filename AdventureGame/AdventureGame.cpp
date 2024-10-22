#include <iostream>
#include <string>
#include <vector>

int DisplayAndReadPlayerAction()
{
    std::cout << "What would you like to do?\n";
    std::cout << "\t1.\tLook\n";
    std::cout << "\t2.\tMove\n";
    std::cout << "\t3.\tQuit\n";

    int choice;
    std::cin >> choice;
    // TODO: input validation stuff

    return choice;
}
void DisplayPlayer(std::string name, std::string desc, int stam)
{
    std::cout << "You are " << name << ", " << desc << "\n";
    std::cout << "You have " << stam << " stamina.\n";
}

void DisplayArea(std::string areaName, std::string areaDescription)
{
    std::cout << "You find yourself in the " << areaName << "\n";
    std::cout << areaDescription << "\n";
}

int Look()
{
    std::cout << "What would you like to look at?\n";
    std::cout << "\t1.\tPlayer\n";
    std::cout << "\t2.\tArea\n";
    std::cout << "\t3.\tCancel\n";

    int choice;
    std::cin >> choice;
    // TODO: input validation stuff

    return choice;
}

void Move(std::vector<std::string> areaNames, std::vector<std::string> areaDescriptions, int& currentAreaIndex, int& stamina)
{
    std::cout << "Where would you like to move?\n";
    int lower = currentAreaIndex - 1;
    int lowerDisplayNum = -1;
    int upper = currentAreaIndex + 1;
    int upperDisplayNum = -1;
    int displayNum = 0;
    if (lower >= 0)
    {
        ++displayNum;
        lowerDisplayNum = displayNum;
        std::cout << "\t"<< displayNum <<".\t"<< areaNames[lower] <<"\n";
    }
    if (upper < areaNames.size())
    {
        ++displayNum;
        upperDisplayNum = displayNum;
        std::cout << "\t" << displayNum << ".\t" << areaNames[upper] << "\n";
    }
    ++displayNum;
    std::cout << "\t" << displayNum << ".\t" << "Cancel" << "\n";

    int choice;
    std::cin >> choice;
    
    if (choice == lowerDisplayNum)
    {
        stamina -= 5;
        currentAreaIndex = lower;
        DisplayArea(areaNames[currentAreaIndex], areaDescriptions[currentAreaIndex]);
    }
    if (choice == upperDisplayNum)
    {
        stamina -= 5;
        currentAreaIndex = upper;
        DisplayArea(areaNames[currentAreaIndex], areaDescriptions[currentAreaIndex]);
    }

}

void Quit()
{
    std::cout << "You have chosen to quit.\n";
    std::cout << "Thanks for playing!\n";
}


int main()
{
    std::string playerName = "Steve";
    std::string playerDescription = "A brave warrior.";
    int playerStamina = 100;

    std::vector<std::string> areaNames;
    std::vector<std::string> areaDescriptions;

    areaNames.push_back("Courtyard");
    areaNames.push_back("Entry Hall");
    areaNames.push_back("Throne Room");

    areaDescriptions.push_back("This overgrown courtyard is filled with crumbling statuary. The haunting caws of crows echos through the ruins.");
    areaDescriptions.push_back("The long entry hall houses rusted suits of armor lining the entrance. Strange paintings on the walls seem to follow you with their eyes.");
    areaDescriptions.push_back("A stained and faded red carpet leads down the room to a jagged, black stone throne.");

    int currentAreaIndex = 0;

    bool play = true;

    std::cout << "Please enter your name.\n";
    std::getline(std::cin, playerName);

    std::cout << "Welcome!\n";
    DisplayPlayer(playerName, playerDescription, playerStamina);

    DisplayArea(areaNames[currentAreaIndex], areaDescriptions[currentAreaIndex]);

    while (play)
    {
        int choice = DisplayAndReadPlayerAction();

        switch (choice)
        {
        case 1:
        {
            int lookChoice = Look();
            switch (lookChoice)
            {
            case 1:
                DisplayPlayer(playerName, playerDescription, playerStamina);
                break;
            case 2:
                DisplayArea(areaNames[currentAreaIndex], areaDescriptions[currentAreaIndex]);
                break;
            default:
                break;
            }
            break;
        }
        case 2:
            Move(areaNames, areaDescriptions, currentAreaIndex, playerStamina);
            break;
        case 3:
            Quit();
            play = false;
            break;
        default:
            break;
        }
    }

}


