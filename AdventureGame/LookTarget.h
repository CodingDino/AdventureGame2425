#pragma once
#include <string>

class LookTarget
{
public:

	// Constructors
	LookTarget();
	LookTarget(std::string newName, std::string newDescription);
	LookTarget(const LookTarget& other);
	~LookTarget();

	// Accessors
	std::string GetName();

protected:

	// Data Members
	std::string name;
	std::string description;
};

