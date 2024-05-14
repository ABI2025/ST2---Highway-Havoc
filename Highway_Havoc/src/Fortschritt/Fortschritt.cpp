#pragma once
#include "Fortschritt.hpp"

void Fortschritt::setGeld(int geld)
{
	this->geld = geld;
}

int Fortschritt::getGeld()
{
	return this->geld;
}

void Fortschritt::setLevelFreigeschaltet(int levelFreigeschaltet)
{
	this->levelFreigeschaltet = levelFreigeschaltet;
}

int Fortschritt::getLevelFreigeschaltet()
{
	return this->levelFreigeschaltet;
}

void Fortschritt::setAutoFreigeschaltet(int autoFreigeschaltet)
{
	this->autoFreigeschaltet = autoFreigeschaltet;
}

int Fortschritt::getAutoFreigeschaltet()
{
	return this->autoFreigeschaltet;
}

bool Fortschritt::fortschrittSpeichern()
{
	char pfad[29] = "higwayhavoc_fortschritt";
	pfad[23] = (char)this->spielstand + 48;
	pfad[24] = '.'; pfad[25] = 'd'; pfad[26] = 'a'; pfad[27] = 't';
	std::fstream datei(pfad, std::ios::out | std::ios::binary);
	if (!datei) {
		std::cout << "Fehler beim Öffnen von " << pfad << std::endl;
		return false;
	}
	datei.write((char*)&this->geld, sizeof(int));
	datei.write((char*)&this->levelFreigeschaltet, sizeof(int));
	datei.write((char*)&this->autoFreigeschaltet, sizeof(int));
	datei.close();
	return true;
}

bool Fortschritt::fortschrittLaden()
{
	char pfad[29] = "higwayhavoc_fortschritt";
	pfad[23] = (char)this->spielstand + 48;
	pfad[24] = '.'; pfad[25] = 'd'; pfad[26] = 'a'; pfad[27] = 't';
	std::fstream datei(pfad, std::ios::in | std::ios::binary);
	if (!datei) {
		std::cout << "Fehler beim Öffnen von " << pfad << std::endl;
		this->geld = 0;
		this->levelFreigeschaltet = 0;
		this->autoFreigeschaltet = 0;
		this->fortschrittSpeichern();
		return false;
	}
	datei.read((char*)&this->geld, sizeof(int));
	datei.read((char*)&this->levelFreigeschaltet, sizeof(int));
	datei.read((char*)&this->autoFreigeschaltet, sizeof(int));
	datei.close();
	return true;
}

void Fortschritt::setSpielstand(int spielstand)
{
	this->spielstand = spielstand;
}

int Fortschritt::getSpielstand()
{
	return this->spielstand;
}