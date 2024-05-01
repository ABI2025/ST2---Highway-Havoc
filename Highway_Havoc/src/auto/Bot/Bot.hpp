#pragma once
#include "../Automobil.hpp"
class Bot : public Automobil {
public:
	Bot();
	Bot(sf::RenderWindow* window, sf::Texture* textur);
	void aktualisieren();
	void anzeigen();
};