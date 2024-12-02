#pragma once
#include "LookTarget.h"
class Item :
    public LookTarget
{
public:

    // Constructors
    Item();
    Item(std::string newName, std::string newDescription);
    Item(const Item& other);
    ~Item();

    // Methods
    void Display();

private:

    // Data Members
};

