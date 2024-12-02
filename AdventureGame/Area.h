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
	void DisplayFeatures();
	void DisplayItems();
	void DisplayMonster();

	// Accessors
	void AddExit(Area* newExit);
	Area* GetExit(int index);
	int GetNumExits();
	void AddFeature(Feature* newFeature);
	Feature* GetFeature(int index);
	int GetNumFeatures();
	void AddItem(Item* newItem);
	Item* GetItem(int index);
	int GetNumItems();
	void SetMonster(Monster* newMonster);
	Monster* GetMonster();

private:

	// Data Members
	std::vector<Area*> exits;
	std::vector<Feature*> features;
	std::vector<Item*> items;
	Monster* monster;
};

