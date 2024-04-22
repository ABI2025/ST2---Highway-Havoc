#pragma once
#include "Bot1.hpp"
Bot1::Bot1() : Bot()
{

}
Bot1::Bot1(sf::RenderWindow* window) : Bot(window)
{
	this->window = window;
	if (!this->texture.loadFromFile("./res/grafiken/auto.png")) {
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/auto.png)" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	sprite.setOrigin(sprite.getGlobalBounds().getSize().x / 2, sprite.getGlobalBounds().getSize().y / 2);
	sprite.setScale(2.2f, 2.2f);
	this->sprite.setPosition(this->window->getSize().x/2, 0 - this->sprite.getGlobalBounds().height / 2);
}
void Bot1::aktualisieren()
{
	this->bewegenUm(sf::Vector2f(0.f,-1.f));
}
