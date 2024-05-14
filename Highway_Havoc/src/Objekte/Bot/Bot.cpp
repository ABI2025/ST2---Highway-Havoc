#pragma once
#include "Bot.hpp"
Bot::Bot()
{
}
Bot::Bot(sf::RenderWindow* window, sf::Texture* textur)
{
	this->window = window;
	this->textur = *textur;
	this->sprite.setTexture(this->textur);
	sprite.setOrigin(sprite.getGlobalBounds().getSize().x / 2, sprite.getGlobalBounds().getSize().y / 2);
	float faktor = 57.2f / this->sprite.getGlobalBounds().getSize().x;
	sprite.setScale(faktor, faktor);
	this->sprite.setPosition(this->window->getSize().x / 2, 0 - this->sprite.getGlobalBounds().height / 2);
}
void Bot::aktualisieren()
{
	this->bewegenUm(sf::Vector2f(0.f, -1.f));
}

void Bot::anzeigen()
{
	this->window->draw(this->sprite);
}