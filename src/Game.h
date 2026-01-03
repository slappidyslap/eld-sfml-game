#pragma once
#include "Window.h"

class Game
{
public:
    Game();
    virtual ~Game();

    void HandleInput();
    void Update();
    void Render();
    void RestartClock();
    sf::Time GetElapsed();

    Window *GetWindow();

    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

private:
    void MoveKnight();

    Window m_window;
    sf::Texture m_knightTexture;
    sf::Sprite m_knight;
    sf::Vector2i m_increment;
    sf::Clock m_clock;
    sf::Time m_elapsed;
};