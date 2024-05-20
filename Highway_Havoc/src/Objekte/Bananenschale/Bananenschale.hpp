#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Bananenschale {
private:
	sf::RenderWindow* window; // Zeiger auf das SFML-Fenster
	sf::Texture bananenschaleTextur; // Textur für die Bananenschale
	sf::Sprite bananenschaleSprite; // Sprite für die Bananenschale
public:
	~Bananenschale(); // Destruktor
	Bananenschale(sf::RenderWindow* window); // Konstruktor, der ein Fenster erwartet
	void aktualisieren(); // Funktion zum Aktualisieren der Bananenschale
	void anzeigen(); // Funktion zum Anzeigen der Bananenschale im Fenster
	sf::Vector2f getPos(); // Funktion zum Abrufen der Position der Bananenschale
	void setPos(sf::Vector2f position); // Funktion zum Setzen der Position der Bananenschale
	sf::FloatRect getGlobalBounds(); // Funktion zum Abrufen der globalen Grenzen der Bananenschale
	bool kollidiert(sf::FloatRect viereck); // Funktion zur Kollisionserkennung mit einem übergebenen Rechteck
	sf::Sprite* getSprite(); // Funktion zum Abrufen des Sprites der Bananenschale
};
