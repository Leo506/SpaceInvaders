#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

class GameObject
{
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	void destroy();
	bool isActive() const;
	static void addGameObject(GameObject* gameObject);
	static void drawAll(sf::RenderWindow& window, sf::Event& event);

private:
	bool _isActive = true;
	static std::list<GameObject*> _activeGameObjects;
	static void clearInactiveGameObjects();
};

void GameObject::destroy()
{
	_isActive = false;
}

bool GameObject::isActive() const
{
	return _isActive;
}

void GameObject::addGameObject(GameObject* gameObject)
{
	GameObject::_activeGameObjects.push_back(gameObject);
}

void GameObject::clearInactiveGameObjects()
{
	GameObject::_activeGameObjects.remove_if([](GameObject* g) { return !g->isActive();  });
}

inline void GameObject::drawAll(sf::RenderWindow& window, sf::Event& event)
{
	for (auto obj : GameObject::_activeGameObjects)
		obj->draw(window);

	clearInactiveGameObjects();
}

std::list<GameObject*> GameObject::_activeGameObjects = std::list<GameObject*>();
