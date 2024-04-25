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
	std::fstream datei("higwayhavoc_fortschritt.dat", std::ios::out | std::ios::binary);
	if (!datei) {
		std::cout << "Fehler beim Öffnen von higwayhavoc_fortschritt.dat" << std::endl;
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
	std::fstream datei("higwayhavoc_fortschritt.dat", std::ios::in | std::ios::binary);
	if (!datei) {
		std::cout << "Fehler beim Öffnen von higwayhavoc_fortschritt.dat" << std::endl;
		return false;
	}
	datei.read((char*)&this->geld, sizeof(int));
	datei.read((char*)&this->levelFreigeschaltet, sizeof(int));
	datei.read((char*)&this->autoFreigeschaltet, sizeof(int));
	datei.close();
	return true;
}
