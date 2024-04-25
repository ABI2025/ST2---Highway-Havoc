#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Fortschritt {
private:
	int geld = 0;
	int levelFreigeschaltet = 1;
	int autoFreigeschaltet = 1;
public:
	void setGeld(int geld);
	int getGeld();
	void setLevelFreigeschaltet(int levelFreigeschaltet);
	int getLevelFreigeschaltet();
	void setAutoFreigeschaltet(int autoFreigeschaltet);
	int getAutoFreigeschaltet();
	bool fortschrittSpeichern();
	bool fortschrittLaden();
};