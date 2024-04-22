#pragma once
static class Level {
public:
	virtual ~Level() {

	}
	virtual void aktualisieren() = 0;
	virtual void anzeigen() = 0;
	virtual bool getUnterbrechung() = 0;
	virtual int getUnterbrechungsgrund() = 0;
};