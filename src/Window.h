#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

class Window {
public:
  explicit Window(const std::string &title, const sf::Vector2u &size,
                  const unsigned int &maxFps);
  virtual ~Window();

  void beginDraw();
  void endDraw();
  void update();
  void toggleFullscreen();
  void draw(const sf::Drawable &drawable);

  bool isDone() const;
  bool isFullscreen() const;
  sf::Vector2u getWindowSize() const;
  unsigned int getMaxFps() const;

  Window() = delete;
  Window(Window &&) = delete;
  Window &operator=(Window &&) = delete;
  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;

protected:
  sf::RenderWindow sfWindow_;
  sf::Vector2u size_;
  std::string title_;
  unsigned int maxFps_;
  bool isDone_;
  bool isFullscreen_;

  void destroy();
  void create();
};
