#pragma once
#include "Bot2.hpp"
Bot2::Bot2() : Bot()
{

}
Bot2::Bot2(sf::RenderWindow* window) : Bot(window)
{
	this->window = window;
	if (!this->texture.loadFromFile("./res/grafiken/bot_lvl2.png")) {
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/auto.png)" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	sprite.setOrigin(sprite.getGlobalBounds().getSize().x / 2, sprite.getGlobalBounds().getSize().y / 2);
	sprite.setScale(2.7f, 2.7f);
	this->sprite.setPosition(this->window->getSize().x / 2, 0 - this->sprite.getGlobalBounds().height / 2);
}
void Bot2::aktualisieren()
{
	this->bewegenUm(sf::Vector2f(0.f, -1.f));
}
