#pragma once
#include "SFML/Graphics.hpp"
#include "../EingabeVerwaltung/EingabeVerwaltung.hpp"
#include "../PauseMenue/PauseMenue.hpp"
#include "../Fortschritt/Fortschritt.hpp"
#include "../Nachricht/Nachricht.hpp"
#include "Level.hpp"
#include <iostream>

class LevelAuswahl {
	sf::RenderWindow* window;
	EingabeVerwaltung* eingabeverwaltung;
	PauseMenue* pauseMenue;
	Fortschritt* fortschritt;
	Nachricht* verlorenBildschirm;
	Nachricht* gewonnenBildschirm;
	unsigned short auswahlX = 0;
	unsigned short auswahlY = 1;
	bool auswahlGetroffen = false;
	Level* level;
	std::vector<sf::RectangleShape> levelBoxVector;
	std::vector<sf::Sprite> levelSpriteVector;
	std::vector<sf::Texture> levelTextureVector;

	std::vector<sf::RectangleShape> autoBoxVector;
	std::vector<sf::Sprite> autoSpriteVector;
	std::vector<sf::Texture> autoTexturVector;
	std::vector<int> autoPreisVector;
	int autoWahl = 0;

	struct Zustaende {
		bool pauseMenueAnzeigen = false;
		bool pauseMenueAktualisieren = false;
		bool levelAuswahlAnzeigen = false;
		bool levelAuswahlAktualisieren = false;
		bool levelLaeuft = false;
		bool levelAnzeigen = false;
		bool levelAktualisieren = false;
		bool verlorenBildschirmAnzeigen = false;
		bool verlorenBildschirmAktualisieren = false;
		bool gewonnenBildschirmAnzeigen = false;
		bool gewonnenBildschirmAktualisieren = false;
	}zustaende;

	bool unterbrechung = false;
	int unterbrechungsgrund = NULL;

	sf::Font PixeboyFont;
	sf::Text titelText;
	sf::ConvexShape zurueckPfeil;
	sf::Texture levelSchlossTextur;
	sf::Sprite levelSchlossSprite;

	sf::Texture muenzeTextur;
	sf::Sprite muenzeSprite;
	sf::Text geldText;

	void levelHinzufuegen(int typ);
	Level* levelGenerieren(int index);
	void autoHinzufuegen(int typ, int preis);

public:
	~LevelAuswahl();
	LevelAuswahl(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, Fortschritt* fortschritt);
	void aktualisieren();
	void anzeigen();
	bool getAuswahlGetroffen();
	unsigned short getAuswahlX();
	unsigned short getAuswahlY();
	bool getUnterbrechung();
	int getUnterbrechungsgrund();
};