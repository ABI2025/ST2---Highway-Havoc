#pragma once
#include "SFML/Graphics.hpp"

class Game {
private:
	sf::RenderWindow* window;		//	Pointer auf window, weil window dynamisch ist (siehe Konstruktor)
	int fps;						//	Bildwiederholungsrate, mit der das Spiel läuft
	int tickrate;					//	Spielberechnungsrate, mit der das Spiel läuft
public:
	Game(int fps, int tickrate);	//	Konstruktor
	~Game();						//	Destruktor
	void render();					//	Hier kommt der Rendercode rein!!!!!
	void tick();					//	Hier kommt der Spielcode rein, der nicht der Rendercode ist!!!
	void start();					//	Ruft die Render- und Tick-Methoden auf.
};