#include "Area.h"
#include <iostream>

Area::Area()
    : LookTarget("Area", "Area description")
    , exits()
    , features()
{
    // TEMP: DEBUG
    //std::cout << "Area default constructor called.\n";
}

Area::Area(std::string newName, std::string newDescription)
    : LookTarget(newName, newDescription)
    , exits()
    , features()
{
    // TEMP: DEBUG
    //std::cout << "Area parameterized constructor called.\n";
}

Area::Area(const Area& other)
    : LookTarget(other)
    , exits(other.exits)
    , features(other.features)
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
}

void Area::Display()
{
    std::cout << "You find yourself in the " << name << "\n";
    std::cout << description << "\n";
    DisplayFeatures();
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
