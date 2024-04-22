#pragma once
#include "SFML/Graphics.hpp"
#include "../Automobil.hpp"
#include "../Spieler/Spieler.hpp"
#include "../../EingabeVerwaltung/EingabeVerwaltung.hpp"
class Spieler1 : public Spieler{
private:
	sf::RenderWindow* window;
	float geschwindigkeit;
	float rotation;
	float maxMinGeschwindigkeit = 3;
	float reibung = 0.01;
	float beschlaeunigung = 0.05;

	EingabeVerwaltung* eingabeverwaltung;
public:
	~Spieler1();
	Spieler1();
	Spieler1(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung);
	void aktualisieren();
};