#pragma once
#include "Game.hpp"
#include <iostream>

// Konstruktor für die Game-Klasse
Game::Game(int fps, int tickrate)
{
	// Initialisiere Fenster und Komponenten des Spiels
	this->window = new sf::RenderWindow(sf::VideoMode(640, 360), "Highway Havoc");
	this->eingabeverwaltung = new EingabeVerwaltung(window);
	this->fortschritt = new Fortschritt();
	this->musikverwaltung = new MusikVerwaltung();
	this->startbildschirm = new Startbildschirm(window, eingabeverwaltung, fortschritt, musikverwaltung);
	this->einstellungen = new Einstellungen(window, eingabeverwaltung, musikverwaltung);
	this->levelauswahl = new LevelAuswahl(window, eingabeverwaltung, fortschritt, musikverwaltung);

	// Initialisiere Framerate und Tickrate
	this->fps = fps;
	this->tickrate = tickrate;

	// Initialisiere Event-Objekt
	this->event = new sf::Event();

	// Initialisiere Zustände
	this->zustaende.startBildschirmAnzeigen = true;
	this->zustaende.startBildschirmLaeuft = true;

	// Füge Tasten zur Eingabeverwaltung hinzu
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

	// Erstelle und ordne Tasten zu Gruppen zu
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

// Destruktor für die Game-Klasse
Game::~Game()
{
	// Schließe und lösche alle Komponenten
	this->window->close();
	delete this->window;
	this->window = nullptr;
	delete this->eingabeverwaltung;
	this->eingabeverwaltung = nullptr;
	delete this->startbildschirm;
	this->startbildschirm = nullptr;
	delete this->einstellungen;
	this->einstellungen = nullptr;
	delete this->event;
	this->event = nullptr;
	delete this->levelauswahl;
	this->levelauswahl = nullptr;
	delete this->musikverwaltung;
	this->musikverwaltung = nullptr;
	delete this->fortschritt;
	this->fortschritt = nullptr;
}

// Render-Methode
void Game::render() {
	this->window->clear(sf::Color(0, 0, 0, 0));
	// Zeige den entsprechenden Bildschirm basierend auf dem aktuellen Zustand
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

// Tick-Methode für die Spiel-Logik
void Game::tick() {
	while (this->window->pollEvent(*this->event))
	{
		// Beende das Spiel, wenn das Fenster geschlossen wird
		if (this->event->type == sf::Event::Closed) this->window->close();
	}

	// Aktualisiere den Startbildschirm, falls aktiv
	if (this->zustaende.startBildschirmLaeuft) {
		this->startbildschirm->aktualisieren();
		if (this->startbildschirm->getAuswahlGetroffen()) {
			int auswahlX = this->startbildschirm->getAuswahlX();
			int auswahlY = this->startbildschirm->getAuswahlY();
			// Überprüfe die Auswahl und aktualisiere die Zustände entsprechend
			if (auswahlX == 0) {
				if (auswahlY == 1) {
					this->zustaende.spielLaeuft = true;
					this->zustaende.spielAnzeigen = true;
					this->zustaende.musikStartbildschirmSpielen = false;
					this->zustaende.musikSpielSpielen = true;
					this->zustaende.startBildschirmLaeuft = false;
					this->zustaende.startBildschirmAnzeigen = false;
				}
				else if (auswahlY == 0) {
					int spielstand = this->fortschritt->getSpielstand();
					if (spielstand > 1) {
						this->fortschritt->setSpielstand(spielstand - 1);
					}
				}
				else if (auswahlY == 2) {
					int spielstand = this->fortschritt->getSpielstand();
					if (spielstand < 3) {
						this->fortschritt->setSpielstand(spielstand + 1);
					}
				}
			}
			else if (auswahlX == 1) {
				this->zustaende.einstellungenLaeuft = true;
				this->zustaende.einstellungenAnzeigen = true;
				this->zustaende.einstellungenAufgerufenVon = 'S';
				this->zustaende.startBildschirmLaeuft = false;
				this->zustaende.startBildschirmAnzeigen = false;
			}
			else if (auswahlX == 2) {
				this->zustaende.programmBeenden = true;
			}
		}
	}

	// Aktualisiere die Einstellungen, falls aktiv
	if (this->zustaende.einstellungenLaeuft) {
		this->einstellungen->aktualisieren();
		if (this->einstellungen->getAuswahlGetroffen()) {
			int auswahlX = this->einstellungen->getAuswahlX();
			if (auswahlX == 2) {
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

	// Aktualisiere die Levelauswahl, falls aktiv
	if (this->zustaende.spielLaeuft) {
		this->levelauswahl->aktualisieren();
		if (this->levelauswahl->getAuswahlGetroffen()) {
			unsigned short auswahlY = this->levelauswahl->getAuswahlY();
			if (auswahlY == 0) {
				this->zustaende.spielLaeuft = false;
				this->zustaende.spielAnzeigen = false;
				this->zustaende.startBildschirmLaeuft = true;
				this->

					zustaende.startBildschirmAnzeigen = true;
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

	// Spiele die entsprechende Musik basierend auf dem aktuellen Zustand
	if (this->zustaende.musikStartbildschirmSpielen) this->musikverwaltung->musikStartbildschirmStarten();
	if (this->zustaende.musikSpielSpielen) this->musikverwaltung->musikSpielStarten();

	// Beende das Programm, falls der entsprechende Zustand gesetzt ist
	if (zustaende.programmBeenden) {
		this->~Game();
		exit(0);
	}
}

// Start-Methode für die Hauptspielschleife
void Game::start()
{
	// Initialisiere Timer für Tick- und Frame-Limits
	sf::Clock tickLimitClock;
	double zeitSeitLetztemTick = tickLimitClock.restart().asMicroseconds();
	double deltaTickZeit = ((double)1 / (double)tickrate) * (double)1000000;

	sf::Clock frameLimitClock;
	double zeitSeitLetztemFrame = frameLimitClock.restart().asMicroseconds();
	double deltaFrameZeit = ((double)1 / (double)fps) * (double)1000000;

	// Hauptspielschleife
	while (this->window->isOpen())
	{
		// Tick-Logik
		zeitSeitLetztemTick = tickLimitClock.getElapsedTime().asMicroseconds();
		if (zeitSeitLetztemTick >= deltaTickZeit)
		{
			for (int i = 0; (zeitSeitLetztemTick - deltaTickZeit * i) >= deltaTickZeit; i++)
			{
				this->tick();
			}
			tickLimitClock.restart().asMicroseconds();
		}

		// Render-Logik
		zeitSeitLetztemFrame = frameLimitClock.getElapsedTime().asMicroseconds();
		if (zeitSeitLetztemFrame >= deltaFrameZeit)
		{
			this->render();
			frameLimitClock.restart().asMicroseconds();
		}
		// Aktualisiere die Delta-Zeit-Werte für dynamische Anpassungen
		deltaFrameZeit = ((double)1 / (double)fps) * (double)1000000;
		deltaTickZeit = ((double)1 / (double)tickrate) * (double)1000000;
	}
}