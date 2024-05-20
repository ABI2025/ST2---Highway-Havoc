#pragma once
#include "Bananenschale.hpp"

Bananenschale::~Bananenschale()
{
}

Bananenschale::Bananenschale(sf::RenderWindow* window)
{
	this->window = window;
	if (!this->bananenschaleTextur.loadFromFile("./res/grafiken/bananenschale.png")) {
		std::cout << "Fehler beim Laden der Datei! (./res/grafiken/bananenschale.png)" << std::endl;
	}
	this->bananenschaleSprite.setTexture(this->bananenschaleTextur);
	this->bananenschaleSprite.setOrigin(this->bananenschaleSprite.getGlobalBounds().getSize().x / 2, this->bananenschaleSprite.getGlobalBounds().getSize().y / 2);
	float faktor = 50 / this->bananenschaleSprite.getGlobalBounds().getSize().x;
	this->bananenschaleSprite.setScale(faktor, faktor);
	this->bananenschaleSprite.setRotation(rand()%360);
}

void Bananenschale::aktualisieren()
{
}

void Bananenschale::anzeigen()
{
	this->window->draw(this->bananenschaleSprite);
}

sf::Vector2f Bananenschale::getPos()
{
	return this->bananenschaleSprite.getPosition();
}

void Bananenschale::setPos(sf::Vector2f position)
{
	this->bananenschaleSprite.setPosition(position);
}

sf::FloatRect Bananenschale::getGlobalBounds()
{
	return this->bananenschaleSprite.getGlobalBounds();
}
bool Bananenschale::kollidiert(sf::FloatRect viereck)
{
	return this->bananenschaleSprite.getGlobalBounds().intersects(viereck);
}

sf::Sprite* Bananenschale::getSprite()
{
	return &this->bananenschaleSprite;
}
