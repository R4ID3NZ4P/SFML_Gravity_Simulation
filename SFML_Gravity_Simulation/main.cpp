#include <SFML/Graphics.hpp>
#include <vector>
#include "GravitySource.h"
#include "Particle.h"

sf::Color mapColor(float value) {
	if (value < 0.f) value = 0.f;
	if (value > 1.f) value = 1.f;

	int r = value * 255;
	int g = (.5f - value) * 255;
	int b = (1.f - value) * 255;

	return sf::Color(r, g, b);
}

int main() {
	const unsigned int width = 1280;
	const unsigned int height = 720;

	std::vector<Particle> particles;
	std::vector<GravitySource> sources;

	sources.push_back(GravitySource(320, 360, 2500));
	sources.push_back(GravitySource(960, 360, 2500));
	int num_particles = 5000;

	for (int i = 0; i < num_particles; i++) {
		particles.push_back(Particle(640, 360, 1.5, 1.5 + 0.1 * i / num_particles));
		particles[i].setColor(mapColor(i / (float)num_particles));
	}


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

		for (auto& s : sources)
			s.render(window);

		for (auto& p1 : particles) {
			for (auto& s : sources)
				p1.updatePhysics(s);
			p1.render(window);
		}

		/*src.render(window);
		p1.render(window);*/
		
		window->display();
	}

	return 0;
}