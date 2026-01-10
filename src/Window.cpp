#include "Window.h"
#include <SFML/Window/Keyboard.hpp>

Window::Window(const std::string &title, const sf::Vector2u &size,
               const unsigned int &maxFps)
    : title_(title), size_(size), maxFps_(maxFps), isDone_(false),
      isFullscreen_(false) {
  create();
}

Window::~Window() { destroy(); }

void Window::beginDraw() { sfWindow_.clear(sf::Color::Black); }

void Window::endDraw() { sfWindow_.display(); }

void Window::update() {
  while (const std::optional event = sfWindow_.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      isDone_ = true;
    } else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
      if (keyPressed->scancode == sf::Keyboard::Scancode::F5) {
        toggleFullscreen();
      }
    }
  }
}

void Window::draw(const sf::Drawable &drawable) { sfWindow_.draw(drawable); }

bool Window::isDone() const { return isDone_; }

bool Window::isFullscreen() const { return isFullscreen_; }

sf::Vector2u Window::getWindowSize() const { return size_; }

unsigned int Window::getMaxFps() const { return maxFps_; }

void Window::toggleFullscreen() {
  isFullscreen_ = !isFullscreen_;
  destroy();
  create();
}

void Window::create() {
  auto state = isFullscreen_ ? sf::State::Fullscreen : sf::State::Windowed;
  // первый аргумент sfWindow_.create - sf::VideoMode
  // третий аргумент sf::VideoMode:
  // modeBitsPerPixel – Pixel depths in bits per pixel
  // Construct the video mode with its attributes
  sfWindow_.create(sf::VideoMode{sf::Vector2u{size_.x, size_.y}}, title_,
                   state);
  sfWindow_.setFramerateLimit(maxFps_);
}

void Window::destroy() { sfWindow_.close(); }
