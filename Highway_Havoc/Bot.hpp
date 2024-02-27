#pragma once
#include "Auto.hpp"

class Bot : public Auto
{
private: 
	char fahrbahn;     // Angabe der aktuellen Fahrbahn des Bots ( l -> links, m -> Mitte, r -> rechts)
public:
	Bot(sf::RenderWindow* window, const char extLevel);
	~Bot();

	void anzeigen();
	void aktualisieren();

	char getFahrbahn();
};

