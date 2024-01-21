#include "Map.hpp"
#include <iostream>
Map::~Map()
{
}

Map::Map(sf::RenderWindow* window)
{
	this->window = window;
	if (!this->stassenTextur.loadFromFile("strasse.png"))
	{
		std::cout << "Fehler beim laden der Textur! (strasse.png)" << std::endl;
	}
	this->strasse.setTexture(this->stassenTextur);
	this->strasse.setScale(2.f, 1.f);
	this->strasse.setOrigin(this->strasse.getLocalBounds().width / 2, 0.f);
	this->strasse.setPosition({ (float)this->window->getView().getSize().x / 2,0.f });

	this->strasse2.setTexture(this->stassenTextur);
	this->strasse2.setScale(2.f, 1.f);
	this->strasse2.setOrigin(this->strasse2.getLocalBounds().width / 2, 0.f);
	this->strasse2.setPosition({ (float)this->window->getView().getSize().x / 2, -(this->strasse2.getLocalBounds().height) });
}

void Map::zeichnen()
{
	this->window->draw(this->strasse);
	this->window->draw(this->strasse2);
}

void Map::aktualisieren()
{
	if (this->strasse.getPosition().y < this->window->getView().getSize().y) {
		this->strasse.move(0.f, 1.f);
	}
	else {
		this->strasse.setPosition({ (float)this->window->getView().getSize().x / 2, -(this->strasse.getLocalBounds().height) });
	}

	if (this->strasse2.getPosition().y < this->window->getView().getSize().y) {
		this->strasse2.move(0.f, 1.f);
	}
	else {
		this->strasse2.setPosition({ (float)this->window->getView().getSize().x / 2, -(this->strasse2.getLocalBounds().height) });
	}
}