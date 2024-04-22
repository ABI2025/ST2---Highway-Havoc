#pragma once
#include "../Automobil.hpp"
#include "../Bot/Bot.hpp"
class Bot2 : public Bot {
public:
	Bot2();
	Bot2(sf::RenderWindow* window);
	void aktualisieren();
};