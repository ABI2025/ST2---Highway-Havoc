#pragma once
#include <SFML/Graphics.hpp>
#include "../EingabeVerwaltung/EingabeVerwaltung.hpp"
#include "../Fortschritt/Fortschritt.hpp"


class Startbildschirm 
{
protected:
	short auswahlX = 0;							//	Zeigt welche Option gerade ausgew�hlt ist (von oben nach unten durchnummeriert)
	short auswahlY = 1;
	bool auswahlGetroffen = false;				//	Ob die Momentan ausgew�hlte Auswahl best�tigt wurde
	sf::RenderWindow* window;					//	Pointer auf window, wird f�r die anzeigen-Methode ben�tigt
	sf::Font PixeboyFont;						//	Die Schriftart, die f�r die Textz�ge genutz wird
	sf::Text titelText;							//	Textelement, das den Spieltitel enth�lt
	sf::Text spielStartText;					//	Textelement, das den "Spiel starten"-Schriftzug enth�lt
	sf::Text einstellungenOeffnenText;			//	Textelement, das den "Einstellungen"-Schriftzug enth�lt
	sf::Text spielBeendenText;					//	Textelement, das den "Spiel beenden"-Schriftzug enth�lt
	EingabeVerwaltung* eingabeverwaltung;		//	Eingabeverwaltung wird f�r die Steuerung ben�tigt
	sf::Texture autoTextur;
	sf::Sprite autoSprite;

	Fortschritt* fortschritt;
	char spielStartenCString[16] = "Speicherstand  ";
	sf::Text speicherstandHoch;
	sf::Text speicherstandRunter;
public:
	~Startbildschirm();							//	Destruktor
	Startbildschirm(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, Fortschritt* fortschritt);	//	Konstruktor
	void anzeigen();							//	Zeichnet den Startbildschirm, wird in Game::render() aufgerufen
	void aktualisieren();						//	Aktualisiert die Auswahl
	short getAuswahlX();
	short getAuswahlY();
	bool getAuswahlGetroffen();
};