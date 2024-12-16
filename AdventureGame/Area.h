#pragma once
#include <string>
#include <vector>
#include "LookTarget.h"
#include "Feature.h"
#include "Item.h"
#include "Monster.h"

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
	void DisplayContents();

	// Accessors
	void AddExit(Area* newExit);
	Area* GetExit(int index);
	int GetNumExits();
	void SetFeature(Feature* newFeature);
	Feature* GetFeature();
	void SetItem(Item* newItem);
	Item* GetItem();
	void SetMonster(Monster* newMonster);
	Monster* GetMonster();

private:

	// Data Members
	std::vector<Area*> exits;
	Feature* feature;
	Item* item;
	Monster* monster;
};

