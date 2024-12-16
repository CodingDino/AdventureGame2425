#include "Area.h"
#include <iostream>

Area::Area()
    : LookTarget("Area", "Area description")
    , exits()
    , feature(nullptr)
    , item(nullptr)
    , monster(nullptr)
{
    // TEMP: DEBUG
    //std::cout << "Area default constructor called.\n";
}

Area::Area(std::string newName, std::string newDescription)
    : LookTarget(newName, newDescription)
    , exits()
    , feature(nullptr)
    , item(nullptr)
    , monster(nullptr)
{
    // TEMP: DEBUG
    //std::cout << "Area parameterized constructor called.\n";
}

Area::Area(const Area& other)
    : LookTarget(other)
    , exits(other.exits)
    , feature(other.feature)
    , item(other.item)
    , monster(other.monster)
{
    // TEMP: DEBUG
    //std::cout << "Area copy constructor called.\n";
}

Area::~Area()
{
    // TEMP: DEBUG
    std::cout << "Area destructor called.\n";

    // Delete all features!
    if (feature != nullptr)
    {
        delete feature;
        feature = nullptr;
    }

    // Delete all items!
    if (item != nullptr)
    {
        delete item;
        item = nullptr;
    }

    // Delete monster
    if (monster != nullptr)
    {
        delete monster;
        monster = nullptr;
    }
}

void Area::Display()
{
    std::cout << "You find yourself in the " << name << "\n";
    std::cout << description << "\n";
    DisplayContents();
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

void Area::DisplayContents()
{
    if (feature)
    {
        std::cout << "Area contains: ";
        std::cout << feature->GetName();
        std::cout << "\n";
    }
    else if (item)
    {
        std::cout << "Area contains: ";
        std::cout << item->GetName();
        std::cout << "\n";
    }
    else if (monster)
    {
        std::cout << "Area contains: ";
        std::cout << monster->GetName();
        std::cout << "\n";
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

void Area::SetFeature(Feature* newFeature)
{
    if (feature != nullptr)
    {
        delete feature;
        feature = nullptr;
    }
    feature = newFeature;
}

Feature* Area::GetFeature()
{
    return feature;
}

void Area::SetItem(Item* newItem)
{
    if (item != nullptr)
    {
        delete item;
        item = nullptr;
    }
    item = newItem;
}

Item* Area::GetItem()
{
    return item;
}

void Area::SetMonster(Monster* newMonster)
{
    if (monster != nullptr)
    {
        delete monster;
        monster = nullptr;
    }
    monster = newMonster;
}

Monster* Area::GetMonster()
{
    return monster;
}
