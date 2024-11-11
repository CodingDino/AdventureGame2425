#include "Player.h"
#include <iostream>

Player::Player()
    : name("Steve")
    , description("A brave warrior.")
    , stamina(10)
{
    // TEMP: DEBUG
    //std::cout << "Player default constructor called.\n";
}

Player::Player(std::string newDescription)
    : name("Steve")
    , description(newDescription)
    , stamina(10)
{
    // TEMP: DEBUG
    //std::cout << "Player parameterized constructor called.\n";
}

Player::Player(const Player& other)
    : name(other.name)
    , description(other.description)
    , stamina(other.stamina)
{
    // TEMP: DEBUG
    //std::cout << "Player copy constructor called.\n";
}

void Player::Display()
{
    std::cout << "You are " << name << ", " << description << "\n";
    std::cout << "You have " << stamina << " stamina.\n";
}
