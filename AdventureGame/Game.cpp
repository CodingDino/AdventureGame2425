#include "Game.h"
#include <iostream>

Game::Game()
    : player(new Player())
    , areas()
    , currentArea(nullptr)
    , play(true)
{
    // TEMP: DEBUG
    //std::cout << "Game default constructor called.\n";
}

Game::~Game()
{
    delete player;
    player = nullptr;

    // delete all areas
    for (int i = 0; i < areas.size(); ++i)
    {
        delete areas[i];
        areas[i] = nullptr;
    }
    areas.clear(); // Removes all items from vector

    // TEMP: DEBUG
    std::cout << "Game destructor called.\n";
}

void Game::Initialise()
{
    Area* courtyard = new Area(
        "Courtyard", 
        "This overgrown courtyard is filled with crumbling statuary. The haunting caws of crows echos through the ruins."
        );
    courtyard->AddFeature(new Feature("Fountain", "A bubbling fountain gurgles despite its age."));
    courtyard->AddItem(new Item("Pebble", "A simple pebble, small enough to fit in one's pocket."));
    courtyard->SetMonster(new Monster("Giant Bat", "A big flying bat who wants to suck your blood!"));
    areas.push_back(courtyard);

    Area* entryHall = new Area(
        "Entry Hall",
        "The long entry hall houses rusted suits of armor lining the entrance. Strange paintings on the walls seem to follow you with their eyes."
    );
    areas.push_back(entryHall);

    Area* sideRoom = new Area(
        "Side Room",
        "This dusty side room was once host for meetings, but seems to have later been used as a storage cupboard. Old boxes litter the floor."
    );
    areas.push_back(sideRoom);

    Area* throneRoom = new Area(
        "Throne Room",
        "A stained and faded red carpet leads down the room to a jagged, black stone throne."
    );
    areas.push_back(throneRoom);

    // Set up exits
    courtyard->AddExit(entryHall);
    entryHall->AddExit(courtyard);
    entryHall->AddExit(sideRoom);
    entryHall->AddExit(throneRoom);
    sideRoom->AddExit(entryHall);
    throneRoom->AddExit(entryHall);

    // Set up current area
    currentArea = courtyard;

    std::cout << "Please enter your name.\n";
    std::string tempName;
    std::getline(std::cin, tempName);
    player->SetName(tempName);

    std::cout << "Welcome!\n";
    player->Display();

    currentArea->Display();
}

void Game::Run()
{
    while (play)
    {
        int choice = DisplayAndReadPlayerAction();

        switch (choice)
        {
        case 1:
        {
            Look();
            break;
        }
        case 2:
            Move();
            break;
        case 3:
            Quit();
            break;
        default:
            break;
        }

        if (player->GetStamina() <= 0)
        {
            std::cout << "You are out of stamina. Game Over - better luck next time.\n";
            play = false;
        }
    }
}

int Game::DisplayAndReadPlayerAction()
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

void Game::Look()
{

    std::cout << "What would you like to look at?\n";
    std::cout << "\t1.\tPlayer\n";
    std::cout << "\t2.\tArea\n";

    int lastNum = 3;
    int featureStart = lastNum;

    for (int i = 0; i < currentArea->GetNumFeatures(); ++i)
    {
        Feature* thisFeature = currentArea->GetFeature(i);
        std::string featureName = thisFeature->GetName();
        std::cout << "\t" << lastNum << ".\t"<< featureName <<"\n";
        ++lastNum;
    }
    int itemStart = lastNum;

    for (int i = 0; i < currentArea->GetNumItems(); ++i)
    {
        Item* thisItem = currentArea->GetItem(i);
        std::string itemName = thisItem->GetName();
        std::cout << "\t" << lastNum << ".\t" << itemName << "\n";
        ++lastNum;
    }

    int monsterNum = lastNum;
    if (currentArea->GetMonster() != nullptr)
    {
        std::cout << "\t" << lastNum << ".\t" << currentArea->GetMonster()->GetName() << "\n";
        ++lastNum;
    }

    int cancelNum = lastNum;

    std::cout << "\t"<< lastNum << ".\tCancel\n";

    int choice;
    std::cin >> choice;
    // TODO: input validation stuff
    if (choice == 1)
    {
        player->Display();
    }
    else if (choice == 2)
    {
        currentArea->Display();
    }
    // Features
    else if (choice >= featureStart && choice < featureStart+currentArea->GetNumFeatures())
    {
        int i = choice - featureStart; // start at 0
        currentArea->GetFeature(i)->Display();
    }
    // Items
    else if (choice >= itemStart && choice < itemStart + currentArea->GetNumItems())
    {
        int i = choice - itemStart; // start at 0
        currentArea->GetItem(i)->Display();
    }
    // Monster
    else if (currentArea->GetMonster() != nullptr && choice == monsterNum)
    {
        currentArea->GetMonster()->Display();
    }
}

void Game::Move()
{
    std::cout << "Where would you like to move?\n";
    
    currentArea->DisplayExits();

    int cancelNum = currentArea->GetNumExits() + 1;
    std::cout << "\t" << cancelNum << ".\t" << "Cancel" << "\n";

    int choice;
    std::cin >> choice;

    if (choice > 0 && choice < cancelNum)
    {
        choice = choice - 1; // start from 0 not 1
        currentArea = currentArea->GetExit(choice);
        currentArea->Display();
        player->UseStamina(1);
    }
}

void Game::Quit()
{
    std::cout << "You have chosen to quit.\n";
    std::cout << "Thanks for playing!\n";
    play = false;
}
