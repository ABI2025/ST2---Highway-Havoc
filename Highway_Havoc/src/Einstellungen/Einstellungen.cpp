#include "Einstellungen.hpp"
#include <iostream>

Einstellungen::~Einstellungen() { }

Einstellungen::Einstellungen(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung) //, sf::Music* musik
{
	this->window = window;
	//this->musik = musik;
	//this->musikStartbildschirm = musikStartbildschirm;
	this->eingabeverwaltung = eingabeverwaltung;
	if (!this->PixeboyFont.loadFromFile("./res/schriftarten/Pixeboy-z8XGD.ttf"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/schriftarten/Pixeboy-z8XGD.ttf)" << std::endl;
	}
	
	this->titelText.setFont(PixeboyFont);											//	Parameter und Position von den Schriftzügen setzen
	this->titelText.setFillColor(sf::Color::White);
	this->titelText.setOutlineColor(sf::Color::White);
	this->titelText.setCharacterSize(60);
	this->titelText.setLetterSpacing(1);
	this->titelText.setString("Einstellungen");
	this->titelText.setPosition({ window->getSize().x / 2 - titelText.getGlobalBounds().width / 2, 0 });


	this->lautstärkeText.setFont(PixeboyFont);
	this->lautstärkeText.setFillColor(sf::Color::White);
	this->lautstärkeText.setOutlineColor(sf::Color::White);
	this->lautstärkeText.setCharacterSize(30);
	this->lautstärkeText.setLetterSpacing(1);
	this->lautstärkeText.setString("Lautstaerke");
	this->lautstärkeText.setPosition({ window->getSize().x / 2 - lautstärkeText.getGlobalBounds().width / 2, 60 });

	this->lautstärkeLeiserText.setFont(PixeboyFont);
	this->lautstärkeLeiserText.setFillColor(sf::Color::White);
	this->lautstärkeLeiserText.setOutlineColor(sf::Color::White);
	this->lautstärkeLeiserText.setCharacterSize(20);
	this->lautstärkeLeiserText.setLetterSpacing(1);
	this->lautstärkeLeiserText.setString("Leiser");
	this->lautstärkeLeiserText.setPosition({ (window->getSize().x / 2 - lautstärkeText.getGlobalBounds().width / 2) - 20, 90 });

	this->lautstärkeLauterText.setFont(PixeboyFont);
	this->lautstärkeLauterText.setFillColor(sf::Color::White);
	this->lautstärkeLauterText.setOutlineColor(sf::Color::White);
	this->lautstärkeLauterText.setCharacterSize(20);
	this->lautstärkeLauterText.setLetterSpacing(1);
	this->lautstärkeLauterText.setString("Lauter");
	this->lautstärkeLauterText.setPosition({ (window->getSize().x / 2 - lautstärkeText.getGlobalBounds().width / 2) + 120, 90 });

	this->lautstärkeWertText.setFont(PixeboyFont);
	this->lautstärkeWertText.setFillColor(sf::Color::White);
	this->lautstärkeWertText.setOutlineColor(sf::Color::White);
	this->lautstärkeWertText.setCharacterSize(20);
	this->lautstärkeWertText.setLetterSpacing(1);
	this->lautstärkeWertText.setString(std::to_string(laustaerkeWert));
	this->lautstärkeWertText.setPosition({ (window->getSize().x / 2 - lautstärkeText.getGlobalBounds().width / 2) + 70, 90 });


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
	this->fpsWenigerText.setPosition({ (window->getSize().x / 2 - lautstärkeText.getGlobalBounds().width / 2) - 20, 160 });

	this->fpsMehrText.setFont(PixeboyFont);
	this->fpsMehrText.setFillColor(sf::Color::White);
	this->fpsMehrText.setOutlineColor(sf::Color::White);
	this->fpsMehrText.setCharacterSize(20);
	this->fpsMehrText.setLetterSpacing(1);
	this->fpsMehrText.setString("Mehr");
	this->fpsMehrText.setPosition({ (window->getSize().x / 2 - lautstärkeText.getGlobalBounds().width / 2) + 120, 160 });

	this->fpsWertText.setFont(PixeboyFont);
	this->fpsWertText.setFillColor(sf::Color::White);
	this->fpsWertText.setOutlineColor(sf::Color::White);
	this->fpsWertText.setCharacterSize(20);
	this->fpsWertText.setLetterSpacing(1);
	this->fpsWertText.setString(std::to_string(fpsWert));
	this->fpsWertText.setPosition({ (window->getSize().x / 2 - lautstärkeText.getGlobalBounds().width / 2) + 70, 160 });


	this->speichernText.setFont(PixeboyFont);
	this->speichernText.setFillColor(sf::Color::White);
	this->speichernText.setOutlineColor(sf::Color::White);
	this->speichernText.setCharacterSize(40);
	this->speichernText.setLetterSpacing(1);
	this->speichernText.setString("Speichern");
	this->speichernText.setPosition({ window->getSize().x / 2 - speichernText.getGlobalBounds().width / 2, 220 });


	//this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Up);				//	Die Tasten zum Steuern zur Beobachtungsliste, der Eingabeverwaltung, hinzufügen
	//this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Down);
	//this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Enter);
	//this->eingabeverwaltung->mausTasteHinzufuegen(sf::Mouse::Button::Left);
}

