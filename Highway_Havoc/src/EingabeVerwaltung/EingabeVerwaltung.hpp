#pragma once
#include <list>
#include "SFML/Graphics.hpp"

class EingabeVerwaltung 
{
private:
	std::list<sf::Keyboard::Key> tasten;				//	Liste der zu �berpr�fenden Tasten
	std::list<bool> tastenStatus;						//	Liste der Zust�nde (gedr�ckt oder nicht) der Tasten (�ber den Index identifizierbar)
	std::list<bool> tastenStatusGeaendert;				//	Liste in der gespeichert wird, ob der Status einer Taste sich von "nicht gedr�ckt" zu "gedr�ckt" �ndert (�ber den Index identifizierbar)

	std::list<sf::Mouse::Button> mausTasten;
	std::list<bool> mausTastenStatus;
	std::list<bool> mausTastenStatusGeaendert;
	sf::Vector2f mausPosition;

	std::vector<std::vector<bool*>*> gruppenStatus;
	std::vector<std::vector<bool*>*> gruppenStatusGeaendert;

	sf::RenderWindow* window;
public:
	~EingabeVerwaltung();								//	Destruktor
	EingabeVerwaltung();								//	Konstrucktor
	EingabeVerwaltung(sf::RenderWindow* window);
	void aktualisieren();								//	Aktualisiert den "tastenStatus" sowie den "tastenStatusGeaendert"
	void tasteHinzufuegen(sf::Keyboard::Key taste);		//	F�gt eine Taste zum �berpr�fen hinzu (kann duch Indexnummer �berpr�ft werden)
	void mausTasteHinzufuegen(sf::Mouse::Button taste);	//	F�gt eine Maustaste zum �berpr�fen hinzu (kann duch Indexnummer �berpr�ft werden)
	bool mausPositionInFlaeche(sf::FloatRect flaeche);

	sf::Keyboard::Key getTastenIndex(short index);		//	Gibt die, mit der �bergebenen index-Nummer assoziirte, Taste zur�ck
	bool getTastenStatusIndex(short index);				//	Gibt zur�ck ob die Taste mit der �bergebenen index-Nummer allgemein gedr�ckt ist
	bool getTastenStatusGeandertIndex(short index);		//	Gibt zur�ck ob die Taste mit der �bergebenen index-Nummer von nicht gedr�ck zu gedr�ckt gewechselt ist

	sf::Mouse::Button getMausTastenIndex(short index);	//	Gibt die, mit der �bergebenen index-Nummer assoziirte, Mausaste zur�ck
	bool getMausTastenStatusIndex(short index);			//	Gibt zur�ck ob die Maustaste mit der �bergebenen index-Nummer allgemein gedr�ckt ist
	bool getMausTastenStatusGeandertIndex(short index);	//	Gibt zur�ck ob die Maustaste mit der �bergebenen index-Nummer von nicht gedr�ck zu gedr�ckt gewechselt ist
	sf::Vector2f getMausPosition();

	void gruppeHinzufuegen();
	void tasteZuGruppeHinzufuegen(short index, short indexInTasten);
	bool getGruppenStatus(short index);
	bool getGruppenStatusGeaendert(short index);
};