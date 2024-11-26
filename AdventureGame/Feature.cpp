#include "Feature.h"

#include <iostream>

Feature::Feature()
	:LookTarget("Feature", "Description")
{
}

Feature::Feature(std::string newName, std::string newDescription)
	:LookTarget(newName, newDescription)
{
}

Feature::Feature(const Feature& other)
	:LookTarget(other)
{
}

Feature::~Feature()
{
}

void Feature::Display()
{
	std::cout << name << ": " << description << "\n";
}
