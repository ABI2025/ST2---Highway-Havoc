#pragma once
#include "SFML/Graphics.hpp"
#include "Auto.hpp"
#include "Startbildschirm.hpp"
#include "PauseMenue.hpp"
#include "Einstellungen.hpp"
#include "Map.hpp"
struct Zustaende
{
	bool startbildschirmAnzeigen = false;
	bool spielStarten = false;
	bool einstellungenAnzeigen = false;
	bool spielBeenden = false;
	bool pauseMenueAnzeigen = false;
};

class Game 
{
private:
	sf::RenderWindow* window;		//	Pointer auf window, weil window dynamisch ist (siehe Konstruktor)
	int fps;						//	Bildwiederholungsrate, mit der das Spiel läuft
	int tickrate;					//	Spielberechnungsrate, mit der das Spiel läuft
	Auto* test_auto;

	Zustaende zustaende;			//	Sagt was gerade angezeigt werden soll, bzw ausgeführt
	Startbildschirm* startbildschirm;
	PauseMenue* pauseMenue;
	Einstellungen* einstellungen;
	Map* map;
public:
	Game(int fps, int tickrate);	//	Konstruktor
	~Game();						//	Destruktor
	void render();					//	Hier kommt der Rendercode rein!!!!!
	void tick();					//	Hier kommt der Spielcode rein, der nicht der Rendercode ist!!!
	void start();					//	Ruft die Render- und Tick-Methoden auf.
};