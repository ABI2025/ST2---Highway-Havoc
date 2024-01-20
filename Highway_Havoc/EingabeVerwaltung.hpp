#pragma once
#include <list>
#include "SFML/Graphics.hpp"

class EingabeVerwaltung {
private:
	std::list<sf::Keyboard::Key> tasten;				//	Liste der zu überprüfenden Tasten
	std::list<bool> tastenStatus;						//	Liste der Zustände (gedrückt oder nicht) der Tasten (über den Index identifizierbar)
	std::list<bool> tastenStatusGeaendert;				//	Liste in der gespeichert wird, ob der Status einer Taste sich von "nicht gedrückt" zu "gedrückt" ändert (über den Index identifizierbar)
public:
	~EingabeVerwaltung();								//	Destruktor
	EingabeVerwaltung();								//	Konstrucktor
	void aktualisieren();								//	Aktualisiert den "tastenStatus" sowie den "tastenStatusGeaendert"
	void tasteHinzufuegen(sf::Keyboard::Key taste);		//	Fügt eine Taste zum überprüfen hinzu (kann duch Indexnummer überprüft werden)

	sf::Keyboard::Key getTastenIndex(short index);		//	Gibt die, mit der übergebenen index-Nummer assoziirte, Taste zurück
	bool getTastenStatusIndex(short index);				//	Gibt zurück ob die Taste mit der übergebenen index-Nummer allgemein gedrückt ist
	bool getTastenStatusGeandertIndex(short index);		//	Gibt zurück ob die Taste mit der übergebenen index-Nummer von nicht gedrück zu gedrückt gewechselt ist
};



	//const std::list<sf::Keyboard::Key>* getTastenPtr(); //	hat momentan keinen Anwendungszweck
	//const std::list<bool>* getTastenStatusPtr();
	//const std::list<bool>* getTastenStatusGeaendertPtr();