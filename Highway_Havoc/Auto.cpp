#include "Auto.hpp"
#include <iostream>

Auto::Auto(const char extLevel) :
	Position{ 0.f, 0.f },
	Geschwindigkeit{ 0.f, 0.f },
	Beschleunigung{ 0.f, 0.f},
	breite(60),
	hoehe(120)
{ 
	level = extLevel;

	switch (level)  // Lade die entsprechende Grafik des Levels des Autos in die Variable textur
	{
	case '0':
		if (!textur.loadFromFile("Scheiﬂauto.png")) std::cout << "Laden der Grafik fehlgeschlagen!";
	break;

	case '1':
		if (!textur.loadFromFile("Auto.png")) std::cout << "Laden der Grafik fehlgeschlagen!";
	break;

	//case '2':
	//	if (!textur.loadFromFile("Auto_lvl2.png")) std::cout << "Laden der Grafik fehlgeschlagen!";
	//break;

	//case '3':
	//	if (!textur.loadFromFile("Auto_lvl3.png")) std::cout << "Laden der Grafik fehlgeschlagen!";
	//break;

	default: std::cout << "Dieses Level gibt es nicht!";

	}

	derWicht.setTexture(textur);
}

/*
Auto::Auto(unsigned short extBreite, unsigned short extHoehe) :    // Parameterkonstruktor, welcher die Hˆhe und Breite des Autos festlegt
	xPos(0.f),
	yPos(0.f),
	xGeschw(0.f),
	yGeschw(0.f),
	xBeschleunigung(0.f),
	yBeschleunigung(0.f)
{
	// textur.loadFromFile("...") 
	derWicht.setTexture(textur);
	this->breite = extBreite;
	this->hoehe = extHoehe;
}
*/

Auto::~Auto() { }

// set-Methoden
void Auto::setPosition(sf::Vector2f extPosition) { Position = extPosition; }
void Auto::setXPosition(float extXPosition) { Position.x = extXPosition; }
void Auto::setYPosition(float extYPosition) { Position.y = extYPosition; }
void Auto::setHoehe(unsigned short extHoehe) { this->hoehe = extHoehe; }
void Auto::setBreite(unsigned short extBreite) { this->breite = extBreite; }
void Auto::setGeschwindigkeit(sf::Vector2f extGeschwindigkeit) { Geschwindigkeit = extGeschwindigkeit; }
void Auto::setXGeschwindigkeit(float extXGeschwindigkeit) { Geschwindigkeit.x = extXGeschwindigkeit; }
void Auto::setYGeschwindigkeit(float extYGeschwindigkeit) { Geschwindigkeit.y = extYGeschwindigkeit; }
void Auto::setBeschleunigung(sf::Vector2f extBeschleunigung) { Beschleunigung = extBeschleunigung; }
void Auto::setXBeschleunigung(float extXBeschleunigung) { Beschleunigung.x = extXBeschleunigung; }
void Auto::setYBeschleunigung(float extYBeschleunigung) { Beschleunigung.y = extYBeschleunigung; }

// get-Methoden
char Auto::getLevel() const { return level; }
sf::Vector2f Auto::getPosition() const { return Position; }
float Auto::getXPosition() const { return Position.x; }
float Auto::getYPosition() const { return Position.y; }
unsigned short Auto::getHoehe() const { return hoehe; }
unsigned short Auto::getBreite() const { return breite; }
sf::Vector2f Auto::getGeschwindigkeit() const { return Geschwindigkeit; }
float Auto::getXGeschwindigkeit() const { return Geschwindigkeit.x; }
float Auto::getYGeschwindigkeit() const { return Geschwindigkeit.y; }
sf::Vector2f Auto::getBeschleunigung() const { return Beschleunigung; }
float Auto::getXBeschleunigung() const { return Beschleunigung.x; }
float Auto::getYBeschleunigung() const { return Beschleunigung.y; }

void Auto::draw(sf::RenderWindow& window) const
{
	window.draw(derWicht);
}

