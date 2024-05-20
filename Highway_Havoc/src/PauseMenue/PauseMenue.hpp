#pragma once
#include <SFML/Graphics.hpp>
#include "../EingabeVerwaltung/EingabeVerwaltung.hpp"
#include "../MusikVerwaltung/MusikVerwaltung.hpp"

class PauseMenue {
protected:
	short auswahl = 0;							//	Zeigt welche Option gerade ausgewählt ist (von oben nach unten durchnummeriert)
	bool auswahlGetroffen = false;				//	Ob die Momentan ausgewählte Auswahl bestätigt wurde
	sf::RenderWindow* window;					//	Pointer auf window, wird für die anzeigen-Methode benötigt
	sf::Font PixeboyFont;						//	Die Schriftart, die für die Textzüge genutz wird
	sf::Text spielStartText;					//	Textelement, das den "Spiel starten"-Schriftzug enthält
	sf::Text einstellungenOeffnenText;			//	Textelement, das den "Einstellungen"-Schriftzug enthält
	sf::Text spielBeendenText;					//	Textelement, das den "Spiel beenden"-Schriftzug enthält
	EingabeVerwaltung* eingabeverwaltung;		//	Eingabeverwaltung wird für die Steuerung benötigt
	MusikVerwaltung* musikverwaltung;
	sf::RectangleShape fensterHintergrund;

public:
	~PauseMenue();							//	Destruktor
	PauseMenue(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, MusikVerwaltung* musikverwaltung);	//	Konstruktor
	void anzeigen();							//	Zeichnet den Startbildschirm, wird in Game::render() aufgerufen
	void aktualisieren();						//	Aktualisiert die Auswahl
	short getAuswahl();
	bool getAuswahlGetroffen();
};