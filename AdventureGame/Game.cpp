#include "Game.h"
#include <iostream>

Game::Game()
    : player(new Player())
    , areas()
    , currentAreaIndex(0)
    , currentArea(nullptr)
    , play(true)
{
    // TEMP: DEBUG
    //std::cout << "Game default constructor called.\n";
}

Game::Game(const Game& other)
    : player(new Player(*(other.player)))
    , areas(other.areas) // should probably do deep copy
    , currentAreaIndex(other.currentAreaIndex)
    , currentArea(other.currentArea) // could cause problems!
    , play(other.play)
{
    // TEMP: DEBUG
    //std::cout << "Game copy constructor called.\n";
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
    Area* courtyard = new Area();
    courtyard->name = "Courtyard";
    courtyard->description = "This overgrown courtyard is filled with crumbling statuary. The haunting caws of crows echos through the ruins.";
    areas.push_back(courtyard);

    Area* entryHall = new Area();
    entryHall->name = "Entry Hall";
    entryHall->description = "The long entry hall houses rusted suits of armor lining the entrance. Strange paintings on the walls seem to follow you with their eyes.";
    areas.push_back(entryHall);

    Area* throneRoom = new Area();
    throneRoom->name = "Throne Room";
    throneRoom->description = "A stained and faded red carpet leads down the room to a jagged, black stone throne.";
    areas.push_back(throneRoom);

    // Set up exits
    courtyard->exits.push_back(entryHall);
    entryHall->exits.push_back(courtyard);
    entryHall->exits.push_back(throneRoom);
    throneRoom->exits.push_back(entryHall);

    // Set up current area
    currentArea = courtyard;

    std::cout << "Please enter your name.\n";
    std::getline(std::cin, player->name);

    std::cout << "Welcome!\n";
    player->Display();

    areas[currentAreaIndex]->Display();
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

        if (player->stamina <= 0)
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
    std::cout << "\t3.\tCancel\n";

    int choice;
    std::cin >> choice;
    // TODO: input validation stuff

    switch (choice)
    {
    case 1:
        player->Display();
        break;
    case 2:
        currentArea->Display();
        break;
    default:
        break;
    }
}

void Game::Move()
{
    std::cout << "Where would you like to move?\n";
    
    currentArea->DisplayExits();

    int cancelNum = currentArea->exits.size() + 1;
    std::cout << "\t" << cancelNum << ".\t" << "Cancel" << "\n";

    int choice;
    std::cin >> choice;

    if (choice > 0 && choice < cancelNum)
    {
        choice = choice - 1; // start from 0 not 1
        currentArea = currentArea->exits[choice];
        currentArea->Display();
        player->stamina -= 5;
    }
}

void Game::Quit()
{
    std::cout << "You have chosen to quit.\n";
    std::cout << "Thanks for playing!\n";
    play = false;
}
