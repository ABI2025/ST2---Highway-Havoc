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

void Einstellungen::setTickrate(unsigned short framerate) { this->tickrate = tickrate; }

void Einstellungen::setBewegung_links(sf::Keyboard::Key bewegung_links) { this->bewegung_links = bewegung_links; }

void Einstellungen::setBewegung_rechts(sf::Keyboard::Key bewegung_rechts) { this->bewegung_rechts = bewegung_rechts; }

void Einstellungen::setAction(sf::Keyboard::Key action) { this->action = action; }


unsigned short Einstellungen::getLautstaerke() const { return lautstaerke; }

unsigned short Einstellungen::getFramerate() const { return framerate; }

unsigned short Einstellungen::getTickrate() const { return tickrate; }

sf::Keyboard::Key Einstellungen::getBewegung_links() const { return bewegung_links; }

sf::Keyboard::Key Einstellungen::getBewegung_rechts() const { return bewegung_rechts; }

sf::Keyboard::Key Einstellungen::getAction() const { return action; }
