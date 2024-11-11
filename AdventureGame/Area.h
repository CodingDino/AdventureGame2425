#pragma once
#include <string>

class Area
{
public:

	// Constructors
	Area();
	Area(std::string newName, std::string newDescription);
	Area(const Area& other);

	// Methods
	void Display();

	// Data Members
	std::string name;
	std::string description;
};

