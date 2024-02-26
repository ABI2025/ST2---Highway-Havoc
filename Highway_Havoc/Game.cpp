#pragma once
#include "Game.hpp"
#include <iostream>

Game::Game(int fps, int tickrate)
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 360), "Highway Havoc");
	//this->window->setView(sf::View(sf::Vector2f(640/2, 360/2), sf::Vector2f(1920,1080)));	//	optional
	test_spieler = new Spieler(window,'1');
	this->startbildschirm = new Startbildschirm(window);
	this->einstellungen = new Einstellungen(window);
	this->map = new Map(window);
	this->zustaende.startbildschirmAnzeigen = true;
	this->fps = fps;
	this->tickrate = tickrate;
}

Game::~Game()
{
	this->window->close();
	delete this->window;
	this->window = nullptr;
}

void Game::render()
{
	this->window->clear(sf::Color::Black);

	if (this->zustaende.startbildschirmAnzeigen == true)	//	Den Startbildschirm anzeigen, wenn gefordert
	{
		this->startbildschirm->anzeigen();
	}

	if (this->zustaende.einstellungenAnzeigen == true)		//	Den Einstellungsbildschirm anzeigen, wenn gefordert
	{
		this->einstellungen->anzeigen();
	}
	

	if (this->zustaende.spielStarten == true)				//	Die Map anzeigen, wenn gefordert
	{
		map->zeichnen();
		test_spieler->anzeigen();
	} 

	this->window->display();
}

void Game::tick()
{
	//	Wird von SFML erfordert
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) this->window->close();
	}
	

	if (this->zustaende.startbildschirmAnzeigen == true)	//	Den Startbildschirm updaten und auslesen, wenn gefordert
	{
		this->startbildschirm->aktualisieren();
		if (this->startbildschirm->getAuswahlGetroffen())
		{
			switch (this->startbildschirm->getAuswahl())
			{
			case 0:
				this->zustaende.spielStarten = true;
				this->zustaende.startbildschirmAnzeigen = false;
				break;
			case 1:
				this->zustaende.einstellungenAnzeigen = true;
				this->zustaende.startbildschirmAnzeigen = false;
				break;
			case 2:
				this->zustaende.spielBeenden = true;
				this->zustaende.startbildschirmAnzeigen = false;
				break;
			}
		}
	}

	if (this->zustaende.einstellungenAnzeigen == true)	//	Die Einstellungen updaten und auslesen, wenn gefordert
	{
		this->einstellungen->aktualisieren();
		this->einstellungen->playMusik(true);
		if (this->einstellungen->getAuswahlGetroffen())
		{
			switch (this->einstellungen->getAuswahl())
			{
			case 0:										//	Lautstärke anpassen
				einstellungen->lautsaerkeWertMinus(5);
				break;
			case 1:
				einstellungen->lautsaerkeWertPlus(5);
				break;
			case 2:
				einstellungen->fpsWertMinus(5);
				this->fps = einstellungen->getFpsWert();//	Bildwiederholungsrate anpassen
				break;
			case 3:
				einstellungen->fpsWertPlus(5);
				this->fps = einstellungen->getFpsWert();
				break;
			case 4:
				this->zustaende.einstellungenAnzeigen = false;
				this->zustaende.startbildschirmAnzeigen = true;
				break;
			}
		}
	}

	if (this->zustaende.spielStarten == true) {
		this->map->aktualisieren();
		test_spieler->aktualisieren();
	}

	if (this->zustaende.spielBeenden == true)			//	Spiel beenden, wenn gefordert
	{
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