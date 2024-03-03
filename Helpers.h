#pragma once
#include <SFML/Graphics.hpp>

float magnitude(const sf::Vector2f& const vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f normalize(const sf::Vector2f& const vector) 
{
	auto mag = magnitude(vector);
	return sf::Vector2f(vector.x / mag, vector.y / mag);
}

