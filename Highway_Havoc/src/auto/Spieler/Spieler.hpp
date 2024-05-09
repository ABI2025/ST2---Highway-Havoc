#pragma once
#include "SFML/Graphics.hpp"
#include "../Automobil.hpp"
#include "../../EingabeVerwaltung/EingabeVerwaltung.hpp"
struct Eigenschaften {
	float maxGeschwindigkeit = 3;
	float reibung = 0.01;
	float beschlaeunigung = 0.05;
	Eigenschaften operator *(float multiplikator) {
		float maxGeschwindigkeitTmp = this->maxGeschwindigkeit * multiplikator;
		float reibungTmp = this->reibung * multiplikator;
		float beschlaeunigungTmp = this->beschlaeunigung * multiplikator;
		return Eigenschaften{maxGeschwindigkeitTmp, reibungTmp, beschlaeunigungTmp};
	}
};
class Spieler : public Automobil {
private:
	sf::RenderWindow* window;
	float geschwindigkeit;
	float rotation;

	sf::Texture tachoTextur;
	sf::Sprite tachoSprite;

	sf::Texture tachoZeigerTextur;
	sf::Sprite tachoZeigerSprite;

	Eigenschaften eigenschaften;
	
	EingabeVerwaltung* eingabeverwaltung;
public:
	~Spieler();
	Spieler();
	Spieler(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, sf::Texture* textur, Eigenschaften eigenschaften);
	void aktualisieren();
	void anzeigen();
};