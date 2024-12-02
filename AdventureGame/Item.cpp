#include "Item.h"

#include <iostream>

Item::Item()
{
}

Item::Item(std::string newName, std::string newDescription)
	:LookTarget(newName, newDescription)
{
}

Item::Item(const Item& other)
	:LookTarget(other)
{
}

Item::~Item()
{
}

void Item::Display()
{
	std::cout << name << ": " << description << "\n";
}
