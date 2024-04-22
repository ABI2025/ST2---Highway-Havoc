#pragma once
#include <iostream>
#include "SFML/Audio.hpp"
class MusikVerwaltung {
private:
	sf::Music musikStartbildschirm;
	sf::Music musikSpiel;
	int lautstaerke;
public:
	~MusikVerwaltung();
	MusikVerwaltung();
	void musikStartbildschirmStarten();
	void musikSpielStarten();
	void musikStoppen();
	void setLautstaerke(int lautstaerke);
};