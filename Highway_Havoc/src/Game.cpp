#pragma once
#include "Game.hpp"
#include <iostream>

Game::Game(int fps, int tickrate)
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 360), "Highway Havoc");
	this->eingabeverwaltung = new EingabeVerwaltung(window);
	this->startbildschirm = new Startbildschirm(window, eingabeverwaltung);
	this->einstellungen = new Einstellungen(window, eingabeverwaltung);
	this->levelauswahl = new LevelAuswahl(window, eingabeverwaltung);
	this->musikverwaltung = new MusikVerwaltung();
	this->fps = fps;
	this->tickrate = tickrate;
	this->event = new sf::Event();
	this->zustaende.startBildschirmAnzeigen = true;
	this->zustaende.startBildschirmLaeuft = true;
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Up);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::W);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Left);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::A);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Down);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::S);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Right);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::D);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Enter);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Space);
	this->eingabeverwaltung->tasteHinzufuegen(sf::Keyboard::Key::Escape);
	this->eingabeverwaltung->mausTasteHinzufuegen(sf::Mouse::Button::Left);
	this->eingabeverwaltung->gruppeHinzufuegen();
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(0, 0);
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(0, 1);
	this->eingabeverwaltung->gruppeHinzufuegen();
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(1, 2);
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(1, 3);
	this->eingabeverwaltung->gruppeHinzufuegen();
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(2, 4);
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(2, 5);
	this->eingabeverwaltung->gruppeHinzufuegen();
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(3, 6);
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(3, 7);
	this->eingabeverwaltung->gruppeHinzufuegen();
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(4, 8);
	this->eingabeverwaltung->tasteZuGruppeHinzufuegen(4, 9);

	this->zustaende.musikStartbildschirmSpielen = true;
}

Game::~Game()
{
	this->window->close();
	delete this->window;
	this->window = nullptr;
	delete this->startbildschirm;
	this->startbildschirm = nullptr;
	delete this->einstellungen;
	this->einstellungen = nullptr;
	delete this->event;
	this->event = nullptr;
}

void Game::render() {
	this->window->clear(sf::Color(0, 0, 0, 0));
	if (this->zustaende.startBildschirmAnzeigen) {
		this->startbildschirm->anzeigen();
	}
	if (this->zustaende.einstellungenAnzeigen) {
		this->einstellungen->anzeigen();
	}
	if (this->zustaende.spielAnzeigen) {
		this->levelauswahl->anzeigen();
	}
	this->window->display();
}

