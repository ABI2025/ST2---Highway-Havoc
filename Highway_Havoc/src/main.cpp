#include "SFML/Graphics.hpp"
#include "Game.hpp"

int WinMain() {
	Game game(60, 60);
	game.start();
	return 0;
}