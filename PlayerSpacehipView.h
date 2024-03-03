#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Helpers.h"
#include "Shot.h"
#include "GameObject.h"

namespace views 
{
	class PlayerSpacehipView : public GameObject
	{
	public:
		PlayerSpacehipView();
		~PlayerSpacehipView();
		void draw(sf::RenderWindow& const window) override;
		void handleInput();

	private:
		sf::Vector2f _size = sf::Vector2f(25, 25);
		sf::Vector2f _position = sf::Vector2f(WindowWidth / 2, WindowHeight - _size.y - 20);
		float _speed = 0.125;
		float _sincLastShot = 2000;
		sf::RectangleShape _rect = sf::RectangleShape(_size);
		void move(const sf::Vector2f& dir);
		ShotView* shot();
		bool CanShot();
	};

	PlayerSpacehipView::PlayerSpacehipView()
	{
	}

	PlayerSpacehipView::~PlayerSpacehipView()
	{
	}

	inline void PlayerSpacehipView::draw(sf::RenderWindow& const window)
	{
		_rect.setFillColor(sf::Color::Red);
		_rect.setPosition(_position);
		window.draw(_rect);
		_sincLastShot += 1;

		handleInput();
	}

	inline void PlayerSpacehipView::handleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			move(sf::Vector2f(1, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			move(sf::Vector2f(-1, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && CanShot())
		{
			addGameObject(shot());
		}
	}

	inline void PlayerSpacehipView::move(const sf::Vector2f& dir)
	{
		auto newPosition = sf::Vector2f(_position.x + normalize(dir).x * _speed, _position.y);
		if (newPosition.x <= 0)
			return;
		if (newPosition.x >= WindowWidth - _size.x)
			return;
		_position = newPosition;
	}

	inline ShotView* PlayerSpacehipView::shot()
	{
		_sincLastShot = 0;
		return new ShotView(sf::Vector2f(_position.x + _size.x / 2, _position.y), _speed);
	}

	inline bool PlayerSpacehipView::CanShot()
	{
		return _sincLastShot >= 2000;
	}
}
