#pragma once
#include "Startbildschirm.hpp"
#include <iostream>

Startbildschirm::~Startbildschirm()
{
}

Startbildschirm::Startbildschirm(sf::RenderWindow* window)
{
	this->window = window;
	if (!this->PixeboyFont.loadFromFile("Pixeboy-z8XGD.ttf"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (Pixeboy-z8XGD.ttf)" << std::endl;
	}

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
	this->spielStartText.setString("Spiel starten");
	this->spielStartText.setPosition({ window->getSize().x / 2 - spielStartText.getGlobalBounds().width / 2, 60 });

	this->einstellungenOeffnenText.setFont(PixeboyFont);							//	Parameter und Position vom "Einstellungen"-Schriftzug setzen
	this->einstellungenOeffnenText.setFillColor(sf::Color::White);
	this->einstellungenOeffnenText.setOutlineColor(sf::Color::White);
	this->einstellungenOeffnenText.setCharacterSize(30);
	this->einstellungenOeffnenText.setLetterSpacing(1);
	this->einstellungenOeffnenText.setString("Einstellungen");
	this->einstellungenOeffnenText.setPosition({ window->getSize().x / 2 - einstellungenOeffnenText.getGlobalBounds().width / 2, 85 });

	this->spielBeendenText.setFont(PixeboyFont);									//	Parameter und Position vom "Spiel beenden"-Schriftzug setzen
	this->spielBeendenText.setFillColor(sf::Color::White);
	this->spielBeendenText.setOutlineColor(sf::Color::White);
	this->spielBeendenText.setCharacterSize(30);
	this->spielBeendenText.setLetterSpacing(1);
	this->spielBeendenText.setString("Spiel beenden");
	this->spielBeendenText.setPosition({ window->getSize().x / 2 - spielBeendenText.getGlobalBounds().width / 2, 110 });

	this->eingabeverwaltung.tasteHinzufuegen(sf::Keyboard::Key::Up);				//	Die Tasten zum Steuern zur Beobachtungsliste, der Eingabeverwaltung, hinzufügen
	this->eingabeverwaltung.tasteHinzufuegen(sf::Keyboard::Key::Down);
	this->eingabeverwaltung.tasteHinzufuegen(sf::Keyboard::Key::Enter);
}

void Startbildschirm::anzeigen()
{
	this->window->clear(sf::Color(55, 166, 166, 255));								//	Hintergundfarbe setzten

	this->spielStartText.setFillColor(sf::Color::White);							//	die Farbe der Momentan getroffenen Auswahl auf Rot setzten, den Rest auf Weiß
	this->einstellungenOeffnenText.setFillColor(sf::Color::White);
	this->spielBeendenText.setFillColor(sf::Color::White);
	if (this->auswahl == 0) {
		this->spielStartText.setFillColor(sf::Color::Red);
	}
	if (this->auswahl == 1) {
		this->einstellungenOeffnenText.setFillColor(sf::Color::Red);
	}
	if (this->auswahl == 2) {
		this->spielBeendenText.setFillColor(sf::Color::Red);
	}

	this->window->draw(titelText);													//	die Textelemente zeichenen
	this->window->draw(spielStartText);
	this->window->draw(einstellungenOeffnenText);
	this->window->draw(spielBeendenText);
}

void Startbildschirm::aktualisieren()
{
	this->eingabeverwaltung.aktualisieren();										//	die Eingabeverwaltung aktualisieren

	if (this->eingabeverwaltung.getTastenStatusGeandertIndex(0) && auswahl > 0) {	// Die Eingabe überprüfen und die Auswahl anpassen
		this->auswahl -= 1;
	}
	if (this->eingabeverwaltung.getTastenStatusGeandertIndex(1) && auswahl < 2) {	// Die Eingabe überprüfen und die Auswahl anpassen
		this->auswahl += 1;
	}
	if (this->eingabeverwaltung.getTastenStatusGeandertIndex(2) == true) {			//	Überprüfen ob die Auswahl Getroffen wurde
		this->auswahlGetroffen = true;
	}
}

short Startbildschirm::getAuswahl()
{
	return this->auswahl;
}

bool Startbildschirm::getAuswahlGetroffen()
{
	return this->auswahlGetroffen;
}
