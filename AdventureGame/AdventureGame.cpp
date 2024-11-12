
#include "Game.h"



int main()
{
	Game* game = new Game();
	game->Initialise();
	game->Run();
	delete game;
	game = nullptr;
}


