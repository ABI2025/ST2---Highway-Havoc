#pragma once
#include <iostream>
#include "SFML/Audio.hpp"
class MusikVerwaltung {
private:
	sf::Music musikStartbildschirm;
	sf::Music musikSpiel;

	sf::Music autoKollision;
	sf::Music menueHover;
	sf::Music menueKlick;
	sf::Music muenzeGesammelt;
	sf::Music levelverloren;
	sf::Music levelgeschafft;
	sf::Music spielerGestorben;

	int lautstaerke;
public:
	~MusikVerwaltung();
	MusikVerwaltung();
	void musikStartbildschirmStarten();
	void musikSpielStarten();
	void musikStoppen();
	void setLautstaerke(int lautstaerke);
	void musikAutoKollisionStarten();
	void musikMenueHoverStarten();
	void musikMenueKlickStarten();
	void musikMuenzeGesammeltStarten();
	void musikLevelverlorenStarten();
	void musikLevelgeschafftStarten();
	void musikSpielerGestorbenStarten();
};