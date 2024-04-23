#pragma once
#include "SFML/Graphics.hpp"
class Map {
private:
	sf::RenderWindow* window;		//	Wird benötigt zum zeichnen
	sf::Texture strassenTextur;		//	Textur der Straße und co.
	sf::Sprite strasse;				//	Die beiden Straßen wechseln sich ab um einen reibungslosen Übergang zu schaffen.
	sf::Texture brueckeTextur;		//	Textur der Brücke und co.
	sf::Sprite bruecke;
	float streckungsFaktor;			//	Der Faktor um den das Bild gestreckt wird
	float geschwindigkeit = 1.8f;	//	Geschwindigkeit mit der die Bilder sich bewegen
public:
	~Map();
	Map(sf::RenderWindow* window);
	void zeichnen();
	void aktualisieren();
	sf::FloatRect getMapViereck();
	void brueckeZeichnen();
};