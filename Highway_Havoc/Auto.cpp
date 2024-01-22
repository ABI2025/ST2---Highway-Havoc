#include "Auto.hpp"
#include <iostream>

Auto::Auto(const char extLevel) :   // Parameterkonstruktor zur Erstellung eines Autos 
	position{ 0.f, 0.f },
	geschwindigkeit{ 0.f, 0.f },
	beschleunigung{ 0.f, 0.f},
	breite(60),
	hoehe(120)
{ 
	level = extLevel;

	switch (level)  // Lade die entsprechende Grafik des Levels, des Autos in die Variable textur
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
	//	if (!textur.loadFromFile("Auto_lvl3.png")) std::cout << "Laden der Grafik fehlgeschlagen!";      // zuk¸nftige Autolevel
	//break;

	default: std::cout << "Dieses Level gibt es nicht!";

	}

	derWicht.setTexture(textur);    // entsprechende Textur / Bild in die Sprite laden um damit arbeiten zu kˆnnen (Position etc.)
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
void Auto::setPosition(sf::Vector2f extPosition) { position = extPosition; }
void Auto::setXPosition(float extXPosition) { position.x = extXPosition; }		// x und y getrennt macht nach aktuellem Stand keinen Sinn und ist ein Resultat aus der anf‰nglichen
void Auto::setYPosition(float extYPosition) { position.y = extYPosition; }      // Trennung der Koordinaten/Werte in zwei einzelne Variablen, besteht nun weiter bis evtl. nicht mehr nˆtig
void Auto::setHoehe(unsigned short extHoehe) { this->hoehe = extHoehe; }
void Auto::setBreite(unsigned short extBreite) { this->breite = extBreite; }
void Auto::setGeschwindigkeit(sf::Vector2f extGeschwindigkeit) { geschwindigkeit = extGeschwindigkeit; }
void Auto::setXGeschwindigkeit(float extXGeschwindigkeit) { geschwindigkeit.x = extXGeschwindigkeit; }
void Auto::setYGeschwindigkeit(float extYGeschwindigkeit) { geschwindigkeit.y = extYGeschwindigkeit; }
void Auto::setBeschleunigung(sf::Vector2f extBeschleunigung) { beschleunigung = extBeschleunigung; }
void Auto::setXBeschleunigung(float extXBeschleunigung) { beschleunigung.x = extXBeschleunigung; }
void Auto::setYBeschleunigung(float extYBeschleunigung) { beschleunigung.y = extYBeschleunigung; }

// get-Methoden
char Auto::getLevel() const { return level; }
sf::Vector2f Auto::getPosition() const { return position; }
float Auto::getXPosition() const { return position.x; }	    // x und y getrennt macht nach aktuellem Stand keinen Sinn und ist ein Resultat aus der anf‰nglichen
float Auto::getYPosition() const { return position.y; }		// Trennung der Koordinaten/Werte in zwei einzelne Variablen, besteht nun weiter bis evtl. nicht mehr nˆtig
unsigned short Auto::getHoehe() const { return hoehe; }
unsigned short Auto::getBreite() const { return breite; }
sf::Vector2f Auto::getGeschwindigkeit() const { return geschwindigkeit; }
float Auto::getXGeschwindigkeit() const { return geschwindigkeit.x; }
float Auto::getYGeschwindigkeit() const { return geschwindigkeit.y; }
sf::Vector2f Auto::getBeschleunigung() const { return beschleunigung; }
float Auto::getXBeschleunigung() const { return beschleunigung.x; }
float Auto::getYBeschleunigung() const { return beschleunigung.y; }

void Auto::update()  // Bringt die Werte der Variablen auf den "aktuellen" Stand
{
	geschwindigkeit += beschleunigung; // Die Geschwindigkeit wird um Beschleunigung erhˆht
	position -= geschwindigkeit;       // Die Position minus die Geschwindigkeit ergibt die neue Position, da (0|0) oben links ist => somit Position kleiner Auto kommt n‰her an oberen Bildrand

	derWicht.setPosition(position);
}

void Auto::draw(sf::RenderWindow& window) // Zeichnet das Auto...
{
	update();  // nur tempor‰r in der draw()-Methode, muss sp‰ter an anderer Stelle stehen

	window.draw(derWicht);
}

