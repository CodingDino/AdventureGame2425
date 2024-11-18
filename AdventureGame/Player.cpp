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

Player::~Player()
{
    // TEMP: DEBUG
    std::cout << "Player destructor called.\n";
}

void Player::Display()
{
    std::cout << "You are " << name << ", " << description << "\n";
    std::cout << "You have " << stamina << " stamina.\n";
}

void Player::SetName(std::string newName)
{
    name = newName;
}

int Player::GetStamina()
{
    return 0;
}

void Player::UseStamina(int toUse)
{
    stamina -= toUse;
    if (stamina <= 0)
    {
        std::cout << "You have run out of stamina!\n";
        stamina = 0;
    }
}
