#include "Window.h"
#include "util/tostring.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

int main() {
  Window win{"Test", sf::Vector2u{800, 400}, 60};

  sf::RectangleShape shape{sf::Vector2f{30, 30}};

  while (!win.isDone()) {
    win.beginDraw();
    win.update();

    win.draw(shape);
    shape.move({1, 0});

    win.endDraw();
  }
}