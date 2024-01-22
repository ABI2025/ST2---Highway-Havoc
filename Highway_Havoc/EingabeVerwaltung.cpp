#pragma once
#include "EingabeVerwaltung.hpp"
#include <iostream>
EingabeVerwaltung::~EingabeVerwaltung()
{
}

EingabeVerwaltung::EingabeVerwaltung()
{
	this->window = nullptr;
}

EingabeVerwaltung::EingabeVerwaltung(sf::RenderWindow* window)
{
	this->window = window;
}

void EingabeVerwaltung::aktualisieren()
{
	//	Tastatur aktualisieren
	std::list<sf::Keyboard::Key>::iterator tastenIterator;			//	Iteratoren für die Tastaturlisten erstellen und auf den Listenanfang setzten.
	std::list<bool>::iterator statusIterator;
	std::list<bool>::iterator statusGeaendertIterator;
	tastenIterator = this->tasten.begin();
 	statusIterator = this->tastenStatus.begin();
	statusGeaendertIterator = this->tastenStatusGeaendert.begin();

	while (tastenIterator != this->tasten.end())					//	Die "tasten"-Liste durchgehen
	{
		if (sf::Keyboard::isKeyPressed(*tastenIterator))			//	Wenn eine Taste gedrückt wird, werden entsprechend die "tastenStatus" und "tastenStatusGeaendert"-Listen aktualisiert.
		{
			if (*statusIterator == false) 
			{
				*statusGeaendertIterator = true;
			}
			else 
			{
				*statusGeaendertIterator = false;
			}
			*statusIterator = true;
		}
		else 
		{
			*statusIterator = false;
			*statusGeaendertIterator = false;
		}
		tastenIterator++;
		statusIterator++;
		statusGeaendertIterator++;
	}

	//	Maus aktualisieren
	std::list<sf::Mouse::Button>::iterator mausTastenIterator;		//	Iteratoren für die Tastaturlisten erstellen und auf den Listenanfang setzten.
	std::list<bool>::iterator mausTastenStatusIterator;
	std::list<bool>::iterator mausTastenStatusGeaendertIterator;
	mausTastenIterator = this->mausTasten.begin();
	mausTastenStatusIterator = this->mausTastenStatus.begin();
	mausTastenStatusGeaendertIterator = this->mausTastenStatusGeaendert.begin();

	while (mausTastenIterator != this->mausTasten.end())			//	Die "mausTasten"-Liste durchgehen
	{
		if (sf::Mouse::isButtonPressed(*mausTastenIterator))		//	Wenn eine Taste gedrückt wird, werden entsprechend die "mausTastenStatus" und "mausTastenStatusGeaendert"-Listen aktualisiert.
		{
			if (*mausTastenStatusIterator == false) 
			{
				*mausTastenStatusGeaendertIterator = true;
			}
			else 
			{
				*mausTastenStatusGeaendertIterator = false;
			}
			*mausTastenStatusIterator = true;
		}
		else 
		{
			*mausTastenStatusIterator = false;
			*mausTastenStatusGeaendertIterator = false;
		}
		mausTastenIterator++;
		mausTastenStatusIterator++;
		mausTastenStatusGeaendertIterator++;
	}
	if (this->window != nullptr) {									//	Mausposition aktualisieren
		sf::Vector2i pixelMausPosition = sf::Mouse::getPosition(*this->window);
		this->mausPosition = this->window->mapPixelToCoords(pixelMausPosition);
	}
}

void EingabeVerwaltung::tasteHinzufuegen(sf::Keyboard::Key taste)
{
	this->tasten.push_back(taste);							//	Für die übergebene Taste wird in jeder tastatur-Liste ein neuer Eintrag hinzugefügt.
	this->tastenStatus.push_back(false);
	this->tastenStatusGeaendert.push_back(false);
}

void EingabeVerwaltung::mausTasteHinzufuegen(sf::Mouse::Button taste)
{
	this->mausTasten.push_back(taste);						//	Für die übergebene Taste wird in jeder maus-Liste ein neuer Eintrag hinzugefügt.
	this->mausTastenStatus.push_back(false);
	this->mausTastenStatusGeaendert.push_back(false);
}

bool EingabeVerwaltung::mausPositionInFlaeche(sf::FloatRect flaeche)
{
	if (this->window == nullptr) {
		std::cout << "Für diese Funktion braucht die EingabeVerwaltung einen Pointer auf ein RenderWindow!" << std::endl;
		return false;
	}
	return flaeche.contains(mausPosition);
}

sf::Keyboard::Key EingabeVerwaltung::getTastenIndex(short index)
{
	std::list<sf::Keyboard::Key>::iterator tastenIterator;	//	Den Iterator erstellen und auf den Anfang der "tasten"-Liste setzen.
	tastenIterator = this->tasten.begin();
	std::advance(tastenIterator, index);					//	Den Iterator um den übergebenen Index nach vorne verschieben.
	return *tastenIterator;
}

bool EingabeVerwaltung::getTastenStatusIndex(short index)
{
	std::list<bool>::iterator statusIterator;				//	Den Iterator erstellen und auf den Anfang der "tastenStatus"-Liste setzen.
	statusIterator = this->tastenStatus.begin();
	std::advance(statusIterator, index);					//	Den Iterator um den übergebenen Index nach vorne verschieben.
	return *statusIterator;
}

bool EingabeVerwaltung::getTastenStatusGeandertIndex(short index)
{
	std::list<bool>::iterator statusGeaendertIterator;		//	Den Iterator erstellen und auf den Anfang der "tastenStatusGeaendert"-Liste setzen.
	statusGeaendertIterator = this->tastenStatusGeaendert.begin();
	std::advance(statusGeaendertIterator, index);			//	Den Iterator um den übergebenen Index nach vorne verschieben.
	return *statusGeaendertIterator;
}

sf::Mouse::Button EingabeVerwaltung::getMausTastenIndex(short index)
{
	std::list<sf::Mouse::Button>::iterator mausTastenIterator;
	mausTastenIterator = this->mausTasten.begin();
	std::advance(mausTastenIterator, index);
	return *mausTastenIterator;
}

bool EingabeVerwaltung::getMausTastenStatusIndex(short index)
{
	std::list<bool>::iterator mausTastenStatusIterator;
	mausTastenStatusIterator = this->mausTastenStatus.begin();
	std::advance(mausTastenStatusIterator, index);
	return *mausTastenStatusIterator;
}

bool EingabeVerwaltung::getMausTastenStatusGeandertIndex(short index)
{
	std::list<bool>::iterator mausTastenStatusGeaendertIterator;
	mausTastenStatusGeaendertIterator = this->mausTastenStatusGeaendert.begin();
	std::advance(mausTastenStatusGeaendertIterator, index);
	return *mausTastenStatusGeaendertIterator;
}

sf::Vector2f EingabeVerwaltung::getMausPosition()
{
	return this->mausPosition;
}
