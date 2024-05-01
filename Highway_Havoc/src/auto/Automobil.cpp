#pragma once
#include "Automobil.hpp"

Automobil::~Automobil()
{
}
Automobil::Automobil() {
}

Automobil::Automobil(sf::RenderWindow* window)
{
	this->window = window;

}

void Automobil::setPos(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

sf::Vector2f Automobil::getPos()
{
	return this->sprite.getPosition();
}

sf::FloatRect Automobil::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

sf::Sprite* Automobil::getSprite()
{
	return &this->sprite;
}

void Automobil::bewegenUm(sf::Vector2f bewegung)
{
	this->sprite.move(bewegung);
}

bool Automobil::kollidiert(sf::FloatRect viereck)
{
	return this->sprite.getGlobalBounds().intersects(viereck);
}

void Automobil::aktualisieren()
{
}

void Automobil::anzeigen()
{
	this->window->draw(this->sprite);
}