//#include "Level.hpp"
//
//int Level::muenzenGesammelt()
//{
//    return 10;
//}
#pragma once
#include "Level.hpp"

Level::~Level()
{
	delete this->objektverwalter;
	delete this->map;
}

Level::Level(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, unsigned short anzahlBots, unsigned short botReihen, unsigned short botTyp, unsigned short anzahlSpieler, unsigned short spielerTyp, unsigned short anzahlMuenzen, unsigned short muenzReihen)
{
	this->window = window;
	this->map = new Map(window);
	this->eingabeverwaltung = eingabeverwaltung;
	this->zustaende.mapAktualisieren = true;
	this->zustaende.mapAnzeigen = true;
	this->objektverwalter = new Objektverwalter(window, this->map, eingabeverwaltung);
	this->objektverwalter->botLevelGenerieren(anzahlBots, botReihen, botTyp);
	this->objektverwalter->spielerGenerieren(anzahlSpieler, spielerTyp);
	this->objektverwalter->muenzLevelGenerieren(anzahlMuenzen, muenzReihen);
}

void Level::aktualisieren()
{
	this->unterbrechung = false;
	this->eingabeverwaltung->aktualisieren();

	if (this->zustaende.mapAktualisieren) {
		this->objektverwalter->botsAktualisieren();
		this->objektverwalter->spielerAktualisieren();
		if (this->objektverwalter->getIstTot()) {
			this->unterbrechung = true;
			this->unterbrechungsgrund = 0;
		}
		if (this->objektverwalter->getHatGewonnen()) {
			this->unterbrechung = true;
			this->unterbrechungsgrund = 1;
		}
		this->botGenerierungsIntervallZaehler++;
		if ((this->botGenerierungsIntervallZaehler >= this->botGenerierungsIntervall) && this->botGenerierungsIntervall != 0) {
			this->objektverwalter->botGenerieren(1, 1);
			this->botGenerierungsIntervallZaehler = 0;
		}
	}
}

void Level::anzeigen()
{
	this->objektverwalter->viewAufGesteuertenSpieler(0);
	if (this->zustaende.mapAnzeigen) this->map->zeichnen();
	this->objektverwalter->muenzenAnzeigen();
	this->objektverwalter->botsAnzeigen();
	this->objektverwalter->spielerAnzeigen();
	this->map->brueckeZeichnen();
	this->objektverwalter->infoVonSpielerAnzeigen(0);
}

bool Level::getUnterbrechung()
{
	return this->unterbrechung;
}

int Level::getUnterbrechungsgrund()
{
	return this->unterbrechungsgrund;
}

int Level::muenzenGesammelt()
{
	return this->objektverwalter->muenzenGesammt();
}
