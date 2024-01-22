#include "Game.hpp"
#include "Auto.hpp"
#include <iostream>
#pragma once

Game::Game(int fps, int tickrate)
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 360), "Highway Havoc");
	//this->window->setView(sf::View(sf::Vector2f(640/2, 360/2), sf::Vector2f(1920,1080)));	//	optional
	this->fps = fps;
	this->tickrate = tickrate;
}

Game::~Game()
{
	delete this->window;
	this->window = nullptr;
}

void Game::render()
{
	window->clear(sf::Color::Black);

	window->display();
}

void Game::tick() 
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window->close();
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

	while (window->isOpen()) 
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
			//{
				this->render();
			//}
			frameLimitClock.restart().asMicroseconds();
		}
	}
}