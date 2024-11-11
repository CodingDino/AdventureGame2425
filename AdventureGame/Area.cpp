#include "Area.h"
#include <iostream>

Area::Area()
    : name("Area")
    , description("Area description")
{
    // TEMP: DEBUG
    //std::cout << "Area default constructor called.\n";
}

Area::Area(std::string newName, std::string newDescription)
    : name(newName)
    , description(newDescription)
{
    // TEMP: DEBUG
    //std::cout << "Area parameterized constructor called.\n";
}

Area::Area(const Area& other)
    : name(other.name)
    , description(other.description)
{
    // TEMP: DEBUG
    //std::cout << "Area copy constructor called.\n";
}

void Area::Display()
{
    std::cout << "You find yourself in the " << name << "\n";
    std::cout << description << "\n";
}
