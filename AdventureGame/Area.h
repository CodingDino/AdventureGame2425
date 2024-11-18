#pragma once
#include <string>
#include <vector>

class Area
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
	std::string name;
	std::string description;
	std::vector<Area*> exits;
};

