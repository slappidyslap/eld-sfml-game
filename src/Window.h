#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Window
{
public:
    explicit Window(
        const std::string &l_title,
        const sf::Vector2u &l_size,
        const unsigned int &maxFps);
    virtual ~Window();

    void BeginDraw();
    void EndDraw();

    void Update();

    bool IsDone();
    bool IsFullscreen();
    sf::Vector2u GetWindowSize();
    unsigned int GetMaxFps();

    void ToggleFullscreen();

    void Draw(sf::Drawable &l_drawable);

    Window() = delete;
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

private:
    sf::RenderWindow m_window;
    sf::Vector2u m_size;
    std::string m_title;
    unsigned int m_maxFps;
    bool m_isDone;
    bool m_isFullscreen;

    void Destroy();
    void Create();
};