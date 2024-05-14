#pragma once
#include "PauseMenue.hpp"
#include <iostream>

PauseMenue::~PauseMenue()
{
}

PauseMenue::PauseMenue(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung)
{
	this->window = window;
	this->eingabeverwaltung = eingabeverwaltung;
	if (!this->PixeboyFont.loadFromFile("./res/schriftarten/Pixeboy-z8XGD.ttf"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/schriftarten/Pixeboy-z8XGD.ttf)" << std::endl;
	}

	this->spielStartText.setFont(PixeboyFont);										//	Parameter und Position vom "Spiel starten"-Schriftzug setzen
	this->spielStartText.setFillColor(sf::Color::White);
	this->spielStartText.setOutlineColor(sf::Color::White);
	this->spielStartText.setCharacterSize(30);
	this->spielStartText.setLetterSpacing(1);
	this->spielStartText.setString("Spiel fortsetzen");
	this->spielStartText.setOrigin(spielStartText.getGlobalBounds().width / 2, spielStartText.getGlobalBounds().width);
	this->spielStartText.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y + 159);

	this->einstellungenOeffnenText.setFont(PixeboyFont);							//	Parameter und Position vom "Einstellungen"-Schriftzug setzen
	this->einstellungenOeffnenText.setFillColor(sf::Color::White);
	this->einstellungenOeffnenText.setOutlineColor(sf::Color::White);
	this->einstellungenOeffnenText.setCharacterSize(30);
	this->einstellungenOeffnenText.setLetterSpacing(1);
	this->einstellungenOeffnenText.setString("Einstellungen");
	this->einstellungenOeffnenText.setOrigin(einstellungenOeffnenText.getGlobalBounds().width / 2, einstellungenOeffnenText.getGlobalBounds().width);
	this->einstellungenOeffnenText.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y + 157);

	this->spielBeendenText.setFont(PixeboyFont);									//	Parameter und Position vom "Spiel beenden"-Schriftzug setzen
	this->spielBeendenText.setFillColor(sf::Color::White);
	this->spielBeendenText.setOutlineColor(sf::Color::White);
	this->spielBeendenText.setCharacterSize(30);
	this->spielBeendenText.setLetterSpacing(1);
	this->spielBeendenText.setString("Spiel beenden");
	this->spielBeendenText.setOrigin(spielBeendenText.getGlobalBounds().width / 2, spielBeendenText.getGlobalBounds().height);
	this->spielBeendenText.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y + 27);

	this->fensterHintergrund.setSize(sf::Vector2f(250, 100));
	this->fensterHintergrund.setFillColor(sf::Color(165, 166, 166, 155));
	this->fensterHintergrund.setOrigin(this->fensterHintergrund.getGlobalBounds().width / 2, this->fensterHintergrund.getGlobalBounds().height / 2);
	this->fensterHintergrund.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y);
}

void PauseMenue::anzeigen()
{
	this->fensterHintergrund.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y);
	this->spielBeendenText.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y + 27);
	this->einstellungenOeffnenText.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y + 157);
	this->spielStartText.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y + 159);

	this->window->draw(this->fensterHintergrund);

	this->spielStartText.setFillColor(sf::Color::White);							//	Die Farbe der Momentan getroffenen Auswahl auf Rot setzten, den Rest auf Weiß
	this->einstellungenOeffnenText.setFillColor(sf::Color::White);
	this->spielBeendenText.setFillColor(sf::Color::White);
	if (this->auswahl == 0)
	{
		this->spielStartText.setFillColor(sf::Color::Red);
	}
	if (this->auswahl == 1)
	{
		this->einstellungenOeffnenText.setFillColor(sf::Color::Red);
	}
	if (this->auswahl == 2)
	{
		this->spielBeendenText.setFillColor(sf::Color::Red);
	}

	this->window->draw(spielStartText);
	this->window->draw(einstellungenOeffnenText);
	this->window->draw(spielBeendenText);
}

void PauseMenue::aktualisieren()
{
	//this->eingabeverwaltung->aktualisieren();										//	Die Eingabeverwaltung aktualisieren
	bool benutztMaus = false;														//	Gibt an ob die Maus sich über einem Textfeld befindet
	this->auswahlGetroffen = false;													//	AuswahlGetroffen zurücksetzten

	if (this->eingabeverwaltung->getGruppenStatusGeaendert(0) && this->auswahl > 0) 	//	Die Eingabe überprüfen und die Auswahl anpassen
	{
		this->auswahl -= 1;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(2) && this->auswahl < 2) 	//	Die Eingabe überprüfen und die Auswahl anpassen
	{
		this->auswahl += 1;
	}
	//	Die Mausposition prüfen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->spielStartText.getGlobalBounds())) {
		this->auswahl = 0;
		benutztMaus = true;
	}																				//	Die Mausposition prüfen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->einstellungenOeffnenText.getGlobalBounds())) {
		this->auswahl = 1;
		benutztMaus = true;
	}																				//	Die Mausposition prüfen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->spielBeendenText.getGlobalBounds())) {
		this->auswahl = 2;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(4) == true			//	Überprüfen ob die Auswahl getroffen wurde
		|| (this->eingabeverwaltung->getMausTastenStatusGeandertIndex(0) == true && benutztMaus == true))
	{
		this->auswahlGetroffen = true;
	}
}

short PauseMenue::getAuswahl()
{
	return this->auswahl;
}

bool PauseMenue::getAuswahlGetroffen()
{
	return this->auswahlGetroffen;
}