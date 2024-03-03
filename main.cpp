#include <SFML/Graphics.hpp>
#include "PlayerSpacehipView.h"
#include "Constants.h"
#include <list>


int main()
{
    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Space invaders");
    views::PlayerSpacehipView player;

    GameObject::addGameObject(&player);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            auto i = 1;
        }
        GameObject::drawAll(window, event);
        
        window.display();
    }

    return 0;
}
