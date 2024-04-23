#pragma once
#include "level2.hpp"

Level2::~Level2()
{
	delete this->autoverwalter;
	delete this->map;
}

Level2::Level2(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung)
{
	this->window = window;
	this->map = new Map(window);
	this->eingabeverwaltung = eingabeverwaltung;
	this->zustaende.mapAktualisieren = true;
	this->zustaende.mapAnzeigen = true;
	this->autoverwalter = new Autoverwalter(window, this->map, eingabeverwaltung);
	this->autoverwalter->botLevelGenerieren(1, 20, 2);
	this->autoverwalter->spielerHinzufuegen(new Spieler2(window, eingabeverwaltung));

}

void Level2::aktualisieren()
{
	this->unterbrechung = false;
	this->eingabeverwaltung->aktualisieren();

	if (this->zustaende.mapAktualisieren) {
		this->autoverwalter->botsAktualisieren();
		this->autoverwalter->spielerAktualisieren();
		if (this->autoverwalter->getIstTot()) {
			this->unterbrechung = true;
			this->unterbrechungsgrund = 0;
		}
		this->botGenerierungsIntervallZaehler++;
		if ((this->botGenerierungsIntervallZaehler >= this->botGenerierungsIntervall) && this->botGenerierungsIntervall != 0) {
			this->autoverwalter->botGenerieren(1, 2);
			this->botGenerierungsIntervallZaehler = 0;
		}
	}
}

void Level2::anzeigen()
{
	this->autoverwalter->viewAufGesteuertenSpieler(0);
	if (this->zustaende.mapAnzeigen) this->map->zeichnen();
	this->autoverwalter->botsAnzeigen();
	this->autoverwalter->spielerAnzeigen();
	this->map->brueckeZeichnen();
}

bool Level2::getUnterbrechung()
{
	return this->unterbrechung;
}

int Level2::getUnterbrechungsgrund()
{
	return this->unterbrechungsgrund;
}
