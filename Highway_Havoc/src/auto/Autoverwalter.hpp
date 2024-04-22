#pragma once
#include "SFML/Graphics.hpp"
#include "Bot/Bot.hpp"
#include "Bot1/Bot1.hpp"
#include "Bot2/Bot2.hpp"
#include "Spieler/Spieler.hpp"
#include "Spieler1/Spieler1.hpp"
#include "Spieler2/Spieler2.hpp"
#include "../Map/Map.hpp"
#include "../utils/Collision.hpp"
class Autoverwalter {
private:
	sf::RenderWindow* window;
	EingabeVerwaltung* eingabeverwaltung;
	std::vector<Bot*> botVector;
	std::vector<Spieler*>  spielerVector;
	Map* map;

	bool istTot = false;
public:
	~Autoverwalter();
	Autoverwalter();
	Autoverwalter(sf::RenderWindow* window, Map* map, EingabeVerwaltung* eingabeverwaltung);
	void botHinzufuegen(Bot* bot);
	void botGenerieren(unsigned short anzahl, int typ);
	void botLevelGenerieren(unsigned short anzahl, unsigned short reihen, int typ);
	void botsAktualisieren();
	void botsAnzeigen();
	void spielerHinzufuegen(Spieler* spieler);
	void spielerGenerieren(unsigned short anzahl);
	void spielerAktualisieren();
	void spielerAnzeigen();
	void viewAufGesteuertenSpieler(unsigned short spielerIndex);
	bool getIstTot();
}; 