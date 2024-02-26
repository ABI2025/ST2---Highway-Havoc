#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "EingabeVerwaltung.hpp"
	class Einstellungen
	{
	private:
		short auswahl = 0;							//	Zeigt welche Option gerade ausgewählt ist (von oben nach unten durchnummeriert)
		bool auswahlGetroffen = false;				//	Ob die Momentan ausgewählte Auswahl bestätigt wurde
		sf::RenderWindow* window;					//	Pointer auf window, wird für die anzeigen-Methode benötigt
		sf::Music musik;
		sf::Font PixeboyFont;						//	Die Schriftart, die für die Textzüge genutz wird
		sf::Text titelText;							//	Textelement, das den Spieltitel enthält
		sf::Text lautstärkeText;					//	Textelement, das den "LautstärkeText"-Schriftzug enthält f.f.
		sf::Text lautstärkeLeiserText;					
		sf::Text lautstärkeLauterText;
		sf::Text lautstärkeWertText;
		sf::Text fpsText;
		sf::Text fpsWenigerText;
		sf::Text fpsMehrText;
		sf::Text fpsWertText;
		sf::Text speichernText;
		EingabeVerwaltung* eingabeverwaltung;		//	Eingabeverwaltung wird für die Steuerung benötigt

		unsigned short laustaerkeWert = 0;
		unsigned short lautstaerkeMinWert = 0;
		unsigned short lautstaerkeMaxWert = 100;

		unsigned short fpsWert = 60;
		unsigned short fpsMinWert = 10;
		unsigned short fpsMaxWert = 120;


	public:
		~Einstellungen();							//	Destruktor
		Einstellungen(sf::RenderWindow* window);	//	Konstruktor
		void anzeigen();							//	Zeichnet die Einstellungen, wird in Game::render() aufgerufen
		void aktualisieren();						//	Aktualisiert die Auswahl

		void playMusik(bool);

		short getAuswahl();
		bool getAuswahlGetroffen();
		unsigned short getFpsWert();

		void setLaustaerkeWert(unsigned short value);
		void setFpsWert(unsigned short value);

		void lautsaerkeWertPlus(unsigned short value);	// 
		void lautsaerkeWertMinus(unsigned short value);

		void fpsWertPlus(unsigned short value);
		void fpsWertMinus(unsigned short value);
	};

