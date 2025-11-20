#include <SFML/Graphics.hpp>
#include "GravitySource.h"
#include "Particle.h"

int main() {
	const unsigned int width = 1280;
	const unsigned int height = 720;

	GravitySource src(640, 360, 2000);
	Particle p1(640, 200, 3, -1);


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

		p1.updatePhysics(src);

		src.render(window);
		p1.render(window);
		
		window->display();
	}

	return 0;
}