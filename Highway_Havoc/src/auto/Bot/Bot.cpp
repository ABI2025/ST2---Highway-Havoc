#pragma once
#include "Bot.hpp"
Bot::~Bot()
{
}
Bot::Bot() : Automobil()
{

}
Bot::Bot(sf::RenderWindow* window) : Automobil(window)
{
}
