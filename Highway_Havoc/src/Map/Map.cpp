#include "Map.hpp"
#include <iostream>
Map::~Map()
{
}

Map::Map(sf::RenderWindow* window)
{
	this->window = window;
	if (!this->strassenTextur.loadFromFile("./res/grafiken/strasse_vip.png"))
	{
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/strasse_vip.png)" << std::endl;
	}
	if (!this->brueckeTextur.loadFromFile("./res/grafiken/bruecke.png"))
	{
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/bruecke.png)" << std::endl;
	}

	this->strasse.setTexture(this->strassenTextur);
	streckungsFaktor = (this->window->getView().getSize().x / this->strasse.getLocalBounds().width);
	this->strasse.setScale(streckungsFaktor, streckungsFaktor);
	this->strasse.setOrigin(this->strasse.getLocalBounds().width / 2, 0.f);
	this->strasse.setPosition({ (float)this->window->getView().getSize().x / 2,   (-(this->strasse.getLocalBounds().height) * streckungsFaktor) + ((float)this->window->getView().getSize().y) });

	this->bruecke.setTexture(this->brueckeTextur);
	this->bruecke.setScale(streckungsFaktor, streckungsFaktor);
	this->bruecke.setOrigin(this->bruecke.getLocalBounds().width / 2, 0.f);
	this->bruecke.setPosition({ (float)this->window->getView().getSize().x / 2,   (-(this->strasse.getLocalBounds().height) * streckungsFaktor) + ((float)this->window->getView().getSize().y) + ((-(this->bruecke.getLocalBounds().height) * streckungsFaktor))});

}

void Map::zeichnen()
{
	this->window->draw(this->strasse);
}

void Map::aktualisieren()
{
	//if (this->strasse.getPosition().y < this->window->getView().getSize().y) {
	//	this->strasse.move(0.f, 1.f * geschwindigkeit);
	//}
	//else {
	//	this->strasse.setPosition({ (float)this->window->getView().getSize().x / 2, -(this->strasse.getLocalBounds().height) * streckungsFaktor });
	//}
}

sf::FloatRect Map::getMapViereck()
{
	return this->strasse.getGlobalBounds();
}

void Map::brueckeZeichnen()
{
	this->window->draw(this->bruecke);
}
