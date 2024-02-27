#pragma once
#include "Auto.hpp"

class Spieler : public Auto
{
private:
	bool tot;

public:
	Spieler(sf::RenderWindow* window, const char extLevel);
	~Spieler();

	bool getTot() const;

	void setTot(const char extTot);

	void aktualisieren(); 
	void anzeigen();
	void stirb();
	
};

