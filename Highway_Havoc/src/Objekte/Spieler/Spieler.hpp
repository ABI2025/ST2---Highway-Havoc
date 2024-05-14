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
		return Eigenschaften{ maxGeschwindigkeitTmp, reibungTmp, beschlaeunigungTmp };
	}
};
class Spieler : public Automobil {
private:
	sf::RenderWindow* window;
	float geschwindigkeit;
	float rotation;

	unsigned short leben = 3;
	bool unverwundbar = false;
	unsigned long long unverwundbarNoch = 0;		//in Ticks
	unsigned long long unverwundbarZeit = 60 * 3;	//in Ticks

	int geld = 0;

	sf::Texture tachoTextur;
	sf::Sprite tachoSprite;

	sf::Texture tachoZeigerTextur;
	sf::Sprite tachoZeigerSprite;

	sf::Texture lebensTexturen[4];
	sf::Sprite lebensSprites[4];

	Eigenschaften eigenschaften;

	EingabeVerwaltung* eingabeverwaltung;

	sf::Font PixeboyFont;
	sf::Texture muenzeTextur;
	sf::Sprite muenzeSprite;
	sf::Text geldText;
public:
	~Spieler();
	Spieler();
	Spieler(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, sf::Texture* textur, Eigenschaften eigenschaften);
	void aktualisieren();
	void anzeigen();
	void statusAnzeigen();
	void setLeben(unsigned short leben);
	void setUnverwundbar(bool unverwundbar);
	unsigned short getLeben();
	bool getUnverwundbar();
	void schadenNehmen(unsigned short schaden);
	void setGeld(int geld);
	int getGeld();
	void hatMuenzeGesammelt();
};