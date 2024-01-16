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
	void setBewegung_links(sf::Keyboard::Key bewegung);
	void setBewegung_rechts(sf::Keyboard::Key bewegung_rechts);
	void setAction(sf::Keyboard::Key action);

	unsigned short getLautstaerke() const;
	unsigned short getFramerate() const;
	unsigned short getTickrate() const;
	sf::Keyboard::Key getBewegung_links() const;
	sf::Keyboard::Key getBewegung_rechts() const;
	sf::Keyboard::Key getAction() const;
};

