#pragma once
#include <SFML/Graphics.hpp>

class Auto
{
protected:

    char level;                   // Das Level bestimmt über die Optik und andere Merkmale des Autos (siehe Konstruktor)
    sf::Sprite derWicht;          // benötigt um eine Textur zu anzuzeigen (draw())     (Namensgebung -> Übersetzer)
    sf::Texture textur;           // Bild/PNG des Autos
    sf::Vector2f Position;        // Koordinate eines Auto-Objeks
    unsigned short hoehe;         // Höhe des Autos angegeben in Pixeln
    unsigned short breite;        // Breite des Autos in Pixeln
    sf::Vector2f Geschwindigkeit; // Geschwindigkeit 
    sf::Vector2f Beschleunigung;  // wird das Auto gerade schneller oder langsamer

public:

    Auto(const char extLevel);
    // Auto(unsigned short extBreite, unsigned short extHoehe);
    ~Auto();

    // set-Methoden
    void setPosition(sf::Vector2f extPosition);
    void setXPosition(float extXPosition);
    void setYPosition(float extYPosition);
    void setHoehe(unsigned short extHoehe);
    void setBreite(unsigned short extBreite);
    void setGeschwindigkeit(sf::Vector2f extGeschwindigkeit);
    void setXGeschwindigkeit(float extXGeschwindigkeit);
    void setYGeschwindigkeit(float extYGeschwindigkeit);
    void setBeschleunigung(sf::Vector2f extBeschleunigung);
    void setXBeschleunigung(float extXBeschleunigung);
    void setYBeschleunigung(float extYBeschleunigung);

    // get-Methoden
    char getLevel() const;
    sf::Vector2f getPosition() const;
    float getXPosition() const;
    float getYPosition() const;
    unsigned short getHoehe() const;
    unsigned short getBreite() const;
    sf::Vector2f getGeschwindigkeit() const;
    float getXGeschwindigkeit() const;
    float getYGeschwindigkeit() const;
    sf::Vector2f getBeschleunigung() const;
    float getXBeschleunigung() const;
    float getYBeschleunigung() const;

    void draw(sf::RenderWindow& window) const;
};
