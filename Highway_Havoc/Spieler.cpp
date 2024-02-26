#include "Spieler.hpp"

Spieler::Spieler(sf::RenderWindow* window, const char extLevel) : Auto(window, extLevel),
tot(0)
{

}


Spieler::~Spieler()
{

}

bool Spieler::getTot() const { return tot; }

void Spieler::stirb() { tot = 1; }


void Spieler::aktualisieren()  // Bringt die Werte der Variablen auf den "aktuellen" Stand
{
	this->eingabeverwaltung->aktualisieren();
	float breite = this->derWicht.getGlobalBounds().width / 4;
	derWicht.setRotation(0.f);

	if (position.x >= 28 * 6.4 + breite && this->eingabeverwaltung->getTastenStatusIndex(1) == true) 
	{
		position.x -= geschwindigkeit.x;
		derWicht.setRotation(-7.5f);
	}
	if (position.x <= 640 - (28 * 6.4) - breite && this->eingabeverwaltung->getTastenStatusIndex(0) == true) 
	{
		position.x += geschwindigkeit.x;
		derWicht.setRotation(7.5f);
	}

	//geschwindigkeit += beschleunigung; // Die Geschwindigkeit wird um Beschleunigung erhöht
	//position -= geschwindigkeit;       // Die Position minus die Geschwindigkeit ergibt die neue Position, da (0|0) oben links ist => somit Position kleiner Auto kommt näher an oberen Bildrand

	derWicht.setPosition(position);    // Bild/Sprite an die neue Position setzen
	// geschwindigkeit.x = 0.f;
}

void Spieler::anzeigen() // Zeichnet das Auto...
{
	window->draw(derWicht);
}

void Spieler::setTot(const char extTot) { tot = extTot; }