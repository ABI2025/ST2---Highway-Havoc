#pragma once
#include "Startbildschirm.hpp"
#include <iostream>

Startbildschirm::~Startbildschirm()
{
}

Startbildschirm::Startbildschirm(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, Fortschritt* fortschritt)
{
	this->window = window;
	this->eingabeverwaltung = eingabeverwaltung;
	this->fortschritt = fortschritt;
	if (!this->PixeboyFont.loadFromFile("./res/schriftarten/Pixeboy-z8XGD.ttf"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/schriftarten/Pixeboy-z8XGD.ttf)" << std::endl;
	}
	if (!this->autoTextur.loadFromFile("./res/grafiken/auto_startbildschirm.png")) {
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/auto_startbildschirm.png)" << std::endl;
	}
	this->autoSprite.setTexture(this->autoTextur);
	this->autoSprite.setScale({ 1.5f,1.5f });
	this->autoSprite.setPosition(window->getSize().x / 2 - autoSprite.getGlobalBounds().width / 2, 150);

	this->titelText.setFont(PixeboyFont);											//	Parameter und Position vom Titeltext setzen
	this->titelText.setFillColor(sf::Color::White);
	this->titelText.setOutlineColor(sf::Color::White);
	this->titelText.setCharacterSize(60);
	this->titelText.setLetterSpacing(1);
	this->titelText.setString("Highway Havoc");
	this->titelText.setPosition({ window->getSize().x / 2 - titelText.getGlobalBounds().width / 2, 0 });

	this->spielStartText.setFont(PixeboyFont);										//	Parameter und Position vom "Spiel starten"-Schriftzug setzen
	this->spielStartText.setFillColor(sf::Color::White);
	this->spielStartText.setOutlineColor(sf::Color::White);
	this->spielStartText.setCharacterSize(30);
	this->spielStartText.setLetterSpacing(1);
	this->spielStartenCString[14] = (char)(this->fortschritt->getSpielstand() + 48);
	this->spielStartText.setString(this->spielStartenCString);
	this->spielStartText.setPosition({ window->getSize().x / 2 - spielStartText.getGlobalBounds().width / 2, 80 });

	this->speicherstandHoch.setFont(PixeboyFont);
	this->speicherstandHoch.setFillColor(sf::Color::White);
	this->speicherstandHoch.setOutlineColor(sf::Color::White);
	this->speicherstandHoch.setCharacterSize(30);
	this->speicherstandHoch.setLetterSpacing(1);
	this->speicherstandHoch.setString(">");
	this->speicherstandHoch.setPosition(this->spielStartText.getGlobalBounds().getPosition().x + this->spielStartText.getGlobalBounds().getSize().x + 10, 80);

	this->speicherstandRunter.setFont(PixeboyFont);
	this->speicherstandRunter.setFillColor(sf::Color::White);
	this->speicherstandRunter.setOutlineColor(sf::Color::White);
	this->speicherstandRunter.setCharacterSize(30);
	this->speicherstandRunter.setLetterSpacing(1);
	this->speicherstandRunter.setString("<");
	this->speicherstandRunter.setPosition(this->spielStartText.getGlobalBounds().getPosition().x - this->speicherstandRunter.getGlobalBounds().getSize().x - 10, 80);

	this->einstellungenOeffnenText.setFont(PixeboyFont);							//	Parameter und Position vom "Einstellungen"-Schriftzug setzen
	this->einstellungenOeffnenText.setFillColor(sf::Color::White);
	this->einstellungenOeffnenText.setOutlineColor(sf::Color::White);
	this->einstellungenOeffnenText.setCharacterSize(30);
	this->einstellungenOeffnenText.setLetterSpacing(1);
	this->einstellungenOeffnenText.setString("Einstellungen");
	this->einstellungenOeffnenText.setPosition({ window->getSize().x / 2 - einstellungenOeffnenText.getGlobalBounds().width / 2, 110 });

	this->spielBeendenText.setFont(PixeboyFont);									//	Parameter und Position vom "Spiel beenden"-Schriftzug setzen
	this->spielBeendenText.setFillColor(sf::Color::White);
	this->spielBeendenText.setOutlineColor(sf::Color::White);
	this->spielBeendenText.setCharacterSize(30);
	this->spielBeendenText.setLetterSpacing(1);
	this->spielBeendenText.setString("Spiel beenden");
	this->spielBeendenText.setPosition({ window->getSize().x / 2 - spielBeendenText.getGlobalBounds().width / 2, 140 });
}

