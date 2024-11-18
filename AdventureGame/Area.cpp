#include "Area.h"
#include <iostream>

Area::Area()
    : name("Area")
    , description("Area description")
    , exits()
{
    // TEMP: DEBUG
    //std::cout << "Area default constructor called.\n";
}

Area::Area(std::string newName, std::string newDescription)
    : name(newName)
    , description(newDescription)
    , exits()
{
    // TEMP: DEBUG
    //std::cout << "Area parameterized constructor called.\n";
}

Area::Area(const Area& other)
    : name(other.name)
    , description(other.description)
    , exits(other.exits)
{
    // TEMP: DEBUG
    //std::cout << "Area copy constructor called.\n";
}

Area::~Area()
{
    // TEMP: DEBUG
    std::cout << "Area destructor called.\n";
}

void Area::Display()
{
    std::cout << "You find yourself in the " << name << "\n";
    std::cout << description << "\n";
    DisplayExits();
}

void Area::DisplayExits()
{
    if (exits.empty())
    {
        std::cout << "There are no exits from this area.\n";
    }
    else
    {
        std::cout << "Exits from this area are:\n";
        for (int i = 0; i < exits.size(); ++i)
        {
            int displayI = i + 1;
            std::cout << "\t" << displayI << ".\t" << exits[i]->name << "\n";
        }
    }

}

void Area::AddExit(Area* newExit)
{
    exits.push_back(newExit);
}

Area* Area::GetExit(int index)
{
    if (index >= 0 && index < exits.size())
    {
        return exits[index];
    }
    else
    {
        std::cout << "ERROR: Exit index out of range: index = " << index << ", exit size = "<< exits.size() << "\n";
        return nullptr;
    }
}

int Area::GetNumExits()
{
    return exits.size();
}
