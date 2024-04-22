#pragma once
#include "SFML/Graphics.hpp"
#include "./Startbildschirm/Startbildschirm.hpp"
#include "./PauseMenue/PauseMenue.hpp"
#include "./Einstellungen/Einstellungen.hpp"
#include "./LevelAuswahl/LevelAuswahl.hpp"
#include "./EingabeVerwaltung/EingabeVerwaltung.hpp"
#include "./MusikVerwaltung/MusikVerwaltung.hpp"

struct Zustaende
{
	bool spielLaeuft = false;
	bool startBildschirmLaeuft = false;
	bool einstellungenLaeuft = false;

	bool spielAnzeigen = false;
	bool startBildschirmAnzeigen = false;
	bool einstellungenAnzeigen = false;

	char einstellungenAufgerufenVon = ' '; // S = Startbildschirm P = PauseMenue

	bool musikStartbildschirmSpielen = false;
	bool musikSpielSpielen = false;

	bool programmBeenden = false;
};

class Game 
{
private:
	sf::RenderWindow* window;		//	Pointer auf window, weil window dynamisch ist (siehe Konstruktor)
	int fps;						//	Bildwiederholungsrate, mit der das Spiel läuft
	int tickrate;					//	Spielberechnungsrate, mit der das Spiel läuft

	Zustaende zustaende;			//	Sagt was gerade angezeigt werden soll, bzw ausgeführt
	Startbildschirm* startbildschirm;
	Einstellungen* einstellungen;
	LevelAuswahl* levelauswahl;
	EingabeVerwaltung* eingabeverwaltung;
	MusikVerwaltung* musikverwaltung;
	
	sf::Event* event;
public:
	Game(int fps, int tickrate);	//	Konstruktor
	~Game();						//	Destruktor
	void render();					//	Hier kommt der Rendercode rein!!!!!
	void tick();					//	Hier kommt der Spielcode rein, der nicht der Rendercode ist!!!
	void start();					//	Ruft die Render- und Tick-Methoden auf.
	void autoKollisionen();         //  Prüfen ob sich Autos berühren 
};