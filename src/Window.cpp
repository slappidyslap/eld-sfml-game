#include "Window.h"

Window::Window(const std::string &l_title, sf::Vector2u &l_size)
    : m_title(l_title),
      m_size(l_size)
{
    m_isDone = false;
    m_isFullscreen = false;
    Create();
}

Window::~Window()
{
    Destroy();
}

void Window::BeginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::EndDraw()
{
    m_window.display();
}

void Window::Update()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_isDone = true;
        }
        else if (event.type == sf::Event::KeyPressed &&
                 event.key.code == sf::Keyboard::F5)
        {
            ToggleFullscreen();
        }
    }
}

void Window::Draw(sf::Drawable &l_drawable)
{
    m_window.draw(l_drawable);
}

bool Window::IsDone()
{
    return m_isDone;
}

bool Window::IsFullscreen()
{
    return m_isFullscreen;
}

sf::Vector2u Window::GetWindowSize()
{
    return m_size;
}

void Window::ToggleFullscreen()
{
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}

void Window::Create()
{
    auto style = m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
    // первый аргумент m_window.create - sf::VideoMode
    // третий аргумент sf::VideoMode:
    // modeBitsPerPixel – Pixel depths in bits per pixel
    // Construct the video mode with its attributes
    m_window.create({m_size.x, m_size.y, 32}, m_title, style);
}

void Window::Destroy()
{
    m_window.close();
}
