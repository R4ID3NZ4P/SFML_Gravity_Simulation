#pragma once
#include <SFML/Graphics.hpp>
#include "GravitySource.h"

class Particle
{
	sf::CircleShape shape;
	sf::Vector2f pos;
	sf::Vector2f vel;

public:
	Particle(float pos_x, float pos_y, float vel_x, float vel_y);
	void render(sf::RenderWindow* window);
	void updatePhysics(GravitySource& s);
	void setColor(sf::Color col);
};

