#include "Bot.hpp"
#include <stdlib.h>

Bot::Bot(sf::RenderWindow* window, const char extLevel) : Auto(window, extLevel)
{ 
	setGeschwindigkeit({ 0.f, -1.f });
	setPosition({ 100.f / 2.f * 6.4f, -200.f });
}

Bot::~Bot() { }


void Bot::aktualisieren()
{
	float breite = this->derWicht.getGlobalBounds().width / 4;
	grenzenGrafik = derWicht.getGlobalBounds();
	
	if (getYPosition() > 360 + 200)     // Wenn das Auto 200 Pixel aus dem Bildschirm gefahren ist, wird es wieder nach oben gesetzt um erneut durchs Bild zu fahren
	{
		if ((rand() % 10) > 7) setPosition({ (640 / 2) + (15.f * 6.4), -100.f});
		else if ((rand() % 10) < 4) setPosition({ 640 / 2, -50.f });
		else setPosition({(640 / 2) - (15.f * 6.4), -150.f});
	}

	//geschwindigkeit += beschleunigung; // Die Geschwindigkeit wird um Beschleunigung erhöht
	position -= geschwindigkeit;       // Die Position minus die Geschwindigkeit ergibt die neue Position, da (0|0) oben links ist => somit Position kleiner Auto kommt näher an oberen Bildrand

	derWicht.setPosition(position);    // Bild/Sprite an die neue Position setzen
	// geschwindigkeit.x = 0.f;
}
void Bot::anzeigen()
{
	window->draw(derWicht);
}