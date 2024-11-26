#pragma once
#include "LookTarget.h"

class Feature :
    public LookTarget
{
public:

    // Constructors
    Feature();
    Feature(std::string newName, std::string newDescription);
    Feature(const Feature& other);
    ~Feature();

    // Methods
    void Display();

private:

    // Data Members
};

