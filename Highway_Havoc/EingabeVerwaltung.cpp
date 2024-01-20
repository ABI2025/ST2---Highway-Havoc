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
	std::list<sf::Keyboard::Key>::iterator tastenIterator;			//	Iteratoren für die Listen erstellen und auf den Listenanfang setzten.
	std::list<bool>::iterator statusIterator;
	std::list<bool>::iterator statusGeaendertIterator;
	tastenIterator = this->tasten.begin();
	statusIterator = this->tastenStatus.begin();
	statusGeaendertIterator = this->tastenStatusGeaendert.begin();

	while (tastenIterator != this->tasten.end())					//	Die Listen durchgehen
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
}

void EingabeVerwaltung::tasteHinzufuegen(sf::Keyboard::Key taste)
{
	this->tasten.push_back(taste);							//	Für die übergebene Taste wird in jeder Liste ein neuer Eintrag hinzugefügt.
	this->tastenStatus.push_back(false);
	this->tastenStatusGeaendert.push_back(false);
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



//const std::list<sf::Keyboard::Key>* EingabeVerwaltung::getTastenPtr()		//	besitzt momentan keinen Anwendungszweck
//{
//	return &this->tasten;
//}
//
//const std::list<bool>* EingabeVerwaltung::getTastenStatusPtr()
//{
//	return &this->tastenStatus;
//}
//
//const std::list<bool>* EingabeVerwaltung::getTastenStatusGeaendertPtr()
//{
//	return &this->tastenStatusGeaendert;
//}