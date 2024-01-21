#pragma once
#include "SFML/Graphics.hpp"
class Map {
private:
	sf::RenderWindow* window;
	sf::Texture stassenTextur;
	sf::Sprite strasse;
	sf::Sprite strasse2;
public:
	~Map();
	Map(sf::RenderWindow* window);
	void zeichnen();
	void aktualisieren();
};