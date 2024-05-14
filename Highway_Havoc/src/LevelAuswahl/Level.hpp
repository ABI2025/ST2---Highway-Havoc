//#pragma once
//static class Level {
//public:
//	virtual ~Level() {
//	}
//	virtual void aktualisieren() = 0;
//	virtual void anzeigen() = 0;
//	virtual bool getUnterbrechung() = 0;
//	virtual int getUnterbrechungsgrund() = 0;
//	virtual int muenzenGesammelt();
//};
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
class Level {
private:
	sf::RenderWindow* window;
	Map* map;
	EingabeVerwaltung* eingabeverwaltung;
	Objektverwalter* objektverwalter;
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
	~Level();
	Level(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, unsigned short anzahlBots, unsigned short botReihen, unsigned short botTyp, unsigned short anzahlSpieler, unsigned short spielerTyp, unsigned short anzahlMuenzen, unsigned short muenzReihen);
	void aktualisieren();
	void anzeigen();
	bool getUnterbrechung();
	int getUnterbrechungsgrund();
	int muenzenGesammelt();
};