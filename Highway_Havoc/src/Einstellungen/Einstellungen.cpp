#include "Einstellungen.hpp"
#include <iostream>

Einstellungen::~Einstellungen() { }

Einstellungen::Einstellungen(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung) //, sf::Music* musik
{
	this->window = window;
	//this->musik = musik;
	//this->musikStartbildschirm = musikStartbildschirm;
	this->eingabeverwaltung = eingabeverwaltung;
	if (!this->PixeboyFont.loadFromFile("./res/schriftarten/Pixeboy-z8XGD.ttf"))						//	L�d die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss sp�ter im selben Verzeichniss sein wie die ausf�rbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/schriftarten/Pixeboy-z8XGD.ttf)" << std::endl;
	}
	
	this->titelText.setFont(PixeboyFont);											//	Parameter und Position von den Schriftz�gen setzen
	this->titelText.setFillColor(sf::Color::White);
	this->titelText.setOutlineColor(sf::Color::White);
	this->titelText.setCharacterSize(60);
	this->titelText.setLetterSpacing(1);
	this->titelText.setString("Einstellungen");
	this->titelText.setPosition({ window->getSize().x / 2 - titelText.getGlobalBounds().width / 2, 0 });


	this->lautst�rkeText.setFont(PixeboyFont);
	this->lautst�rkeText.setFillColor(sf::Color::White);
	this->lautst�rkeText.setOutlineColor(sf::Color::White);
	this->lautst�rkeText.setCharacterSize(30);
	this->lautst�rkeText.setLetterSpacing(1);
	this->lautst�rkeText.setString("Lautstaerke");
	this->lautst�rkeText.setPosition({ window->getSize().x / 2 - lautst�rkeText.getGlobalBounds().width / 2, 60 });

	this->lautst�rkeLeiserText.setFont(PixeboyFont);
	this->lautst�rkeLeiserText.setFillColor(sf::Color::White);
	this->lautst�rkeLeiserText.setOutlineColor(sf::Color::White);
	this->lautst�rkeLeiserText.setCharacterSize(20);
	this->lautst�rkeLeiserText.setLetterSpacing(1);
	this->lautst�rkeLeiserText.setString("Leiser");
	this->lautst�rkeLeiserText.setPosition({ (window->getSize().x / 2 - lautst�rkeText.getGlobalBounds().width / 2) - 20, 90 });

	this->lautst�rkeLauterText.setFont(PixeboyFont);
	this->lautst�rkeLauterText.setFillColor(sf::Color::White);
	this->lautst�rkeLauterText.setOutlineColor(sf::Color::White);
	this->lautst�rkeLauterText.setCharacterSize(20);
	this->lautst�rkeLauterText.setLetterSpacing(1);
	this->lautst�rkeLauterText.setString("Lauter");
	this->lautst�rkeLauterText.setPosition({ (window->getSize().x / 2 - lautst�rkeText.getGlobalBounds().width / 2) + 120, 90 });

	this->lautst�rkeWertText.setFont(PixeboyFont);
	this->lautst�rkeWertText.setFillColor(sf::Color::White);
	this->lautst�rkeWertText.setOutlineColor(sf::Color::White);
	this->lautst�rkeWertText.setCharacterSize(20);
	this->lautst�rkeWertText.setLetterSpacing(1);
	this->lautst�rkeWertText.setString(std::to_string(laustaerkeWert));
	this->lautst�rkeWertText.setPosition({ (window->getSize().x / 2 - lautst�rkeText.getGlobalBounds().width / 2) + 70, 90 });


	this->fpsText.setFont(PixeboyFont);
	this->fpsText.setFillColor(sf::Color::White);
	this->fpsText.setOutlineColor(sf::Color::White);
	this->fpsText.setCharacterSize(30);
	this->fpsText.setLetterSpacing(1);
	this->fpsText.setString("Fps");
	this->fpsText.setPosition({ window->getSize().x / 2 - fpsText.getGlobalBounds().width / 2, 130 });

	this->fpsWenigerText.setFont(PixeboyFont);
	this->fpsWenigerText.setFillColor(sf::Color::White);
	this->fpsWenigerText.setOutlineColor(sf::Color::White);
	this->fpsWenigerText.setCharacterSize(20);
	this->fpsWenigerText.setLetterSpacing(1);
	this->fpsWenigerText.setString("Weniger");
	this->fpsWenigerText.setPosition({ (window->getSize().x / 2 - lautst�rkeText.getGlobalBounds().width / 2) - 20, 160 });

	this->fpsMehrText.setFont(PixeboyFont);
	this->fpsMehrText.setFillColor(sf::Color::White);
	this->fpsMehrText.setOutlineColor(sf::Color::White);
	this->fpsMehrText.setCharacterSize(20);
	this->fpsMehrText.setLetterSpacing(1);
	this->fpsMehrText.setString("Mehr");
	this->fpsMehrText.setPosition({ (window->getSize().x / 2 - lautst�rkeText.getGlobalBounds().width / 2) + 120, 160 });

	this->fpsWertText.setFont(PixeboyFont);
	this->fpsWertText.setFillColor(sf::Color::White);
	this->fpsWertText.setOutlineColor(sf::Color::White);
	this->fpsWertText.setCharacterSize(20);
	this->fpsWertText.setLetterSpacing(1);
	this->fpsWertText.setString(std::to_string(fpsWert));
	this->fpsWertText.setPosition({ (window->getSize().x / 2 - lautst�rkeText.getGlobalBounds().width / 2) + 70, 160 });


	this->speichernText.setFont(PixeboyFont);
	this->speichernText.setFillColor(sf::Color::White);
	this->speichernText.setOutlineColor(sf::Color::White);
	this->speichernText.setCharacterSize(40);
	this->speichernText.setLetterSpacing(1);
	this->speichernText.setString("Speichern");
	this->speichernText.setPosition({ window->getSize().x / 2 - speichernText.getGlobalBounds().width / 2, 220 });


	//this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Up);				//	Die Tasten zum Steuern zur Beobachtungsliste, der Eingabeverwaltung, hinzuf�gen
	//this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Down);
	//this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Enter);
	//this->eingabeverwaltung->mausTasteHinzufuegen(sf::Mouse::Button::Left);
}

