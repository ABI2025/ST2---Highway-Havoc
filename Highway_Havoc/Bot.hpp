#pragma once
#include "Auto.hpp"

class Bot : public Auto
{
private: 

public:
	Bot(sf::RenderWindow* window, const char extLevel);
	~Bot();

	void anzeigen();
	void aktualisieren();
};

