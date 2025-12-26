#include <SFML/Graphics.hpp>
#include <iostream>
#include "logger.h"
#include "tostring.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({640, 480}), "CMake SFML Project");
    window.setFramerateLimit(60);

    if (window.isOpen())
    {
        dgrdch::logInfo("App started");
    }

    sf::Texture knightTexture;
    if (!knightTexture.loadFromFile("knight.png"))
    {
        dgrdch::logError("Unable to load knight.png");
        exit(1);
    }
    sf::Sprite knight{knightTexture};
    sf::Vector2u knightSize = knightTexture.getSize();
    // knight.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    // knight.setPosition({static_cast<float>(640u - knightSize.x), knight.getPosition().y});
    knight.setOrigin(knightSize.x / 2, knightSize.y / 2);
    sf::Vector2f increment({2.0f, 2.0f});

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
        window.clear(sf::Color::White);

        if (
            knight.getPosition().x + (knightSize.x / 2) > window.getSize().x &&
                increment.x > 0 ||
            knight.getPosition().x - (knightSize.x / 2) < 0 &&
                increment.x < 0)
        {
            // Reverse the direcetion on X axis
            increment.x = -increment.x;
        }

        if (
            knight.getPosition().y + (knightSize.y / 2) > window.getSize().y &&
                increment.y > 0 ||
            knight.getPosition().y - (knightSize.y / 2) < 0 &&
                increment.y < 0)
        {
            // Reverse the direcetion on Y axis
            increment.y = -increment.y;
        }

        knight.setPosition(knight.getPosition() + increment);
        window.draw(knight);

        window.display();
    }
    dgrdch::logInfo("App closed");
}