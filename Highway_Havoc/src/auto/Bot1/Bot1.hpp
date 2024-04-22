#pragma once
#include "../Automobil.hpp"
#include "../Bot/Bot.hpp"
class Bot1 : public Bot {
public:
	Bot1();
	Bot1(sf::RenderWindow* window);
	void aktualisieren();
};