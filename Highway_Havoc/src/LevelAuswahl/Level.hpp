#pragma once
#include "SFML/Graphics.hpp"
#include "../Map/Map.hpp"
#include "../EingabeVerwaltung/EingabeVerwaltung.hpp"
#include "../PauseMenue/PauseMenue.hpp"
#include "../Objekte/Automobil.hpp"
#include "../Objekte/Objektverwalter.hpp"
#include "../Objekte/Bot/Bot.hpp"
#include "../Objekte/Spieler/Spieler.hpp"
#include "../LevelAuswahl/Level.hpp"
#include "../MusikVerwaltung/MusikVerwaltung.hpp"
class Level {
private:
	sf::RenderWindow* window;
	Map* map;
	EingabeVerwaltung* eingabeverwaltung;
	MusikVerwaltung* musikverwaltung;
	Objektverwalter* objektverwalter;
	unsigned int botGenerierungsIntervall = 240;
	unsigned int botGenerierungsIntervallZaehler = 0;
	unsigned short botTyp = 0;
	unsigned short botAnzahl = 0;


	struct Zustaende {
		bool pauseMenueAnzeigen = false;
		bool pauseMenueAktualisieren = false;
		bool mapAnzeigen = false;
		bool mapAktualisieren = false;
	}zustaende;

	bool unterbrechung = false;
	int unterbrechungsgrund = NULL;
public:
	~Level();
	Level(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, MusikVerwaltung* musikverwaltung, unsigned short anzahlBots, unsigned short botReihen, unsigned short botTyp, unsigned short anzahlSpieler, unsigned short spielerTyp, unsigned short anzahlMuenzen, unsigned short muenzReihen, unsigned short anzahlBananenschalen, unsigned short bananenschalenReihen, unsigned short mapTyp);
	void aktualisieren();
	void anzeigen();
	bool getUnterbrechung();
	int getUnterbrechungsgrund();
	int muenzenGesammelt();
};