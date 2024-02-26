#pragma once
#include "Auto.hpp"

class Bot : Auto
{
private: 

public:
	Bot(sf::RenderWindow* window, const char extLevel);
	~Bot();

	void anzeigen();
	void aktualisieren();
};

