#pragma once
#include "VerlorenBildschirm.hpp"

VerlorenBildschirm::~VerlorenBildschirm()
{
}

VerlorenBildschirm::VerlorenBildschirm(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung)
{
	this->window = window;
	this->eingabeverwaltung = eingabeverwaltung;
	if (!this->PixeboyFont.loadFromFile("./res/schriftarten/Pixeboy-z8XGD.ttf"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/schriftarten/Pixeboy-z8XGD.ttf)" << std::endl;
	}
	this->nachricht.setFont(PixeboyFont);									//	Parameter vom "Du bist gestorben!"-Schriftzug setzen
	this->nachricht.setFillColor(sf::Color::White);
	this->nachricht.setOutlineColor(sf::Color(237, 28, 36, 55));
	this->nachricht.setOutlineThickness(1);
	this->nachricht.setCharacterSize(30);
	this->nachricht.setLetterSpacing(1);
	this->nachricht.setString("Du bist gestorben!");
	this->nachricht.setOrigin(nachricht.getGlobalBounds().width / 2, nachricht.getGlobalBounds().height);

	this->aktzeptieren.setFont(PixeboyFont);									//	Parameter vom "Ok"-Schriftzug setzen
	this->aktzeptieren.setFillColor(sf::Color::Red);
	this->aktzeptieren.setOutlineColor(sf::Color(237, 28, 36, 55));
	this->aktzeptieren.setOutlineThickness(1);
	this->aktzeptieren.setCharacterSize(30);
	this->aktzeptieren.setLetterSpacing(1);
	this->aktzeptieren.setString("Ok");
	this->aktzeptieren.setOrigin(aktzeptieren.getGlobalBounds().width / 2, aktzeptieren.getGlobalBounds().height);

	this->fensterHintergrund.setSize(sf::Vector2f(250, 100));
	this->fensterHintergrund.setFillColor(sf::Color(165, 166, 166, 155));
	this->fensterHintergrund.setOrigin(this->fensterHintergrund.getGlobalBounds().width / 2, this->fensterHintergrund.getGlobalBounds().height / 2);
	this->fensterHintergrund.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y);
}

void VerlorenBildschirm::aktualisieren()
{
	this->auswahlGetroffen = false;
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(4) ||
		(this->eingabeverwaltung->mausPositionInFlaeche(this->aktzeptieren.getGlobalBounds()) &&
			this->eingabeverwaltung->getMausTastenStatusGeandertIndex(0))) this->auswahlGetroffen = true;
}

void VerlorenBildschirm::anzeigen()
{
	this->fensterHintergrund.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y);
	this->nachricht.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y - 30);
	this->aktzeptieren.setPosition(this->window->getView().getCenter().x, this->window->getView().getCenter().y + 10);
	this->window->draw(this->fensterHintergrund);
	this->window->draw(this->nachricht);
	this->window->draw(this->aktzeptieren);
}

bool VerlorenBildschirm::getAuswahlGetroffen()
{
	return this->auswahlGetroffen;
}