#pragma once
#include <string>

class Player
{
public:

    // Constructors
    Player();
    Player(std::string newDescription);
    Player(const Player& other);

    // Methods
    void Display();

    // Data Members
    std::string name;
    std::string description;
    int stamina;
};

