#pragma once
#include "Objektverwalter.hpp"

Objektverwalter::~Objektverwalter()
{
	for (int i = 0; i < this->botVector.size() - 0; i++) {
		delete this->botVector[i];
	}
	for (int i = 0; i < this->spielerVector.size(); i++) {
		delete this->spielerVector[i];
	}
	for (int i = 0; i < this->muenzVector.size(); i++) {
		delete this->muenzVector[i];
	}
	for (int i = 0; i < this->bananenschalenVector.size(); i++) {
		delete this->bananenschalenVector[i];
	}
}

Objektverwalter::Objektverwalter()
{
}

Objektverwalter::Objektverwalter(sf::RenderWindow* window, Map* map, EingabeVerwaltung* eingabeverwaltung, MusikVerwaltung* musikverwaltung)
{
	this->window = window;
	this->map = map;
	this->eingabeverwaltung = eingabeverwaltung;
	this->musikverwaltung = musikverwaltung;
	for (int i = 1; i <= 3; i++) {
		sf::Texture texturTmp;
		char pfadTmp[25] = "./res/grafiken/auto";
		pfadTmp[19] = (char)i + 48;
		pfadTmp[20] = '.';
		pfadTmp[21] = 'p';
		pfadTmp[22] = 'n';
		pfadTmp[23] = 'g';
		if (!texturTmp.loadFromFile(pfadTmp)) {
			std::cout << "Fehler beim laden der Textur (" << pfadTmp << ")" << std::endl;
		}
		this->spielerTexturen.push_back(texturTmp);
	}
	for (int i = 1; i <= 5; i++) {
		sf::Texture texturTmp;
		char pfadTmp[24] = "./res/grafiken/bot";
		pfadTmp[18] = (char)i + 48;
		pfadTmp[19] = '.';
		pfadTmp[20] = 'p';
		pfadTmp[21] = 'n';
		pfadTmp[22] = 'g';
		if (!texturTmp.loadFromFile(pfadTmp)) {
			std::cout << "Fehler beim laden der Textur (" << pfadTmp << ")" << std::endl;
		}
		this->botTexturen.push_back(texturTmp);
	}
}
void Objektverwalter::botHinzufuegen(Bot* bot)
{
	this->botVector.push_back(bot);
}
void Objektverwalter::botGenerieren(unsigned short anzahl, int typ)
{
	for (int i = 0; i < anzahl; i++) {
		Bot* bot_tmp = nullptr;
		bool kollidiert;
		int versuche = 0;
		int maxVersuche = 10;
		do {
			versuche++;
			kollidiert = false;
			if (typ == 1)bot_tmp = new Bot(this->window, &this->botTexturen[0]);
			if (typ == 2)bot_tmp = new Bot(this->window, &this->botTexturen[1]);
			if (typ == 3)bot_tmp = new Bot(this->window, &this->botTexturen[2]);
			if (typ == 4)bot_tmp = new Bot(this->window, &this->botTexturen[3]);
			if (typ == 5)bot_tmp = new Bot(this->window, &this->botTexturen[4]);
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
void Objektverwalter::botLevelGenerieren(unsigned short anzahl, unsigned short reihen, int typ)
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
				if (typ == 1)bot_tmp = new Bot(this->window, &this->botTexturen[0]);
				if (typ == 2)bot_tmp = new Bot(this->window, &this->botTexturen[1]);
				if (typ == 3)bot_tmp = new Bot(this->window, &this->botTexturen[2]);
				if (typ == 4)bot_tmp = new Bot(this->window, &this->botTexturen[3]);
				if (typ == 5)bot_tmp = new Bot(this->window, &this->botTexturen[4]);
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
void Objektverwalter::botsAktualisieren()
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

void Objektverwalter::botsAnzeigen()
{
	for (int i = 0; i < this->botVector.size(); i++) {
		this->botVector[i]->anzeigen();
	}
}

void Objektverwalter::spielerHinzufuegen(Spieler* spieler)
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

void Objektverwalter::spielerGenerieren(unsigned short anzahl, int typ)
{
	Eigenschaften eigenschaftenArr[5]{
		{ 3, 0.01, 0.05},
		{ 4, 0.01, 0.07},
		{ 5, 0.01, 0.10}

	};
	Eigenschaften eigenschaftenTmp{ 3,0.01,0.05 };
	for (int i = 0; i < anzahl; i++) {
		this->spielerVector.push_back(new Spieler(this->window, this->eingabeverwaltung, &this->spielerTexturen[typ], eigenschaftenArr[typ], this->musikverwaltung));
		for (int y = 0; y < this->botVector.size(); y++) {
			if (Collision::pixelPerfectTest(*this->spielerVector[this->spielerVector.size() - 1]->getSprite(), *this->botVector[y]->getSprite(), 177)) {
				delete this->botVector[y];
				std::vector<Bot*>::iterator loeschIterator = this->botVector.begin();
				std::advance(loeschIterator, y);
				this->botVector.erase(loeschIterator);
				y--;
			}
		}
	}
}

void Objektverwalter::spielerAktualisieren()
{
	bool amLeben = false;
	for (int i = 0; i < this->spielerVector.size(); i++) {
		this->spielerVector[i]->aktualisieren();
		for (int y = 0; y < this->botVector.size(); y++) {
			if (Collision::pixelPerfectTest(*this->spielerVector[i]->getSprite(), *this->botVector[y]->getSprite(), 177) && this->spielerVector[i]->getUnverwundbar() == false) {
				this->spielerVector[i]->schadenNehmen(1);
			}
		}
		if (this->spielerVector[i]->getGlobalBounds().intersects(sf::FloatRect(0, -10000, 26 * 6.4, 100000)) && this->spielerVector[i]->getUnverwundbar() == false) this->spielerVector[i]->schadenNehmen(1);
		if (this->spielerVector[i]->getGlobalBounds().intersects(sf::FloatRect(640 - (26 * 6.4), -10000, 640, 100000)) && this->spielerVector[i]->getUnverwundbar() == false) this->spielerVector[i]->schadenNehmen(1);
		if (!this->spielerVector[i]->getGlobalBounds().intersects(this->map->getMapViereck()) && this->spielerVector[i]->getPos().y < this->map->getMapViereck().getPosition().y) this->hatGewonnen = true;
		if (!this->spielerVector[i]->getGlobalBounds().intersects(this->map->getMapViereck()) && this->spielerVector[i]->getPos().y > this->map->getMapViereck().getPosition().y) this->istTot = true;
		if (this->spielerVector[i]->getLeben() != 0) amLeben = true;
		for (int y = 0; y < this->muenzVector.size(); y++) { // Münzen werden überprüft
			if (Collision::pixelPerfectTest(*this->spielerVector[i]->getSprite(), *this->muenzVector[y]->getSprite(), 177) && this->spielerVector[i]->getUnverwundbar() == false) {
				delete this->muenzVector[y];
				std::vector<Muenze*>::iterator muenzVectorIterator = this->muenzVector.begin();
				advance(muenzVectorIterator, y);
				muenzVector.erase(muenzVectorIterator);
				y--;
				this->spielerVector[i]->hatMuenzeGesammelt();
			}
		}
		for (int y = 0; y < this->bananenschalenVector.size(); y++) { // Banenschalen werden überprüft
			if (Collision::pixelPerfectTest(*this->spielerVector[i]->getSprite(), *this->bananenschalenVector[y]->getSprite(), 177) && this->spielerVector[i]->getUnverwundbar() == false) {
				delete this->bananenschalenVector[y];
				std::vector<Bananenschale*>::iterator muenzVectorIterator = this->bananenschalenVector.begin();
				advance(muenzVectorIterator, y);
				bananenschalenVector.erase(muenzVectorIterator);
				y--;
				this->spielerVector[i]->schadenNehmen(1);
				this->spielerVector[i]->setGeschwindigkeit(0);
			}
		}
	}
	if (amLeben == false) this->istTot = true;
	for (int i = 0; i < this->spielerVector.size(); i++) {
	}
}

void Objektverwalter::spielerAnzeigen()
{
	for (int i = 0; i < this->spielerVector.size(); i++) {
		this->spielerVector[0]->anzeigen();
	}
}

void Objektverwalter::viewAufGesteuertenSpieler(unsigned short spielerIndex)
{
	for (int i = 0; i < this->spielerVector.size(); i++) {
		if (i == spielerIndex) {
			float yPos = this->spielerVector[i]->getPos().y;
			float yBegrenzung = this->map->getMapViereck().getPosition().y + this->map->getMapViereck().getSize().y - this->window->getView().getSize().y / 2;
			if (yPos > yBegrenzung) yPos = yBegrenzung;
			this->window->setView(sf::View(sf::Vector2f(this->window->getView().getSize().x / 2, yPos), sf::Vector2f(this->window->getView().getSize().x, this->window->getView().getSize().y)));
		}
		//if (i == spielerIndex) this->window->setView(sf::View(sf::Vector2f(this->window->getView().getSize().x / 2, this->spielerVector[i]->getPos().y), sf::Vector2f(this->window->getView().getSize().x, this->window->getView().getSize().y)));
	}
}

void Objektverwalter::infoVonSpielerAnzeigen(unsigned short spielerIndex)
{
	for (int i = 0; i < this->spielerVector.size(); i++) {
		if (i == spielerIndex) this->spielerVector[i]->statusAnzeigen();
	}
}

void Objektverwalter::muenzLevelGenerieren(unsigned short anzahl, unsigned short reihen)
{
	double yKoordinateMap = this->map->getMapViereck().getSize().y + this->map->getMapViereck().getPosition().y;
	double yAbstand = this->map->getMapViereck().getSize().y / reihen;
	for (int y = 0; y < reihen; y++) {
		for (int i = 0; i < anzahl; i++) {
			Muenze* muenze_tmp = nullptr;
			bool kollidiert;
			int versuche = 0;
			int maxVersuche = 10;
			do {
				versuche++;
				kollidiert = false;
				muenze_tmp = new Muenze(this->window);
				sf::Vector2f position_tmp;
				short fahrbahn = rand() % 3;
				if (fahrbahn == 0) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2) - (15.f * 6.4f), yKoordinateMap + muenze_tmp->getGlobalBounds().height / 2 - (yAbstand * y) - rand() % 1000);
				if (fahrbahn == 1) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2), yKoordinateMap + muenze_tmp->getGlobalBounds().height / 2 - (yAbstand * y) - rand() % 1000);
				if (fahrbahn == 2) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2) + (15.f * 6.4f), yKoordinateMap + muenze_tmp->getGlobalBounds().height / 2 - (yAbstand * y) - rand() % 1000);
				muenze_tmp->setPos(position_tmp);
				for (int i = 0; i < muenzVector.size(); i++) {
					if (muenze_tmp->kollidiert(muenzVector[i]->getGlobalBounds())) {
						delete muenze_tmp;
						muenze_tmp = nullptr;
						kollidiert = true;
						break;
					}
				}
			} while (kollidiert && (versuche < maxVersuche));
			if (muenze_tmp != nullptr) muenzVector.push_back(muenze_tmp);
		}
	}
}