void Game::tick() {
	while (this->window->pollEvent(*this->event))
	{
		if (this->event->type == sf::Event::Closed) this->window->close();
	}

	if (this->zustaende.startBildschirmLaeuft) {
		this->startbildschirm->aktualisieren();
		if (this->startbildschirm->getAuswahlGetroffen()) {
			int auswahl = this->startbildschirm->getAuswahl();
			if (auswahl == 0) {
				this->zustaende.spielLaeuft = true;
				this->zustaende.spielAnzeigen = true;
				this->zustaende.musikStartbildschirmSpielen = false;
				this->zustaende.musikSpielSpielen = true;
			}
			else if (auswahl == 1) {
				this->zustaende.einstellungenLaeuft = true;
				this->zustaende.einstellungenAnzeigen = true;
				this->zustaende.einstellungenAufgerufenVon = 'S';
			}
			else if (auswahl == 2) {
				this->zustaende.programmBeenden = true;
			}
			this->zustaende.startBildschirmLaeuft = false;
			this->zustaende.startBildschirmAnzeigen = false;
		}
	}
	if (this->zustaende.einstellungenLaeuft) {
		this->einstellungen->aktualisieren();
		if (this->einstellungen->getAuswahlGetroffen()) {
			int auswahl = this->einstellungen->getAuswahl();
			if (auswahl == 4) {
				this->fps = this->einstellungen->getFpsWert();
				this->musikverwaltung->setLautstaerke(this->einstellungen->getLautstaerkeWert());

				this->zustaende.einstellungenLaeuft = false;
				this->zustaende.einstellungenAnzeigen = false;

				if (this->zustaende.einstellungenAufgerufenVon == 'S') {
					this->zustaende.startBildschirmLaeuft = true;
					this->zustaende.startBildschirmAnzeigen = true;
				}
				else if (this->zustaende.einstellungenAufgerufenVon == 'P') {
					this->zustaende.spielLaeuft = true;
					this->zustaende.spielAnzeigen = true;
				}
			}
		}
	}
	if (this->zustaende.spielLaeuft) {
		this->levelauswahl->aktualisieren();
		if (this->levelauswahl->getAuswahlGetroffen()) {
			unsigned short auswahl = this->levelauswahl->getAuswahl();
			if (auswahl == 0) {
				this->zustaende.spielLaeuft = false;
				this->zustaende.spielAnzeigen = false;
				this->zustaende.startBildschirmLaeuft = true;
				this->zustaende.startBildschirmAnzeigen = true;
				this->zustaende.musikStartbildschirmSpielen = true;
				this->zustaende.musikSpielSpielen = false;
			}
		}
		if (this->levelauswahl->getUnterbrechung()) {
			int unterbrechungsgrund = this->levelauswahl->getUnterbrechungsgrund();
			if (unterbrechungsgrund == 0) {
				this->zustaende.spielLaeuft = false;
				this->zustaende.spielAnzeigen = false;
				this->zustaende.einstellungenAnzeigen = true;
				this->zustaende.einstellungenLaeuft = true;
				this->zustaende.einstellungenAufgerufenVon = 'P';
			}
		}
	}
	if (this->zustaende.musikStartbildschirmSpielen) this->musikverwaltung->musikStartbildschirmStarten();
	if (this->zustaende.musikSpielSpielen) this->musikverwaltung->musikSpielStarten();

	if (zustaende.programmBeenden) {
		this->~Game();
		exit(0);
	}
}

void Game::start()
{
	sf::Clock tickLimitClock;													//	braucht man zum Zeit messen
	double zeitSeitLetztemTick = tickLimitClock.restart().asMicroseconds();		//	Variable in der die Zeit seit dem letzten Tick (Gamelogic) speichert
	double deltaTickZeit = ((double)1 / (double)tickrate) * (double)1000000;	//	die Zeit, die zwischen zwei Ticks eigehalten werden muss (in Microsekunden)

	sf::Clock frameLimitClock;													//	braucht man zum Zeit messen
	double zeitSeitLetztemFrame = frameLimitClock.restart().asMicroseconds();	//	Variable in der die Zeit seit dem letzten Frame (Rendering) speichert
	double deltaFrameZeit = ((double)1 / (double)fps) * (double)1000000;		//	die Zeit, die zwischen zwei Frames eigehalten werden muss (in Microsekunden)

	while (this->window->isOpen())
	{
		//	tick (Ruft die "tick-Methode" annähernd so oft pro Sekunde auf wie es in "tickrate" steht.)
		zeitSeitLetztemTick = tickLimitClock.getElapsedTime().asMicroseconds();
		if (zeitSeitLetztemTick >= deltaTickZeit)
		{
			for (int i = 0; (zeitSeitLetztemTick - deltaTickZeit * i) >= deltaTickZeit; i++)
			{
				this->tick();
			}
			tickLimitClock.restart().asMicroseconds();
		}

		//	render (Ruft die "render-Methode" annähernd so oft pro Sekunde auf wie es in "fps" steht.)
		zeitSeitLetztemFrame = frameLimitClock.getElapsedTime().asMicroseconds();
		if (zeitSeitLetztemFrame >= deltaFrameZeit)
		{
			//for (int i = 0; (zeitSeitLetztemFrame - deltaFrameZeit * i) >= zeitSeitLetztemFrame; i++)
																				//	solange render nur Bilder wiedergibt ist  die Schleife nicht von Nöten
			//{
			this->render();
			//}
			frameLimitClock.restart().asMicroseconds();
		}
		deltaFrameZeit = ((double)1 / (double)fps) * (double)1000000;			//	Wird in der Schleife berechnet, um die Bildwiederholungrate zur Laufzeit anpassen zu können
		deltaTickZeit = ((double)1 / (double)tickrate) * (double)1000000;
	}
}