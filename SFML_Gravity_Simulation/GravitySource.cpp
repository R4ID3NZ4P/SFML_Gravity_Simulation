#include "GravitySource.h"

GravitySource::GravitySource(float pos_x, float pos_y, float strength) {
	pos.x = pos_x;
	pos.y = pos_y;
	this->strength = strength;

	shape.setRadius(10);
	shape.setPosition(pos);
	shape.setFillColor(sf::Color::White);
}

sf::Vector2f GravitySource::getPos()
{
	return pos;
}

float GravitySource::getStrength()
{
	return strength;
}

void GravitySource::render(sf::RenderWindow* window)
{
	window->draw(shape);
}

