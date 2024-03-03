#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

namespace views
{

	class ShotView : public GameObject
	{
	public:
		ShotView(const sf::Vector2f& position, float speed);
		~ShotView();
		void draw(sf::RenderWindow& window) override;

	private:
		const float Radius = 1;
		sf::Vector2f _position;
		float _speed;
	};


	ShotView::ShotView(const sf::Vector2f& position, float speed)
		: _position(position), _speed(speed)
	{
	}

	ShotView::~ShotView()
	{
	}

	void ShotView::draw(sf::RenderWindow& window)
	{
		sf::CircleShape circle(Radius);
		circle.setFillColor(sf::Color::White);
		circle.setPosition(_position);
		window.draw(circle);
		_position.y -= _speed;

		if (_position.y + Radius < 0)
			destroy();
	}
}