void Einstellungen::anzeigen()
{
	this->window->setView(sf::View(sf::Vector2f(this->window->getView().getSize().x / 2, this->window->getView().getSize().y / 2), sf::Vector2f(this->window->getView().getSize().x, this->window->getView().getSize().y)));
	this->window->clear(sf::Color(55, 166, 166, 255));								//	Hintergundfarbe setzten

	this->lautst�rkeWertText.setString(std::to_string(laustaerkeWert));				// Den momentaren Wert anzeigen
	this->fpsWertText.setString(std::to_string(fpsWert));							

	this->lautst�rkeLeiserText.setFillColor(sf::Color::White);	
	this->lautst�rkeLauterText.setFillColor(sf::Color::White);						//	Die Farbe der Momentan getroffenen Auswahl auf Rot setzten, den Rest auf Wei�
	this->fpsWenigerText.setFillColor(sf::Color::White);
	this->fpsMehrText.setFillColor(sf::Color::White);
	this->speichernText.setFillColor(sf::Color::White);
	if (this->auswahl == 0)
	{
		this->lautst�rkeLeiserText.setFillColor(sf::Color::Red);
	}
	if (this->auswahl == 1)
	{
		this->lautst�rkeLauterText.setFillColor(sf::Color::Red);
	}
	if (this->auswahl == 2)
	{
		this->fpsWenigerText.setFillColor(sf::Color::Red);
	}
	if (this->auswahl == 3)
	{
		this->fpsMehrText.setFillColor(sf::Color::Red);
	}
	if (this->auswahl == 4)
	{
		this->speichernText.setFillColor(sf::Color::Red);
	}

	this->window->draw(titelText);													//	Die Textelemente zeichenen
	this->window->draw(lautst�rkeText);
	this->window->draw(lautst�rkeLeiserText);
	this->window->draw(lautst�rkeLauterText);
	this->window->draw(lautst�rkeWertText);
	this->window->draw(fpsText);
	this->window->draw(fpsWenigerText);
	this->window->draw(fpsMehrText);
	this->window->draw(fpsWertText);
	this->window->draw(speichernText);
}

