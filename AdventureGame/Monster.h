#pragma once
#include "LookTarget.h"
class Monster :
    public LookTarget
{
public:

    // Constructors
    Monster();
    Monster(std::string newName, std::string newDescription);
    Monster(const Monster& other);
    ~Monster();

    // Methods
    void Display();

private:

    // Data Members
};

