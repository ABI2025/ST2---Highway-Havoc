#pragma once
#include "Bananenschale.hpp"

// Destruktor f�r die Klasse Bananenschale
Bananenschale::~Bananenschale()
{
}

// Konstruktor f�r die Klasse Bananenschale
Bananenschale::Bananenschale(sf::RenderWindow* window)
{
    // Weist das Fensterzeiger der Klassenvariable zu
    this->window = window;

    // L�dt die Textur f�r die Bananenschale und �berpr�ft auf Fehler
    if (!this->bananenschaleTextur.loadFromFile("./res/grafiken/bananenschale.png")) {
        std::cout << "Fehler beim Laden der Datei! (./res/grafiken/bananenschale.png)" << std::endl;
    }

    // Setzt die Textur f�r den Sprite
    this->bananenschaleSprite.setTexture(this->bananenschaleTextur);

    // Setzt den Ursprung des Sprites auf dessen Zentrum
    this->bananenschaleSprite.setOrigin(this->bananenschaleSprite.getGlobalBounds().getSize().x / 2, this->bananenschaleSprite.getGlobalBounds().getSize().y / 2);

    // Skaliert den Sprite auf eine Breite von 50 Einheiten, wobei das Seitenverh�ltnis beibehalten wird
    float faktor = 50 / this->bananenschaleSprite.getGlobalBounds().getSize().x;
    this->bananenschaleSprite.setScale(faktor, faktor);

    // Setzt eine zuf�llige Rotation f�r den Sprite
    this->bananenschaleSprite.setRotation(rand() % 360);
}

// Aktualisierungsfunktion, derzeit leer
void Bananenschale::aktualisieren()
{
}

// Zeichnet den Bananenschalen-Sprite auf das Fenster
void Bananenschale::anzeigen()
{
    this->window->draw(this->bananenschaleSprite);
}

// Gibt die Position des Bananenschalen-Sprites zur�ck
sf::Vector2f Bananenschale::getPos()
{
    return this->bananenschaleSprite.getPosition();
}

// Setzt die Position des Bananenschalen-Sprites
void Bananenschale::setPos(sf::Vector2f position)
{
    this->bananenschaleSprite.setPosition(position);
}

// Gibt die globalen Begrenzungen des Bananenschalen-Sprites zur�ck
sf::FloatRect Bananenschale::getGlobalBounds()
{
    return this->bananenschaleSprite.getGlobalBounds();
}

// �berpr�ft, ob der Bananenschalen-Sprite mit einem gegebenen Rechteck kollidiert
bool Bananenschale::kollidiert(sf::FloatRect viereck)
{
    return this->bananenschaleSprite.getGlobalBounds().intersects(viereck);
}

// Gibt einen Zeiger auf den Bananenschalen-Sprite zur�ck
sf::Sprite* Bananenschale::getSprite()
{
    return &this->bananenschaleSprite;
}
