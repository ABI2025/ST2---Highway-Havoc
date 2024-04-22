#pragma once
#include "MusikVerwaltung.hpp"

MusikVerwaltung::~MusikVerwaltung()
{
}

MusikVerwaltung::MusikVerwaltung()
{
	if (!this->musikStartbildschirm.openFromFile("./res/geraeusche/self.ogg")) {
		std::cout << "Fehler beim Laden der Musikdatei. (./res/geraeusche/self.ogg)" << std::endl;
	}
	if (!this->musikSpiel.openFromFile("./res/geraeusche/HintergrundMusik.ogg")) {
		std::cout << "Fehler beim Laden der Musikdatei. (./res/geraeusche/HintergrundMusik.ogg)" << std::endl;
	}
}

void MusikVerwaltung::musikStartbildschirmStarten()
{
	if (this->musikStartbildschirm.getStatus() != sf::SoundSource::Status::Playing) {
		this->musikStoppen();
		this->musikStartbildschirm.play();
	}
}

void MusikVerwaltung::musikSpielStarten()
{
	if (this->musikSpiel.getStatus() != sf::SoundSource::Status::Playing) {
		this->musikStoppen();
		this->musikSpiel.play();
	}
}

void MusikVerwaltung::musikStoppen()
{
	this->musikSpiel.stop();
	this->musikStartbildschirm.stop();
}

void MusikVerwaltung::setLautstaerke(int lautstaerke)
{
	this->lautstaerke = lautstaerke;
	this->musikSpiel.setVolume(lautstaerke);
	this->musikStartbildschirm.setVolume(lautstaerke);
}
