#pragma once
#include "Player.h"
#include "Area.h"
#include <vector>

class Game
{
public:

	// Constructors
	Game();
	Game(const Game& other);
	~Game();

	// Methods
	void Initialise();
	void Run();
	int DisplayAndReadPlayerAction();
	void Look();
	void Move();
	void Quit();

	// Data Members
	Player* player;
	std::vector<Area> areas;
	int currentAreaIndex;
	bool play;
};