void Einstellungen::aktualisieren()
{
	this->eingabeverwaltung->aktualisieren();										//	Die Eingabeverwaltung aktualisieren
	bool benutztMaus = false;														//	Gibt an ob die Maus sich �ber einem Textfeld befindet
	this->auswahlGetroffen = false;													//	Zur�cksetzen von Auswahlgetroffen, da sonst ein Klickspam ensteht 

	if (this->eingabeverwaltung->getGruppenStatusGeaendert(0) && auswahl > 0) 	//	Die Eingabe �berpr�fen und die Auswahl anpassen
	{
		this->auswahl -= 1;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(2) && auswahl < 4) 	//	Die Eingabe �berpr�fen und die Auswahl anpassen
	{
		this->auswahl += 1;
	}
	//	Die Mausposition pr�fen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->lautst�rkeLeiserText.getGlobalBounds())) {
		this->auswahl = 0;
		benutztMaus = true;
	}																				//	Die Mausposition pr�fen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->lautst�rkeLauterText.getGlobalBounds())) {
		this->auswahl = 1;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->fpsWenigerText.getGlobalBounds())) {
		this->auswahl = 2;
		benutztMaus = true;
	}																				//	Die Mausposition pr�fen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->fpsMehrText.getGlobalBounds())) {
		this->auswahl = 3;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->speichernText.getGlobalBounds())) {
		this->auswahl = 4;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(4) == true			//	�berpr�fen ob die Auswahl getroffen wurde
		|| (this->eingabeverwaltung->getMausTastenStatusGeandertIndex(0) == true && benutztMaus == true))
	{

		if (this->auswahl == 0) this->lautsaerkeWertMinus(5);
		else if (this->auswahl == 1) this->lautsaerkeWertPlus(5);
		else if (this->auswahl == 2) this->fpsWertMinus(5);
		else if (this->auswahl == 3) this->fpsWertPlus(5);
		else if (this->auswahl == 4) this->auswahlGetroffen = true;
	}
}


short Einstellungen::getAuswahl() const
{
	return this->auswahl;
}

bool Einstellungen::getAuswahlGetroffen() const
{
	return this->auswahlGetroffen;
}

unsigned short Einstellungen::getFpsWert() const
{
	return this->fpsWert;
}

unsigned short Einstellungen::getLautstaerkeWert() const
{
	return this->laustaerkeWert;
}

void Einstellungen::setLaustaerkeWert(unsigned short wert)
{
	if (wert >= lautstaerkeMinWert && wert <= lautstaerkeMaxWert)laustaerkeWert = wert;
	else std::cout << "Fehler: Ung�ltiger Wert f�r Lautst�rke." << std::endl;
}

void Einstellungen::setFpsWert(unsigned short wert)
{
	if (wert >= fpsMinWert && wert <= fpsMaxWert) fpsWert = wert;
	else std::cout << "Fehler: Ung�ltiger Wert f�r FPS." << std::endl;
}

void Einstellungen::lautsaerkeWertPlus(unsigned short value)
{
	if (laustaerkeWert < lautstaerkeMaxWert)
	{
		laustaerkeWert += value;
		//musik->setVolume(laustaerkeWert);
		//musikStartbildschirm->setVolume(laustaerkeWert);
	}
}

void Einstellungen::lautsaerkeWertMinus(unsigned short value)
{
	if (laustaerkeWert > lautstaerkeMinWert)
	{
		laustaerkeWert -= value;
		//musik->setVolume(laustaerkeWert);
		//musikStartbildschirm->setVolume(laustaerkeWert);
	}
}

void Einstellungen::fpsWertPlus(unsigned short value)
{
	if (fpsWert < fpsMaxWert) fpsWert += value;
}

void Einstellungen::fpsWertMinus(unsigned short value)
{
	if (fpsWert > fpsMinWert) fpsWert -= value;
}




