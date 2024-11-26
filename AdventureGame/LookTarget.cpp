#include "LookTarget.h"
#include <iostream>

LookTarget::LookTarget()
    : name("Name")
    , description("Description")
{
}

LookTarget::LookTarget(std::string newName, std::string newDescription)
    : name(newName)
    , description(newDescription)
{
}

LookTarget::LookTarget(const LookTarget& other)
    : name(other.name)
    , description(other.description)
{
}

LookTarget::~LookTarget()
{
}