void Einstellungen::anzeigen()
{
	this->window->setView(sf::View(sf::Vector2f(this->window->getView().getSize().x / 2, this->window->getView().getSize().y / 2), sf::Vector2f(this->window->getView().getSize().x, this->window->getView().getSize().y)));
	this->window->clear(sf::Color(55, 166, 166, 255));								//	Hintergundfarbe setzten

	this->lautstärkeWertText.setString(std::to_string(laustaerkeWert));				// Den momentaren Wert anzeigen
	this->fpsWertText.setString(std::to_string(fpsWert));							

	this->lautstärkeLeiserText.setFillColor(sf::Color::White);	
	this->lautstärkeLauterText.setFillColor(sf::Color::White);						//	Die Farbe der Momentan getroffenen Auswahl auf Rot setzten, den Rest auf Weiß
	this->fpsWenigerText.setFillColor(sf::Color::White);
	this->fpsMehrText.setFillColor(sf::Color::White);
	this->speichernText.setFillColor(sf::Color::White);
	if (this->auswahl == 0)
	{
		this->lautstärkeLeiserText.setFillColor(sf::Color::Red);
	}
	if (this->auswahl == 1)
	{
		this->lautstärkeLauterText.setFillColor(sf::Color::Red);
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
	this->window->draw(lautstärkeText);
	this->window->draw(lautstärkeLeiserText);
	this->window->draw(lautstärkeLauterText);
	this->window->draw(lautstärkeWertText);
	this->window->draw(fpsText);
	this->window->draw(fpsWenigerText);
	this->window->draw(fpsMehrText);
	this->window->draw(fpsWertText);
	this->window->draw(speichernText);
}

void Einstellungen::aktualisieren()
{
	this->eingabeverwaltung->aktualisieren();										//	Die Eingabeverwaltung aktualisieren
	bool benutztMaus = false;														//	Gibt an ob die Maus sich über einem Textfeld befindet
	this->auswahlGetroffen = false;													//	Zurücksetzen von Auswahlgetroffen, da sonst ein Klickspam ensteht 

	if (this->eingabeverwaltung->getGruppenStatusGeaendert(0) && auswahl > 0) 	//	Die Eingabe überprüfen und die Auswahl anpassen
	{
		this->auswahl -= 1;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(2) && auswahl < 4) 	//	Die Eingabe überprüfen und die Auswahl anpassen
	{
		this->auswahl += 1;
	}
	//	Die Mausposition prüfen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->lautstärkeLeiserText.getGlobalBounds())) {
		this->auswahl = 0;
		benutztMaus = true;
	}																				//	Die Mausposition prüfen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->lautstärkeLauterText.getGlobalBounds())) {
		this->auswahl = 1;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->fpsWenigerText.getGlobalBounds())) {
		this->auswahl = 2;
		benutztMaus = true;
	}																				//	Die Mausposition prüfen und die Auswahl anpassen
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->fpsMehrText.getGlobalBounds())) {
		this->auswahl = 3;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->mausPositionInFlaeche(this->speichernText.getGlobalBounds())) {
		this->auswahl = 4;
		benutztMaus = true;
	}
	if (this->eingabeverwaltung->getGruppenStatusGeaendert(4) == true			//	Überprüfen ob die Auswahl getroffen wurde
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
	else std::cout << "Fehler: Ungültiger Wert für Lautstärke." << std::endl;
}

void Einstellungen::setFpsWert(unsigned short wert)
{
	if (wert >= fpsMinWert && wert <= fpsMaxWert) fpsWert = wert;
	else std::cout << "Fehler: Ungültiger Wert für FPS." << std::endl;
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




