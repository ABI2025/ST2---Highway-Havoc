#include "Bot.hpp"

Bot::Bot(sf::RenderWindow* window, const char extLevel) : Auto(window, extLevel)
{ }

Bot::~Bot() { }


void Bot::aktualisieren()
{
	this->eingabeverwaltung->aktualisieren();
	float breite = this->derWicht.getGlobalBounds().width / 4;

	if (position.x >= 28 * 6.4 + breite && this->eingabeverwaltung->getTastenStatusIndex(1) == true) {
		position.x -= geschwindigkeit.x;
	}
	if (position.x <= 640 - (28 * 6.4) - breite && this->eingabeverwaltung->getTastenStatusIndex(0) == true) {
		position.x += geschwindigkeit.x;
	}

	//geschwindigkeit += beschleunigung; // Die Geschwindigkeit wird um Beschleunigung erhöht
	//position -= geschwindigkeit;       // Die Position minus die Geschwindigkeit ergibt die neue Position, da (0|0) oben links ist => somit Position kleiner Auto kommt näher an oberen Bildrand

	derWicht.setPosition(position);    // Bild/Sprite an die neue Position setzen
	// geschwindigkeit.x = 0.f;
}
void Bot::anzeigen()
{
	window->draw(derWicht);
}