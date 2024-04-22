#include "Spieler.hpp"
Spieler::~Spieler()
{
}

Spieler::Spieler()
{
}

Spieler::Spieler(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung) : Automobil(window)
{
}