#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Fortschritt {
private:
	int spielstand = 1;
	int geld = 0;
	int levelFreigeschaltet = 0;
	int autoFreigeschaltet = 0;
public:
	void setGeld(int geld);
	int getGeld();
	void setLevelFreigeschaltet(int levelFreigeschaltet);
	int getLevelFreigeschaltet();
	void setAutoFreigeschaltet(int autoFreigeschaltet);
	int getAutoFreigeschaltet();
	bool fortschrittSpeichern();
	bool fortschrittLaden();
	void setSpielstand(int spielstand);
	int getSpielstand();
};