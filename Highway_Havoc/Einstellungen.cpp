#include "Einstellungen.hpp"

Einstellungen::~Einstellungen() {}
Einstellungen::Einstellungen()
{
	lautstaerke = 100;
	framerate = 30;
	tickrate = 30;

	bewegung_links = sf::Keyboard::Key::Left;
	bewegung_rechts = sf::Keyboard::Key::Right;
	action = sf::Keyboard::Key::Space;
}

void Einstellungen::setLautstaerke(unsigned short lautstaerke) { this->lautstaerke = lautstaerke; }

void Einstellungen::setFramerate(unsigned short framerate) { this->framerate = framerate; }


