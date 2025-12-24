#include <SFML/Graphics.hpp>
#include <iostream>
#include "logger.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({640, 480}), "CMake SFML Project");
    window.setFramerateLimit(60);

    if (window.isOpen())
    {
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

        sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(320, 240);
        rectangle.setOrigin(64, 64);
        window.draw(rectangle);

        sf::Texture worldTilesetTexture;
        if (!worldTilesetTexture.loadFromFile("world_tileset.png"))
        {
            dgrdch::logError("Unable to load world_tileset.png");
            exit(1);
        }
        sf::Sprite worldTileset{worldTilesetTexture};
        window.draw(worldTileset);

        window.display();
    }
    dgrdch::logInfo("App closed");
}