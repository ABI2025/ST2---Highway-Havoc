#include "SFML/Graphics.hpp"

int main() {
	//Fenster erstellen
	sf::RenderWindow window(sf::VideoMode(800, 800), "Highway Havoc");
	//Fenster updaten
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		window.clear(sf::Color::Black);

		window.display();
	}
	return 0;
}