#pragma once
#include "PauseMenue.hpp"
#include <iostream>

PauseMenue::~PauseMenue()
{
}

PauseMenue::PauseMenue(sf::RenderWindow* window)
{
	this->window = window;
	this->eingabeverwaltung = new EingabeVerwaltung(window);
	if (!this->PixeboyFont.loadFromFile("Pixeboy-z8XGD.ttf"))						//	L�d die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss sp�ter im selben Verzeichniss sein wie die ausf�rbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (Pixeboy-z8XGD.ttf)" << std::endl;
	}
	if (!this->autoTextur.loadFromFile("auto_startbildschirm.png")) {
		std::cout << "Fehler beim laden der Textur! (auto_startbildschirm.png)" << std::endl;
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
	this->spielStartText.setString("Spiel fortsetzen");
	this->spielStartText.setPosition({ window->getSize().x / 2 - spielStartText.getGlobalBounds().width / 2, 80 });

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

	fensterHintergrund.setSize(sf::Vector2f(250, 100));
	fensterHintergrund.setFillColor(sf::Color(165, 166, 166, 155));
	fensterHintergrund.setPosition({ window->getSize().x / 2 - fensterHintergrund.getGlobalBounds().width / 2, 80 });

	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Up);				//	Die Tasten zum Steuern zur Beobachtungsliste, der Eingabeverwaltung, hinzuf�gen
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Down);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Enter);
	this->eingabeverwaltung->mausTasteHinzufuegen(sf::Mouse::Button::Left);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Escape);
}

void PauseMenue::anzeigen()
{
	//this->window->clear(sf::Color(55, 166, 166, 255));								//	Hintergundfarbe setzten
	this->window->draw(fensterHintergrund);

	this->spielStartText.setFillColor(sf::Color::White);							//	Die Farbe der Momentan getroffenen Auswahl auf Rot setzten, den Rest auf Wei�
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

	//this->window->draw(titelText);													//	Die Textelemente zeichenen
	this->window->draw(spielStartText);
	this->window->draw(einstellungenOeffnenText);
	this->window->draw(spielBeendenText);
	//this->window->draw(autoSprite);
}

void PauseMenue::aktualisieren()
{
	//this->eingabeverwaltung->aktualisieren();										//	Die Eingabeverwaltung aktualisieren
	bool benutztMaus = false;														//	Gibt an ob die Maus sich �ber einem Textfeld befindet
	this->auswahlGetroffen = false;													//	AuswahlGetroffen zur�cksetzten

	//std::cout << this->eingabeverwaltung->getTastenIndex(0) << std::endl;
	//std::cout << this->eingabeverwaltung->getTastenStatusIndex(0) << std::endl;
	if (this->eingabeverwaltung->getTastenStatusGeandertIndex(0) && this->auswahl > 0) 	//	Die Eingabe �berpr�fen und die Auswahl anpassen
	{
		this->auswahl -= 1;

	}
	if (this->eingabeverwaltung->getTastenStatusGeandertIndex(1) && this->auswahl < 2) 	//	Die Eingabe �berpr�fen und die Auswahl anpassen
	{
		this->auswahl += 1;

	}
	//	Die Mausposition pr�fen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->spielStartText.getGlobalBounds())) {
		this->auswahl = 0;
		benutztMaus = true;
	}																				//	Die Mausposition pr�fen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->einstellungenOeffnenText.getGlobalBounds())) {
		this->auswahl = 1;
		benutztMaus = true;
	}																				//	Die Mausposition pr�fen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->spielBeendenText.getGlobalBounds())) {
		this->auswahl = 2;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->getTastenStatusGeandertIndex(2) == true			//	�berpr�fen ob die Auswahl getroffen wurde
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

bool PauseMenue::getEsc()
{
	//sf::Event ev;
	//window->pollEvent(ev);
	//if (ev.key.code == sf::Keyboard::Key::C) {
	//	return true;
	//}
	this->eingabeverwaltung->aktualisieren();
	if (this->eingabeverwaltung->getTastenStatusGeandertIndex(3) == true)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
