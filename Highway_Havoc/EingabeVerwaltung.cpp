#pragma once
#include "EingabeVerwaltung.hpp"
#include <iostream>
EingabeVerwaltung::~EingabeVerwaltung()
{
}

EingabeVerwaltung::EingabeVerwaltung()
{
}

void EingabeVerwaltung::aktualisieren()
{
	std::list<sf::Keyboard::Key>::iterator tastenIterator;
	std::list<bool>::iterator statusIterator;
	std::list<bool>::iterator statusGeaendertIterator;
	tastenIterator = this->tasten.begin();
	statusIterator = this->tastenStatus.begin();
	statusGeaendertIterator = this->tastenStatusGeaendert.begin();

	while (tastenIterator != this->tasten.end()) {
		if (sf::Keyboard::isKeyPressed(*tastenIterator)) {
			if (*statusIterator == false) {
				*statusGeaendertIterator = true;
			}
			else {
				*statusGeaendertIterator = false;
			}
			*statusIterator = true;
		}
		else {
			*statusIterator = false;
			*statusGeaendertIterator = false;
		}
		tastenIterator++;
		statusIterator++;
		statusGeaendertIterator++;
	}
}

void EingabeVerwaltung::tasteHinzufuegen(sf::Keyboard::Key taste)
{
	this->tasten.push_back(taste);
	this->tastenStatus.push_back(false);
	this->tastenStatusGeaendert.push_back(false);
}

const std::list<sf::Keyboard::Key>* EingabeVerwaltung::getTastenPtr()
{
	return &this->tasten;
}

const std::list<bool>* EingabeVerwaltung::getTastenStatusPtr()
{
	return &this->tastenStatus;
}

const std::list<bool>* EingabeVerwaltung::getTastenStatusGeaendertPtr()
{
	return &this->tastenStatusGeaendert;
}

sf::Keyboard::Key EingabeVerwaltung::getTastenIndex(short index)
{
	std::list<sf::Keyboard::Key>::iterator tastenIterator;
	tastenIterator = this->tasten.begin();
	std::advance(tastenIterator, index);
	return *tastenIterator;
}

bool EingabeVerwaltung::getTastenStatusIndex(short index)
{
	std::list<bool>::iterator statusIterator;
	statusIterator = this->tastenStatus.begin();
	std::advance(statusIterator, index);
	return *statusIterator;
}

bool EingabeVerwaltung::getTastenStatusGeandertIndex(short index)
{
	std::list<bool>::iterator statusGeaendertIterator;
	statusGeaendertIterator = this->tastenStatusGeaendert.begin();
	std::advance(statusGeaendertIterator, index);
	return *statusGeaendertIterator;
}
