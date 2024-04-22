#pragma once
#include "../Automobil.hpp"
class Bot : public Automobil {
public:
	virtual ~Bot();
	Bot();
	Bot(sf::RenderWindow* window);
	virtual void aktualisieren() = 0;
};