void Objektverwalter::muenzenAnzeigen()
{
	for (int i = 0; i < this->muenzVector.size(); i++) {
		this->muenzVector[i]->anzeigen();
	}
}

bool Objektverwalter::getIstTot()
{
	return this->istTot;
}

bool Objektverwalter::getHatGewonnen()
{
	return this->hatGewonnen;
}

int Objektverwalter::muenzenGesammt()
{
	int muenzenGesammt = 0;
	for (int i = 0; i < this->spielerVector.size(); i++) {
		muenzenGesammt += this->spielerVector[i]->getGeld();
	}
	return muenzenGesammt;
}

void Objektverwalter::bananenschalenLevelGenerieren(unsigned short anzahl, unsigned short reihen)
{
	double yKoordinateMap = this->map->getMapViereck().getSize().y + this->map->getMapViereck().getPosition().y;
	double yAbstand = this->map->getMapViereck().getSize().y / reihen;
	for (int y = 0; y < reihen; y++) {
		for (int i = 0; i < anzahl; i++) {
			Bananenschale* bananenschale_tmp = nullptr;
			bool kollidiert;
			int versuche = 0;
			int maxVersuche = 10;
			do {
				versuche++;
				kollidiert = false;
				bananenschale_tmp = new Bananenschale(this->window);
				sf::Vector2f position_tmp;
				short fahrbahn = rand() % 3;
				if (fahrbahn == 0) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2) - (15.f * 6.4f), yKoordinateMap + bananenschale_tmp->getGlobalBounds().height / 2 - (yAbstand * y) - rand() % 1000);
				if (fahrbahn == 1) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2), yKoordinateMap + bananenschale_tmp->getGlobalBounds().height / 2 - (yAbstand * y) - rand() % 1000);
				if (fahrbahn == 2) position_tmp = sf::Vector2f((this->window->getView().getSize().x / 2) + (15.f * 6.4f), yKoordinateMap + bananenschale_tmp->getGlobalBounds().height / 2 - (yAbstand * y) - rand() % 1000);
				bananenschale_tmp->setPos(position_tmp);
				for (int i = 0; i < bananenschalenVector.size(); i++) {
					if (bananenschale_tmp->kollidiert(bananenschalenVector[i]->getGlobalBounds())) {
						delete bananenschale_tmp;
						bananenschale_tmp = nullptr;
						kollidiert = true;
						break;
					}
				}
				for (int i = 0; i < muenzVector.size() && bananenschale_tmp != nullptr; i++) {
					if (bananenschale_tmp->kollidiert(muenzVector[i]->getGlobalBounds())) {
						delete bananenschale_tmp;
						bananenschale_tmp = nullptr;
						kollidiert = true;
						break;
					}
				}
				for (int i = 0; i < spielerVector.size() && bananenschale_tmp != nullptr; i++) {
					if (bananenschale_tmp->kollidiert(spielerVector[i]->getGlobalBounds())) {
						delete bananenschale_tmp;
						bananenschale_tmp = nullptr;
						kollidiert = true;
						break;
					}
				}
			} while (kollidiert && (versuche < maxVersuche));
			if (bananenschale_tmp != nullptr) bananenschalenVector.push_back(bananenschale_tmp);
		}
	}
}

void Objektverwalter::bananenschalenAnzeigen()
{
	for (int i = 0; i < this->bananenschalenVector.size(); i++) {
		this->bananenschalenVector[i]->anzeigen();
	}
}
