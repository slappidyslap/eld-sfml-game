#include <SFML/Graphics.hpp>
#include <iostream>
#include "logger.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(60);
    
    if (window.isOpen()) {
        dgrdch::logInfo("App started");
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Red);

        window.display();
    }
    dgrdch::logInfo("App closed");
}