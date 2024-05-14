#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "../EingabeVerwaltung/EingabeVerwaltung.hpp"

class Nachricht {
private:
	sf::RenderWindow* window;
	EingabeVerwaltung* eingabeverwaltung;
	sf::Font PixeboyFont;
	sf::Text nachrichtText;
	sf::Text aktzeptieren;
	sf::RectangleShape fensterHintergrund;
	bool auswahlGetroffen = false;
public:
	~Nachricht();
	Nachricht(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung,std::string nachrichtText, sf::Color umrandungsFarbe);
	void aktualisieren();
	void anzeigen();
	bool getAuswahlGetroffen();
};