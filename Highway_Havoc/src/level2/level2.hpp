#pragma once
#include "SFML/Graphics.hpp"
#include "../Map/Map.hpp"
#include "../EingabeVerwaltung/EingabeVerwaltung.hpp"
#include "../PauseMenue/PauseMenue.hpp"
#include "../auto/Automobil.hpp"
#include "../auto/Autoverwalter.hpp"
#include "../auto/Bot/Bot.hpp"
#include "../LevelAuswahl/Level.hpp"
class Level2 : public Level{
private:
	sf::RenderWindow* window;
	Map* map;
	EingabeVerwaltung* eingabeverwaltung;
	Autoverwalter* autoverwalter;
	unsigned int botGenerierungsIntervall = 240;
	unsigned int botGenerierungsIntervallZaehler = 0;

	struct Zustaende {
		bool pauseMenueAnzeigen = false;
		bool pauseMenueAktualisieren = false;
		bool mapAnzeigen = false;
		bool mapAktualisieren = false;
	}zustaende;

	bool unterbrechung = false;
	int unterbrechungsgrund = NULL;
public:
	~Level2();
	Level2(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung);
	void aktualisieren();
	void anzeigen();
	bool getUnterbrechung();
	int getUnterbrechungsgrund();
};