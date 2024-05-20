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

Level::Level(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, MusikVerwaltung* musikverwaltung, unsigned short anzahlBots, unsigned short botReihen, unsigned short botTyp, unsigned short anzahlSpieler, unsigned short spielerTyp, unsigned short anzahlMuenzen, unsigned short muenzReihen, unsigned short anzahlBananenschalen, unsigned short bananenschalenReihen, unsigned short mapTyp)
{
	this->window = window;
	this->map = new Map(window, mapTyp);
	this->eingabeverwaltung = eingabeverwaltung;
	this->zustaende.mapAktualisieren = true;
	this->zustaende.mapAnzeigen = true;
	this->musikverwaltung = musikverwaltung;
	this->objektverwalter = new Objektverwalter(window, this->map, eingabeverwaltung, musikverwaltung);
	this->objektverwalter->botLevelGenerieren(anzahlBots, botReihen, botTyp);
	this->objektverwalter->spielerGenerieren(anzahlSpieler, spielerTyp);
	this->objektverwalter->muenzLevelGenerieren(anzahlMuenzen, muenzReihen);
	this->objektverwalter->bananenschalenLevelGenerieren(anzahlBananenschalen, bananenschalenReihen);
	this->botAnzahl = anzahlBots;
	this->botTyp = botTyp;
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
			this->objektverwalter->botGenerieren(this->botAnzahl, this->botTyp);
			this->botGenerierungsIntervallZaehler = 0;
		}
	}
}

void Level::anzeigen()
{
	this->objektverwalter->viewAufGesteuertenSpieler(0);
	if (this->zustaende.mapAnzeigen) this->map->zeichnen();
	this->objektverwalter->bananenschalenAnzeigen();
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