void Startbildschirm::anzeigen()
{
	this->window->setView(sf::View(sf::Vector2f(this->window->getView().getSize().x / 2, this->window->getView().getSize().y / 2), sf::Vector2f(this->window->getView().getSize().x, this->window->getView().getSize().y)));
	this->window->clear(sf::Color(55, 166, 166, 255));								//	Hintergundfarbe setzten
	this->spielStartenCString[14] = (char)(this->fortschritt->getSpielstand() + 48);
	this->spielStartText.setString(this->spielStartenCString);

	this->spielStartText.setFillColor(sf::Color::White);							//	Die Farbe der Momentan getroffenen Auswahl auf Rot setzten, den Rest auf Weiß
	this->einstellungenOeffnenText.setFillColor(sf::Color::White);
	this->spielBeendenText.setFillColor(sf::Color::White);
	this->speicherstandHoch.setFillColor(sf::Color::White);
	this->speicherstandRunter.setFillColor(sf::Color::White);
	if (this->auswahlX == 0)
	{
		if (this->auswahlY == 0) this->speicherstandRunter.setFillColor(sf::Color::Red);
		if (this->auswahlY == 1) this->spielStartText.setFillColor(sf::Color::Red);
		if (this->auswahlY == 2) this->speicherstandHoch.setFillColor(sf::Color::Red);
	}
	if (this->auswahlX == 1)
	{
		this->einstellungenOeffnenText.setFillColor(sf::Color::Red);
	}
	if (this->auswahlX == 2)
	{
		this->spielBeendenText.setFillColor(sf::Color::Red);
	}

	this->window->draw(titelText);													//	Die Textelemente zeichenen
	this->window->draw(spielStartText);
	this->window->draw(einstellungenOeffnenText);
	this->window->draw(spielBeendenText);
	this->window->draw(speicherstandHoch);
	this->window->draw(speicherstandRunter);
	this->window->draw(autoSprite);
}

void Startbildschirm::aktualisieren()
{
	this->eingabeverwaltung->aktualisieren();										//	Die Eingabeverwaltung aktualisieren
	bool benutztMaus = false;														//	Gibt an ob die Maus sich über einem Textfeld befindet
	this->auswahlGetroffen = false;													//	AuswahlGetroffen zurücksetzten

	if (this->eingabeverwaltung->getGruppenStatusGeaendert(0) && auswahlX > 0) 	//	Die Eingabe überprüfen und die Auswahl anpassen
	{
		this->auswahlX -= 1;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(2) && auswahlX < 2) 	//	Die Eingabe überprüfen und die Auswahl anpassen
	{
		this->auswahlX += 1;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(1) && auswahlX == 0 && auswahlY > 0) 	//	Die Eingabe überprüfen und die Auswahl anpassen
	{
		this->auswahlY -= 1;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(3) && auswahlX == 0 && auswahlY < 2) 	//	Die Eingabe überprüfen und die Auswahl anpassen
	{
		this->auswahlY += 1;
	}
	//	Die Mausposition prüfen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->spielStartText.getGlobalBounds())) {
		this->auswahlX = 0;
		this->auswahlY = 1;
		benutztMaus = true;
	}																				//	Die Mausposition prüfen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->einstellungenOeffnenText.getGlobalBounds())) {
		this->auswahlX = 1;
		benutztMaus = true;
	}																				//	Die Mausposition prüfen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->spielBeendenText.getGlobalBounds())) {
		this->auswahlX = 2;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->speicherstandHoch.getGlobalBounds())) {
		this->auswahlX = 0;
		this->auswahlY = 2;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->speicherstandRunter.getGlobalBounds())) {
		this->auswahlX = 0;
		this->auswahlY = 0;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(4) == true			//	Überprüfen ob die Auswahl getroffen wurde
		|| (this->eingabeverwaltung->getMausTastenStatusGeandertIndex(0) == true && benutztMaus == true))
	{
		this->auswahlGetroffen = true;
	}
}

short Startbildschirm::getAuswahlX()
{
	return this->auswahlX;
}
short Startbildschirm::getAuswahlY()
{
	return this->auswahlY;
}

bool Startbildschirm::getAuswahlGetroffen()
{
	return this->auswahlGetroffen;
}