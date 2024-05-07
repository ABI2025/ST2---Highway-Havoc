#pragma once
#include <SFML/Graphics.hpp>
#include "../EingabeVerwaltung/EingabeVerwaltung.hpp"
#include "../Fortschritt/Fortschritt.hpp"


class Startbildschirm 
{
protected:
	short auswahlX = 0;							//	Zeigt welche Option gerade ausgewählt ist (von oben nach unten durchnummeriert)
	short auswahlY = 1;
	bool auswahlGetroffen = false;				//	Ob die Momentan ausgewählte Auswahl bestätigt wurde
	sf::RenderWindow* window;					//	Pointer auf window, wird für die anzeigen-Methode benötigt
	sf::Font PixeboyFont;						//	Die Schriftart, die für die Textzüge genutz wird
	sf::Text titelText;							//	Textelement, das den Spieltitel enthält
	sf::Text spielStartText;					//	Textelement, das den "Spiel starten"-Schriftzug enthält
	sf::Text einstellungenOeffnenText;			//	Textelement, das den "Einstellungen"-Schriftzug enthält
	sf::Text spielBeendenText;					//	Textelement, das den "Spiel beenden"-Schriftzug enthält
	EingabeVerwaltung* eingabeverwaltung;		//	Eingabeverwaltung wird für die Steuerung benötigt
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