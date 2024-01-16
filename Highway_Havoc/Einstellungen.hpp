#pragma once
#include <SFML/Graphics.hpp>

class Einstellungen
{
private:
	//Allgemeine Einstellungen
	unsigned short lautstaerke;	// Min:0		Max:100
	unsigned short framerate;	// Min:10	Max:kein limit
	unsigned short tickrate;	// Min:10	Max:kein limit

	//Tastenbelegung
	sf::Keyboard::Key bewegung_links;		// Standard: <-
	sf::Keyboard::Key bewegung_rechts;		// Standard: ->
	sf::Keyboard::Key action;				// Standard: leertaste
public:
	~Einstellungen();
	Einstellungen();
	void setLautstaerke(unsigned short lautstaerke);
	void setFramerate(unsigned short framerate);
	void setTickrate(unsigned short tickrate);
	void setBewegung_links(unsigned short bewegung);
	void setBewegung_rechts(unsigned short bewegung_rechts);
	void setAction(unsigned short action);
};

