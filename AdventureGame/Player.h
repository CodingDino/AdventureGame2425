#pragma once
#include <string>

class Player
{
public:

    // Constructors
    Player();
    Player(std::string newDescription);
    Player(const Player& other);
    ~Player();

    // Methods
    void Display();
    void SetName(std::string newName);
    int GetStamina();
    void UseStamina(int toUse);

private:

    // Data Members
    std::string name;
    std::string description;
    int stamina;
};

