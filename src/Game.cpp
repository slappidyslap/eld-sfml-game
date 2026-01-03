#include "Game.h"

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600), 60)
{
    m_knightTexture.loadFromFile("knight.png");
    m_knight.setTexture(m_knightTexture);
    m_increment = sf::Vector2i(400, 400); // (скорость) рыцаря
}

Game::~Game() {}

void Game::HandleInput()
{
}

void Game::Update()
{
    m_window.Update();
    MoveKnight();
}

void Game::Render()
{
    m_window.BeginDraw();
    m_window.Draw(m_knight);
    m_window.EndDraw();
}

void Game::RestartClock() { m_elapsed = m_clock.restart(); }

sf::Time Game::GetElapsed() { return m_elapsed; }

void Game::MoveKnight()
{
    sf::Vector2u winSize = m_window.GetWindowSize();
    sf::Vector2u knightSize = m_knightTexture.getSize();

    if (
        (m_knight.getPosition().x > winSize.x - knightSize.x && m_increment.x > 0) ||
        (m_knight.getPosition().x < 0 && m_increment.x < 0))
    {
        // Reverse the direcetion on X axis
        m_increment.x = -m_increment.x;
    }

    if (
        (m_knight.getPosition().y > winSize.y - knightSize.y && m_increment.y > 0) ||
        (m_knight.getPosition().y < 0 && m_increment.y < 0))
    {
        // Reverse the direcetion on Y axis
        m_increment.y = -m_increment.y;
    }

    float elapsedSeconds = m_elapsed.asSeconds();
    m_knight.setPosition(
        m_knight.getPosition().x + (m_increment.x * elapsedSeconds),
        m_knight.getPosition().y + (m_increment.y * elapsedSeconds));
}

Window *Game::GetWindow() { return &m_window; }
