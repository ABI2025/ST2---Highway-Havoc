#pragma once
#include "SFML/Graphics.hpp"
#include "Bot/Bot.hpp"
#include "Spieler/Spieler.hpp"
#include "Muenze/Muenze.hpp"
#include "Bananenschale/Bananenschale.hpp"
#include "../Map/Map.hpp"
#include "../utils/Collision.hpp"
#include "../MusikVerwaltung/MusikVerwaltung.hpp"
class Objektverwalter {
private:
	sf::RenderWindow* window;
	EingabeVerwaltung* eingabeverwaltung;
	MusikVerwaltung* musikverwaltung;
	std::vector<Bot*> botVector;
	std::vector<Spieler*>  spielerVector;
	std::vector<Muenze*> muenzVector;
	std::vector<Bananenschale*> bananenschalenVector;
	Map* map;

	std::vector<sf::Texture> spielerTexturen;
	std::vector<sf::Texture> botTexturen;

	bool istTot = false;
	bool hatGewonnen = false;
public:
	~Objektverwalter();
	Objektverwalter();
	Objektverwalter(sf::RenderWindow* window, Map* map, EingabeVerwaltung* eingabeverwaltung, MusikVerwaltung* musikverwaltung);
	void botHinzufuegen(Bot* bot);
	void botGenerieren(unsigned short anzahl, int typ);
	void botLevelGenerieren(unsigned short anzahl, unsigned short reihen, int typ);
	void botsAktualisieren();
	void botsAnzeigen();
	void spielerHinzufuegen(Spieler* spieler);
	void spielerGenerieren(unsigned short anzahl, int typ);
	void spielerAktualisieren();
	void spielerAnzeigen();
	void viewAufGesteuertenSpieler(unsigned short spielerIndex);
	void infoVonSpielerAnzeigen(unsigned short spielerIndex);
	void muenzLevelGenerieren(unsigned short anzahl, unsigned short reihen);
	void muenzenAnzeigen();
	bool getIstTot();
	bool getHatGewonnen();
	int muenzenGesammt();
	void bananenschalenLevelGenerieren(unsigned short anzahl, unsigned short reihen);
	void bananenschalenAnzeigen();
};