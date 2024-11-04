#include "Player.h"
#include <iostream>

void Player::Display()
{
    std::cout << "You are " << name << ", " << description << "\n";
    std::cout << "You have " << stamina << " stamina.\n";
}
