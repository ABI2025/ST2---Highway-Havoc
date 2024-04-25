#include "Spieler2.hpp"
Spieler2::~Spieler2()
{
}

Spieler2::Spieler2()
{
}

Spieler2::Spieler2(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung) : Spieler(window, eingabeverwaltung)
{
	this->window = window;
	if (!this->texture.loadFromFile("./res/grafiken/auto_lvl2.png")) {
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/auto.png)" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	sprite.setOrigin(sprite.getGlobalBounds().getSize().x / 2, sprite.getGlobalBounds().getSize().y / 2);
	sprite.setScale(1.7f, 1.7f);
	this->sprite.setPosition(this->window->getView().getSize().x / 2, this->window->getView().getSize().y / 2);
	geschwindigkeit = 1;
	this->eingabeverwaltung = eingabeverwaltung;
}

void Spieler2::aktualisieren()
{
	this->rotation = this->sprite.getRotation();
	if (this->eingabeverwaltung->getGruppenStatus(0)) {
		this->geschwindigkeit += this->beschlaeunigung;
	}
	if (this->eingabeverwaltung->getGruppenStatus(2)) {
		this->geschwindigkeit -= this->beschlaeunigung;
	}
	if (this->eingabeverwaltung->getGruppenStatus(1)) {
		this->rotation -= 1 * geschwindigkeit / 2;
	}
	if (this->eingabeverwaltung->getGruppenStatus(3)) {
		this->rotation += 1 * geschwindigkeit / 2;
	}
	if (this->geschwindigkeit < 0) this->geschwindigkeit += this->reibung;
	if (this->geschwindigkeit > 0) this->geschwindigkeit -= this->reibung;
	if (this->geschwindigkeit > this->maxMinGeschwindigkeit) this->geschwindigkeit = this->maxMinGeschwindigkeit;
	if (this->geschwindigkeit < -this->maxMinGeschwindigkeit) this->geschwindigkeit = -this->maxMinGeschwindigkeit;
	this->sprite.setRotation(this->rotation);
	double rotationAlsWinkelmaß = this->sprite.getRotation() * 3.14159 / 180;
	double xGeschwindigkeit = sin(rotationAlsWinkelmaß) * geschwindigkeit;
	double yGeschwindigkeit = -1 * cos(rotationAlsWinkelmaß) * geschwindigkeit;
	this->bewegenUm(sf::Vector2f(xGeschwindigkeit, yGeschwindigkeit));
}