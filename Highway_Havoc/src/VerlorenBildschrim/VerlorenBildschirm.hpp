#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../EingabeVerwaltung/EingabeVerwaltung.hpp"

class VerlorenBildschirm {
private:
	sf::RenderWindow* window;
	EingabeVerwaltung* eingabeverwaltung;
	sf::Font PixeboyFont;
	sf::Text nachricht;
	sf::Text aktzeptieren;
	sf::RectangleShape fensterHintergrund;
	bool auswahlGetroffen = false;
public:
	~VerlorenBildschirm();
	VerlorenBildschirm(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung);
	void aktualisieren();
	void anzeigen();
	bool getAuswahlGetroffen();
};