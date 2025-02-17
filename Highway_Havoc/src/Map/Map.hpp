#pragma once
#include "SFML/Graphics.hpp"
class Map {
private:
	sf::RenderWindow* window;		//	Wird ben�tigt zum zeichnen
	sf::Texture strassenTextur;		//	Textur der Stra�e und co.
	sf::Sprite strasse;				//	Die beiden Stra�en wechseln sich ab um einen reibungslosen �bergang zu schaffen.
	sf::Texture brueckeTextur;		//	Textur der Br�cke und co.
	sf::Sprite bruecke;
	float streckungsFaktor;			//	Der Faktor um den das Bild gestreckt wird
	float geschwindigkeit = 1.8f;	//	Geschwindigkeit mit der die Bilder sich bewegen
public:
	~Map();
	Map(sf::RenderWindow* window, unsigned short typ);
	void zeichnen();
	void aktualisieren();
	sf::FloatRect getMapViereck();
	void brueckeZeichnen();
};