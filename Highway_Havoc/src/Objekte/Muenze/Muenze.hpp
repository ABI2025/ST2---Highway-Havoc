#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Muenze {
private:
	sf::RenderWindow* window;
	sf::Texture muenzeTextur;
	sf::Sprite muenzeSprite;
public:
	~Muenze();
	Muenze(sf::RenderWindow* window);
	void aktualisieren();
	void anzeigen();
	sf::Vector2f getPos();
	void setPos(sf::Vector2f position);
	sf::FloatRect getGlobalBounds();
	bool kollidiert(sf::FloatRect viereck);
	sf::Sprite* getSprite();
};