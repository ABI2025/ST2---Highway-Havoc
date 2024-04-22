#pragma once
#include "SFML/Graphics.hpp"
#include "../Automobil.hpp"
#include "../../EingabeVerwaltung/EingabeVerwaltung.hpp"
class Spieler : public Automobil{
//private:
//	sf::RenderWindow* window;
//	float geschwindigkeit;
//	float rotation;
//	float maxMinGeschwindigkeit = 3;
//	float reibung = 0.01;
//	float beschlaeunigung = 0.05;
//
//	EingabeVerwaltung* eingabeverwaltung;
public:
	virtual ~Spieler();
	Spieler();
	Spieler(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung);
	virtual void aktualisieren() = 0;
};