#include "SFML/Graphics.hpp"

int main() {
	//Fenster erstellen
	sf::RenderWindow whandle(sf::VideoMode(800, 800), "Highway Havoc");
	//Fenster updaten
	while (whandle.isOpen()) {
		sf::Event event;
		while (whandle.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) whandle.close();
		}

		whandle.clear(sf::Color::Black);

		whandle.display();
	}
	return 0;
}