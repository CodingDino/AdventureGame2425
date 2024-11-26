#pragma once
#include <string>
#include <vector>
#include "LookTarget.h"

class Area : public LookTarget
{
public:

	// Constructors
	Area();
	Area(std::string newName, std::string newDescription);
	Area(const Area& other);
	~Area();

	// Methods
	void Display();
	void DisplayExits();

	// Accessors
	void AddExit(Area* newExit);
	Area* GetExit(int index);
	int GetNumExits();

private:

	// Data Members
	std::vector<Area*> exits;
};

