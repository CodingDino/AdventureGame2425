#include "Monster.h"
#include <iostream>

Monster::Monster()
	:LookTarget("Monster", "Description")
{
}

Monster::Monster(std::string newName, std::string newDescription)
	:LookTarget(newName, newDescription)
{
}

Monster::Monster(const Monster& other)
	:LookTarget(other)
{
}

Monster::~Monster()
{
}

void Monster::Display()
{
	std::cout << name << ": " << description << "\n";
}
