#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
class GravitySource
{
	sf::CircleShape shape;
	sf::Vector2f pos;
	float strength;

public:
	GravitySource(float pos_x, float pos_y, float strength);
	sf::Vector2f getPos();
	float getStrength();
};

