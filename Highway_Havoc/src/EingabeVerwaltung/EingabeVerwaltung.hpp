#pragma once
#include <list>
#include "SFML/Graphics.hpp"

class EingabeVerwaltung 
{
private:
	std::list<sf::Keyboard::Key> tasten;				//	Liste der zu überprüfenden Tasten
	std::list<bool> tastenStatus;						//	Liste der Zustände (gedrückt oder nicht) der Tasten (über den Index identifizierbar)
	std::list<bool> tastenStatusGeaendert;				//	Liste in der gespeichert wird, ob der Status einer Taste sich von "nicht gedrückt" zu "gedrückt" ändert (über den Index identifizierbar)

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
	void tasteHinzufuegen(sf::Keyboard::Key taste);		//	Fügt eine Taste zum überprüfen hinzu (kann duch Indexnummer überprüft werden)
	void mausTasteHinzufuegen(sf::Mouse::Button taste);	//	Fügt eine Maustaste zum überprüfen hinzu (kann duch Indexnummer überprüft werden)
	bool mausPositionInFlaeche(sf::FloatRect flaeche);

	sf::Keyboard::Key getTastenIndex(short index);		//	Gibt die, mit der übergebenen index-Nummer assoziirte, Taste zurück
	bool getTastenStatusIndex(short index);				//	Gibt zurück ob die Taste mit der übergebenen index-Nummer allgemein gedrückt ist
	bool getTastenStatusGeandertIndex(short index);		//	Gibt zurück ob die Taste mit der übergebenen index-Nummer von nicht gedrück zu gedrückt gewechselt ist

	sf::Mouse::Button getMausTastenIndex(short index);	//	Gibt die, mit der übergebenen index-Nummer assoziirte, Mausaste zurück
	bool getMausTastenStatusIndex(short index);			//	Gibt zurück ob die Maustaste mit der übergebenen index-Nummer allgemein gedrückt ist
	bool getMausTastenStatusGeandertIndex(short index);	//	Gibt zurück ob die Maustaste mit der übergebenen index-Nummer von nicht gedrück zu gedrückt gewechselt ist
	sf::Vector2f getMausPosition();

	void gruppeHinzufuegen();
	void tasteZuGruppeHinzufuegen(short index, short indexInTasten);
	bool getGruppenStatus(short index);
	bool getGruppenStatusGeaendert(short index);
};