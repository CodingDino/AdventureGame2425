#pragma once
#include <string>
#include "LookTarget.h"

class Player : public LookTarget
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
    int stamina;
};

