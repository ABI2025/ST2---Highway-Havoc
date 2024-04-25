#pragma once
#include "Autoverwalter.hpp"

Autoverwalter::~Autoverwalter()
{
	for (int i = 0; i < this->botVector.size() - 0; i++) {
		delete this->botVector[i];
	}
	for (int i = 0; i < this->spielerVector.size(); i++) {
		delete this->spielerVector[i];
	}
}

Autoverwalter::Autoverwalter()
{
}

Autoverwalter::Autoverwalter(sf::RenderWindow* window, Map* map, EingabeVerwaltung* eingabeverwaltung)
{
	this->window = window;
	this->map = map;
	this->eingabeverwaltung = eingabeverwaltung;
}
void Autoverwalter::botHinzufuegen(Bot* bot)
{
	this->botVector.push_back(bot);
}
void Autoverwalter::botGenerieren(unsigned short anzahl, int typ)
{
	for (int i = 0; i < anzahl; i++) {
		Bot* bot_tmp = nullptr;
		bool kollidiert;
		int versuche = 0;
		int maxVersuche = 10;
		do {
			versuche++;
			kollidiert = false;
			if (typ == 1)bot_tmp = new Bot1(this->window);
			if (typ == 2)bot_tmp = new Bot2(this->window);
			sf::Vector2f position_tmp;
			//srand(rand());
			short fahrbahn = rand() % 3;
			if (fahrbahn == 0) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2) - (15.f * 6.4f), this->window->getView().getSize().y + bot_tmp->getGlobalBounds().height / 2);
			if (fahrbahn == 1) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2), this->window->getView().getSize().y + bot_tmp->getGlobalBounds().height / 2);
			if (fahrbahn == 2) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2) + (15.f * 6.4f), this->window->getView().getSize().y + bot_tmp->getGlobalBounds().height / 2);
			bot_tmp->setPos(position_tmp);
			for (int i = 0; i < botVector.size(); i++) {
				if (bot_tmp->kollidiert(botVector[i]->getGlobalBounds())) {
					delete bot_tmp;
					bot_tmp = nullptr;
					kollidiert = true;
					break;
				}
			}
		} while (kollidiert && (versuche < maxVersuche));
		if (bot_tmp != nullptr) botVector.push_back(bot_tmp);
	}
}
void Autoverwalter::botLevelGenerieren(unsigned short anzahl, unsigned short reihen, int typ)
{
	double yKoordinateMap = this->map->getMapViereck().getSize().y + this->map->getMapViereck().getPosition().y;
	double yAbstand = this->map->getMapViereck().getSize().y / reihen;
	for (int y = 0; y < reihen; y++) {
		for (int i = 0; i < anzahl; i++) {
			Bot* bot_tmp = nullptr;
			bool kollidiert;
			int versuche = 0;
			int maxVersuche = 10;
			do {
				versuche++;
				kollidiert = false;
				if (typ == 1)bot_tmp = new Bot1(this->window);
				if (typ == 2)bot_tmp = new Bot2(this->window);
				sf::Vector2f position_tmp;
				//srand(rand());
				short fahrbahn = rand() % 3;
				if (fahrbahn == 0) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2) - (15.f * 6.4f), yKoordinateMap + bot_tmp->getGlobalBounds().height / 2 - (yAbstand * y));
				if (fahrbahn == 1) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2), yKoordinateMap + bot_tmp->getGlobalBounds().height / 2 - (yAbstand * y));
				if (fahrbahn == 2) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2) + (15.f * 6.4f), yKoordinateMap + bot_tmp->getGlobalBounds().height / 2 - (yAbstand * y));
				bot_tmp->setPos(position_tmp);
				for (int i = 0; i < botVector.size(); i++) {
					if (bot_tmp->kollidiert(botVector[i]->getGlobalBounds())) {
						delete bot_tmp;
						bot_tmp = nullptr;
						kollidiert = true;
						break;
					}
				}
			} while (kollidiert && (versuche < maxVersuche));
			if (bot_tmp != nullptr) botVector.push_back(bot_tmp);
		}
	}
}
void Autoverwalter::botsAktualisieren()
{
	for (int i = 0; i < this->botVector.size(); i++) {
		this->botVector[i]->aktualisieren();
	}
	sf::FloatRect mapViereck = this->map->getMapViereck();
	for (int i = 0; i < this->botVector.size(); i++) {
		if (!this->botVector[i]->getGlobalBounds().intersects(mapViereck)) {
			std::vector<Bot*>::iterator loeschIterator = this->botVector.begin();
			std::advance(loeschIterator, i);
			this->botVector.erase(loeschIterator);
			i--;
		}
	}
}

void Autoverwalter::botsAnzeigen()
{
	for (int i = 0; i < this->botVector.size(); i++) {
		this->botVector[i]->anzeigen();
	}
}

void Autoverwalter::spielerHinzufuegen(Spieler* spieler)
{
	this->spielerVector.push_back(spieler);
	for (int i = 0; i < this->botVector.size(); i++) {
		if (Collision::pixelPerfectTest(*this->spielerVector[this->spielerVector.size() - 1]->getSprite(), *this->botVector[i]->getSprite(), 177)) {
			std::vector<Bot*>::iterator loeschIterator = this->botVector.begin();
			std::advance(loeschIterator, i);
			this->botVector.erase(loeschIterator);
			i--;
		}
	}
}

void Autoverwalter::spielerGenerieren(unsigned short anzahl)
{
	for (int i = 0; i < anzahl; i++) {
		this->spielerVector.push_back(new Spieler1(this->window, this->eingabeverwaltung));
	}
}

void Autoverwalter::spielerAktualisieren()
{
	for (int i = 0; i < this->spielerVector.size(); i++) {
		this->spielerVector[i]->aktualisieren();
		for (int y = 0; y < this->botVector.size(); y++) {	
			if (Collision::pixelPerfectTest(*this->spielerVector[i]->getSprite(), *this->botVector[y]->getSprite(), 177)) {
				this->istTot = true;
			}
		}
		if (this->spielerVector[i]->getGlobalBounds().intersects(sf::FloatRect(0, -10000, 26 * 6.4, 100000))) this->istTot = true;
		if (this->spielerVector[i]->getGlobalBounds().intersects(sf::FloatRect(640 - (26 * 6.4), -10000, 640 , 100000))) this->istTot = true;
		if (!this->spielerVector[i]->getGlobalBounds().intersects(this->map->getMapViereck()) && this->spielerVector[i]->getPos().y < this->map->getMapViereck().getPosition().y) this->hatGewonnen = true;
		
	}
}

void Autoverwalter::spielerAnzeigen()
{
	for (int i = 0; i < this->spielerVector.size(); i++) {
		//if (i == 0) this->window->setView(sf::View(sf::Vector2f(this->window->getView().getSize().x / 2, this->spielerVector[i]->getPos().y), sf::Vector2f(this->window->getView().getSize().x, this->window->getView().getSize().y)));
		this->spielerVector[i]->anzeigen();
	}
}

void Autoverwalter::viewAufGesteuertenSpieler(unsigned short spielerIndex)
{
	for (int i = 0; i < this->spielerVector.size(); i++) {
		if (i == spielerIndex) this->window->setView(sf::View(sf::Vector2f(this->window->getView().getSize().x / 2, this->spielerVector[i]->getPos().y), sf::Vector2f(this->window->getView().getSize().x, this->window->getView().getSize().y)));
	}
}

bool Autoverwalter::getIstTot()
{
	return this->istTot;
}

bool Autoverwalter::getHatGewonnen()
{
	return this->hatGewonnen;
}
