#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Automobil {
protected:
	sf::RenderWindow* window;
	sf::Texture textur;
	sf::Sprite sprite;
public:
	virtual ~Automobil();
	Automobil();
	Automobil(sf::RenderWindow* window);
	void setPos(sf::Vector2f position);
	sf::Vector2f getPos();
	sf::FloatRect getGlobalBounds();
	sf::Sprite* getSprite();
	void bewegenUm(sf::Vector2f bewegung);
	bool kollidiert(sf::FloatRect viereck);
	void aktualisieren();
	void anzeigen();
};