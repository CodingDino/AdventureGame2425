#include "Game.h"
#include <iostream>

Game::Game()
    : player()
    , areas()
    , currentAreaIndex(0)
    , play(true)
{
    // TEMP: DEBUG
    //std::cout << "Game default constructor called.\n";
}

Game::Game(const Game& other)
    : player(other.player)
    , areas(other.areas)
    , currentAreaIndex(other.currentAreaIndex)
    , play(other.play)
{
    // TEMP: DEBUG
    //std::cout << "Game copy constructor called.\n";
}

Game::~Game()
{
    // TEMP: DEBUG
    std::cout << "Game destructor called.\n";
}

void Game::Initialise()
{
    Area tempArea;
    tempArea.name = "Courtyard";
    tempArea.description = "This overgrown courtyard is filled with crumbling statuary. The haunting caws of crows echos through the ruins.";
    areas.push_back(tempArea);

    tempArea.name = "Entry Hall";
    tempArea.description = "The long entry hall houses rusted suits of armor lining the entrance. Strange paintings on the walls seem to follow you with their eyes.";
    areas.push_back(tempArea);

    tempArea.name = "Throne Room";
    tempArea.description = "A stained and faded red carpet leads down the room to a jagged, black stone throne.";
    areas.push_back(tempArea);

    std::cout << "Please enter your name.\n";
    std::getline(std::cin, player.name);

    std::cout << "Welcome!\n";
    player.Display();

    areas[currentAreaIndex].Display();
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

        if (player.stamina <= 0)
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
        player.Display();
        break;
    case 2:
        areas[currentAreaIndex].Display();
        break;
    default:
        break;
    }
}

void Game::Move()
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
        std::cout << "\t" << displayNum << ".\t" << areas[lower].name << "\n";
    }
    if (upper < areas.size())
    {
        ++displayNum;
        upperDisplayNum = displayNum;
        std::cout << "\t" << displayNum << ".\t" << areas[upper].name << "\n";
    }
    ++displayNum;
    std::cout << "\t" << displayNum << ".\t" << "Cancel" << "\n";

    int choice;
    std::cin >> choice;

    if (choice == lowerDisplayNum)
    {
        player.stamina -= 5;
        currentAreaIndex = lower;
        areas[currentAreaIndex].Display();
    }
    if (choice == upperDisplayNum)
    {
        player.stamina -= 5;
        currentAreaIndex = upper;
        areas[currentAreaIndex].Display();
    }
}

void Game::Quit()
{
    std::cout << "You have chosen to quit.\n";
    std::cout << "Thanks for playing!\n";
    play = false;
}
