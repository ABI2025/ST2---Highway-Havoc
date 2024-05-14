#pragma once
#include "Nachricht.hpp"

Nachricht::~Nachricht()
{
}

Nachricht::Nachricht(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, std::string nachrichtText, sf::Color umrandungsFarbe)
{
	this->window = window;
	this->eingabeverwaltung = eingabeverwaltung;
	if (!this->PixeboyFont.loadFromFile("./res/schriftarten/Pixeboy-z8XGD.ttf"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/schriftarten/Pixeboy-z8XGD.ttf)" << std::endl;
	}
	this->nachrichtText.setFont(PixeboyFont);									//	Parameter vom "Du bist gestorben!"-Schriftzug setzen
	this->nachrichtText.setFillColor(sf::Color::White);
	this->nachrichtText.setOutlineColor(umrandungsFarbe);
	this->nachrichtText.setOutlineThickness(1);
	this->nachrichtText.setCharacterSize(30);
	this->nachrichtText.setLetterSpacing(1);
	this->nachrichtText.setString(nachrichtText);
	this->nachrichtText.setOrigin(this->nachrichtText.getGlobalBounds().width / 2, this->nachrichtText.getGlobalBounds().height);

	this->aktzeptieren.setFont(PixeboyFont);									//	Parameter vom "Ok"-Schriftzug setzen
	this->aktzeptieren.setFillColor(sf::Color::Red);
	this->aktzeptieren.setOutlineColor(umrandungsFarbe);
	this->aktzeptieren.setOutlineThickness(1);
	this->aktzeptieren.setCharacterSize(30);
	this->aktzeptieren.setLetterSpacing(1);
	this->aktzeptieren.setString("Ok");
	this->aktzeptieren.setOrigin(aktzeptieren.getGlobalBounds().width / 2, aktzeptieren.getGlobalBounds().height);

	this->fensterHintergrund.setSize(sf::Vector2f(this->nachrichtText.getGlobalBounds().width + 10, this->aktzeptieren.getGlobalBounds().height + this->nachrichtText.getGlobalBounds().height + (this->nachrichtText.getPosition().y + this->nachrichtText.getGlobalBounds().height * 2 - this->aktzeptieren.getPosition().y)));
	this->fensterHintergrund.setFillColor(sf::Color(165, 166, 166, 155));
	this->fensterHintergrund.setOrigin(this->fensterHintergrund.getGlobalBounds().width / 2, 0);
	this->fensterHintergrund.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y);
}

void Nachricht::aktualisieren()
{
	this->auswahlGetroffen = false;
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(4) ||
		(this->eingabeverwaltung->mausPositionInFlaeche(this->aktzeptieren.getGlobalBounds()) &&
			this->eingabeverwaltung->getMausTastenStatusGeandertIndex(0))) this->auswahlGetroffen = true;
}

void Nachricht::anzeigen()
{
	this->nachrichtText.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y - 30);
	this->aktzeptieren.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y + 10);
	float asdf = this->aktzeptieren.getGlobalBounds().getPosition().y - this->nachrichtText.getGlobalBounds().getPosition().y + this->aktzeptieren.getGlobalBounds().height;
	//std::cout << asdf << std::endl;
	this->fensterHintergrund.setSize(sf::Vector2f(this->nachrichtText.getGlobalBounds().width + 10, asdf + 10));
	this->fensterHintergrund.setPosition(this->window->getView().getCenter().x, this->nachrichtText.getPosition().y - 5);
	this->window->draw(this->fensterHintergrund);
	this->window->draw(this->nachrichtText);
	this->window->draw(this->aktzeptieren);
}

bool Nachricht::getAuswahlGetroffen()
{
	return this->auswahlGetroffen;
}