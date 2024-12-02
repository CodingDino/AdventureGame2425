#include "Area.h"
#include <iostream>

Area::Area()
    : LookTarget("Area", "Area description")
    , exits()
    , features()
    , items()
    , monster(nullptr)
{
    // TEMP: DEBUG
    //std::cout << "Area default constructor called.\n";
}

Area::Area(std::string newName, std::string newDescription)
    : LookTarget(newName, newDescription)
    , exits()
    , features()
    , items()
    , monster(nullptr)
{
    // TEMP: DEBUG
    //std::cout << "Area parameterized constructor called.\n";
}

Area::Area(const Area& other)
    : LookTarget(other)
    , exits(other.exits)
    , features(other.features)
    , items(other.items)
    , monster(nullptr)
{
    // TEMP: DEBUG
    //std::cout << "Area copy constructor called.\n";
}

Area::~Area()
{
    // TEMP: DEBUG
    std::cout << "Area destructor called.\n";

    // Delete all features!
    for (int i = 0; i < features.size(); ++i)
    {
        delete features[i];
        features[i] = nullptr;
    }
    features.clear();

    // Delete all items!
    for (int i = 0; i < items.size(); ++i)
    {
        delete items[i];
        items[i] = nullptr;
    }
    items.clear();

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
    DisplayFeatures();
    DisplayItems();
    DisplayMonster();
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

void Area::DisplayFeatures()
{
    if (!features.empty())
    {
        std::cout << "Area features: ";
        for (int i = 0; i < features.size(); ++i)
        {
            std::cout << features[i]->GetName() <<" ";
        }
        std::cout << "\n";
    }
}

void Area::DisplayItems()
{
    if (!items.empty())
    {
        std::cout << "Some items are here: ";
        for (int i = 0; i < items.size(); ++i)
        {
            std::cout << items[i]->GetName() << " ";
        }
        std::cout << "\n";
    }
}

void Area::DisplayMonster()
{
    if (monster != nullptr)
    {
        std::cout << "There is a monster here: ";
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

void Area::AddFeature(Feature* newFeature)
{
    features.push_back(newFeature);
}

Feature* Area::GetFeature(int index)
{
    return features[index];
}

int Area::GetNumFeatures()
{
    return features.size();
}

void Area::AddItem(Item* newItem)
{
    items.push_back(newItem);
}

Item* Area::GetItem(int index)
{
    return items[index];
}

int Area::GetNumItems()
{
    return items.size();
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
