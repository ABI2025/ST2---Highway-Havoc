#pragma once
#include "SFML/Graphics.hpp"
#include "../EingabeVerwaltung/EingabeVerwaltung.hpp"
#include "../level1/level1.hpp"
#include "../level2/level2.hpp"
#include "../level3/level3.hpp"
#include "../PauseMenue/PauseMenue.hpp"
#include "../Fortschritt/Fortschritt.hpp"
#include "Level.hpp"
#include <iostream>

class LevelAuswahl {
	sf::RenderWindow* window;
	EingabeVerwaltung* eingabeverwaltung;
	PauseMenue* pauseMenue;
	Fortschritt* fortschritt;
	unsigned short auswahl = 1;
	bool auswahlGetroffen = false;
	std::vector<Level*> levelVector;
	std::vector<sf::RectangleShape> levelBoxVector;
	std::vector<sf::Sprite> levelSpriteVector;
	std::vector<sf::Texture> levelTextureVector;

	struct Zustaende {
		bool pauseMenueAnzeigen = false;
		bool pauseMenueAktualisieren = false;
		bool levelAuswahlAnzeigen = false;
		bool levelAuswahlAktualisieren = false;
		bool levelLaeuft = false;
		bool levelAnzeigen = false;
		bool levelAktualisieren = false;
	}zustaende;

	bool unterbrechung = false;
	int unterbrechungsgrund = NULL;

	sf::Font PixeboyFont;
	sf::Text titelText;
	sf::ConvexShape zurueckPfeil;
	sf::Texture levelSchlossTextur;
	sf::Sprite levelSchlossSprite;
	void levelHinzufuegen(Level* level);
	Level* levelGenerieren(int index);
public:
	~LevelAuswahl();
	LevelAuswahl(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, Fortschritt* fortschritt);
	void aktualisieren();
	void anzeigen();
	bool getAuswahlGetroffen();
	unsigned short getAuswahl();
	bool getUnterbrechung();
	int getUnterbrechungsgrund();
};
