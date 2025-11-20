#include <SFML/Graphics.hpp>

int main() {
	const unsigned int width = 1280;
	const unsigned int height = 720;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width, height }), "Gravity Simulation");
	window->setFramerateLimit(60);

	while (window->isOpen()) {
		while (std::optional event = window->pollEvent()) {
			if (event->is<sf::Event::Closed>()) window->close();
			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) window->close();
			}
		}

		window->clear();
		// Simulation update and rendering logic would go here
		window->display();
	}

	return 0;
}