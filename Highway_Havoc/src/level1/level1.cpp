#pragma once
#include "level1.hpp"

Level1::~Level1()
{
	delete this->autoverwalter;
	delete this->map;
}

Level1::Level1(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung)
{
	this->window = window;
	this->map = new Map(window);
	this->eingabeverwaltung = eingabeverwaltung;
	this->zustaende.mapAktualisieren = true;
	this->zustaende.mapAnzeigen = true;
	this->autoverwalter = new Autoverwalter(window, this->map, eingabeverwaltung);
	this->autoverwalter->botLevelGenerieren(1, 20, 1);
	this->autoverwalter->spielerGenerieren(1, 1);

}

void Level1::aktualisieren()
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
			this->autoverwalter->botGenerieren(1, 1);
			this->botGenerierungsIntervallZaehler = 0;
		}
	}
}

void Level1::anzeigen()
{
	this->autoverwalter->viewAufGesteuertenSpieler(0);
	if (this->zustaende.mapAnzeigen) this->map->zeichnen();
	this->autoverwalter->botsAnzeigen();
	this->autoverwalter->spielerAnzeigen();
	this->map->brueckeZeichnen();
	this->autoverwalter->infoVonSpielerAnzeigen(0);
}

bool Level1::getUnterbrechung()
{
	return this->unterbrechung;
}

int Level1::getUnterbrechungsgrund()
{
	return this->unterbrechungsgrund;
}
