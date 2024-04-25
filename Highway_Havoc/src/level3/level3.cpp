#pragma once
#include "level3.hpp"

Level3::~Level3()
{
	delete this->autoverwalter;
	delete this->map;
}

Level3::Level3(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung)
{
	this->window = window;
	this->map = new Map(window);
	this->eingabeverwaltung = eingabeverwaltung;
	this->zustaende.mapAktualisieren = true;
	this->zustaende.mapAnzeigen = true;
	this->autoverwalter = new Autoverwalter(window, this->map, eingabeverwaltung);
	this->autoverwalter->botLevelGenerieren(2, 20, 2);
	this->autoverwalter->spielerHinzufuegen(new Spieler3(window, eingabeverwaltung));

}

void Level3::aktualisieren()
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
		if (this->autoverwalter->getHatGewonnen()) {
			this->unterbrechung = true;
			this->unterbrechungsgrund = 1;
		}
		this->botGenerierungsIntervallZaehler++;
		if ((this->botGenerierungsIntervallZaehler >= this->botGenerierungsIntervall) && this->botGenerierungsIntervall != 0) {
			this->autoverwalter->botGenerieren(2, 2);
			this->botGenerierungsIntervallZaehler = 0;
		}
	}
}

void Level3::anzeigen()
{
	this->autoverwalter->viewAufGesteuertenSpieler(0);
	if (this->zustaende.mapAnzeigen) this->map->zeichnen();
	this->autoverwalter->botsAnzeigen();
	this->autoverwalter->spielerAnzeigen();
	this->map->brueckeZeichnen();
}

bool Level3::getUnterbrechung()
{
	return this->unterbrechung;
}

int Level3::getUnterbrechungsgrund()
{
	return this->unterbrechungsgrund;
}
