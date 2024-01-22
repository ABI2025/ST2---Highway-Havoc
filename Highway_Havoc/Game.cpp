#pragma once
#include "Game.hpp"
#include <iostream>

Game::Game(int fps, int tickrate)
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 360), "Highway Havoc");
	//this->window->setView(sf::View(sf::Vector2f(640/2, 360/2), sf::Vector2f(1920,1080)));	//	optional
	this->startbildschirm = new Startbildschirm(window);
<<<<<<< HEAD
	this->einstellungen = new Einstellungen(window);
=======
	this->map = new Map(window);
>>>>>>> 08746f29628e9b18de704d7bd582226c585b03c8
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

<<<<<<< HEAD
	if (this->zustaende.einstellungenAnzeigen == true)	//	Den Einstellungsbildschirm anzeigen, wenn gefordert
	{
		this->einstellungen->anzeigen();
=======
	if (this->zustaende.spielStarten == true) {
		map->zeichnen();
>>>>>>> 08746f29628e9b18de704d7bd582226c585b03c8
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

	if (this->zustaende.spielStarten == true) {
		this->map->aktualisieren();
	}

	if (this->zustaende.spielBeenden == true)			//	Spiel beenden, wenn gefordert
	{
		this->~Game();
		exit(0);
	}
	if (this->zustaende.einstellungenAnzeigen == true)							//Einstellungen werden geöffnet
	{
		einstellungen->aktualisieren();
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
																				//solange render nur Bilder wiedergibt ist  die Schleife nicht von Nöten
			//{
			this->render();
			//}
			frameLimitClock.restart().asMicroseconds();
		}
	}
}