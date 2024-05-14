#pragma once
#include "Muenze.hpp"

Muenze::~Muenze()
{
}

Muenze::Muenze(sf::RenderWindow* window)
{
	this->window = window;
	if (!this->muenzeTextur.loadFromFile("./res/grafiken/muenze.png")) {
		std::cout << "Fehler beim Laden der Datei! (./res/grafiken/muenze.png)" << std::endl;
	}
	this->muenzeSprite.setTexture(this->muenzeTextur);
	this->muenzeSprite.setOrigin(this->muenzeSprite.getGlobalBounds().getSize().x / 2, this->muenzeSprite.getGlobalBounds().getSize().y / 2);
	this->muenzeSprite.setScale(2.2f, 2.2f);
}

void Muenze::aktualisieren()
{
}

void Muenze::anzeigen()
{
	this->window->draw(this->muenzeSprite);
}

sf::Vector2f Muenze::getPos()
{
	return this->muenzeSprite.getPosition();
}

void Muenze::setPos(sf::Vector2f position)
{
	this->muenzeSprite.setPosition(position);
}

sf::FloatRect Muenze::getGlobalBounds()
{
	return this->muenzeSprite.getGlobalBounds();
}
bool Muenze::kollidiert(sf::FloatRect viereck)
{
	return this->muenzeSprite.getGlobalBounds().intersects(viereck);
}

sf::Sprite* Muenze::getSprite()
{
	return &this->muenzeSprite;
}
