#pragma once
#include <SFML/Graphics.hpp>
#include "EingabeVerwaltung.hpp"
class Auto
{
protected:

    char level;                   // Das Level bestimmt über die Optik des Autos (siehe Konstruktor) -> a,b,c,... Bots; 1,2,3,... Spieler
    sf::Sprite derWicht;          // benötigt um eine Textur zu anzuzeigen (draw()), (Namensgebung -> Übersetzer)
    sf::Texture textur;           // speichert Bild/PNG des Autos
    sf::Vector2f position;        // Koordinate eines Auto-Objeks
    unsigned short hoehe;         // Höhe des Autos angegeben in Pixeln
    unsigned short breite;        // Breite des Autos in Pixeln
    sf::Vector2f geschwindigkeit; // Geschwindigkeit 
    sf::Vector2f beschleunigung;  // wird das Auto gerade schneller oder langsamer
    sf::RenderWindow* window;
    EingabeVerwaltung* eingabeverwaltung;

public:

    Auto(sf::RenderWindow* window, const char extLevel);  // Parameterkonstruktor für die Erstellung eines Autos -> siehe .cpp
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

    virtual void aktualisieren() = 0;       // Bringt die Attribute/Variablen auf den "aktuellen Stand"
    // virtual void anzeigen();            // zeichnet das Auto
};
