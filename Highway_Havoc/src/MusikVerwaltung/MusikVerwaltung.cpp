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
	if (!this->autoKollision.openFromFile("./res/geraeusche/autoKollision.ogg")) {
		std::cout << "Fehler beim Laden der Musikdatei. (./res/geraeusche/autoKollision.ogg)" << std::endl;
	}
	if (!this->menueHover.openFromFile("./res/geraeusche/menueHover.ogg")) {
		std::cout << "Fehler beim Laden der Musikdatei. (./res/geraeusche/menueHover.ogg)" << std::endl;
	}
	if (!this->menueKlick.openFromFile("./res/geraeusche/menueKlick.ogg")) {
		std::cout << "Fehler beim Laden der Musikdatei. (./res/geraeusche/menueKlick.ogg)" << std::endl;
	}
	if (!this->muenzeGesammelt.openFromFile("./res/geraeusche/muenzeGesammelt.ogg")) {
		std::cout << "Fehler beim Laden der Musikdatei. (./res/geraeusche/muenzeGesammelt.ogg)" << std::endl;
	}
	if (!this->levelverloren.openFromFile("./res/geraeusche/levelverloren.ogg")) {
		std::cout << "Fehler beim Laden der Musikdatei. (./res/geraeusche/levelverloren.ogg)" << std::endl;
	}
	if (!this->levelgeschafft.openFromFile("./res/geraeusche/levelgeschafft.ogg")) {
		std::cout << "Fehler beim Laden der Musikdatei. (./res/geraeusche/levelgeschafft.ogg)" << std::endl;
	}
	if (!this->spielerGestorben.openFromFile("./res/geraeusche/spielerGestorben.ogg")) {
		std::cout << "Fehler beim Laden der Musikdatei. (./res/geraeusche/spielerGestorben.ogg)" << std::endl;
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

void MusikVerwaltung::musikAutoKollisionStarten()
{
	this->autoKollision.play();
}

void MusikVerwaltung::musikMenueHoverStarten()
{
	this->menueHover.play();
}

void MusikVerwaltung::musikMenueKlickStarten()
{
	this->menueKlick.play();
}

void MusikVerwaltung::musikMuenzeGesammeltStarten()
{
	this->muenzeGesammelt.play();
}

void MusikVerwaltung::musikLevelverlorenStarten()
{
	this->levelverloren.play();
}

void MusikVerwaltung::musikLevelgeschafftStarten()
{
	this->levelgeschafft.play();
}

void MusikVerwaltung::musikSpielerGestorbenStarten()
{
	this->spielerGestorben.play();
}