#pragma once
#include <list>
#include "SFML/Graphics.hpp"

class EingabeVerwaltung {
private:
	std::list<sf::Keyboard::Key> tasten;				//	Liste der zu �berpr�fenden Tasten
	std::list<bool> tastenStatus;						//	Liste der Zust�nde (gedr�ckt oder nicht) der Tasten (�ber den Index identifizierbar)
	std::list<bool> tastenStatusGeaendert;				//	Liste in der gespeichert wird, ob der Status einer Taste sich von "nicht gedr�ckt" zu "gedr�ckt" �ndert (�ber den Index identifizierbar)
public:
	~EingabeVerwaltung();								//	Destruktor
	EingabeVerwaltung();								//	Konstrucktor
	void aktualisieren();								//	Aktualisiert den "tastenStatus" sowie den "tastenStatusGeaendert"
	void tasteHinzufuegen(sf::Keyboard::Key taste);		//	F�gt eine Taste zum �berpr�fen hinzu (kann duch Indexnummer �berpr�ft werden)

	sf::Keyboard::Key getTastenIndex(short index);		//	Gibt die, mit der �bergebenen index-Nummer assoziirte, Taste zur�ck
	bool getTastenStatusIndex(short index);				//	Gibt zur�ck ob die Taste mit der �bergebenen index-Nummer allgemein gedr�ckt ist
	bool getTastenStatusGeandertIndex(short index);		//	Gibt zur�ck ob die Taste mit der �bergebenen index-Nummer von nicht gedr�ck zu gedr�ckt gewechselt ist
};



	//const std::list<sf::Keyboard::Key>* getTastenPtr(); //	hat momentan keinen Anwendungszweck
	//const std::list<bool>* getTastenStatusPtr();
	//const std::list<bool>* getTastenStatusGeaendertPtr();