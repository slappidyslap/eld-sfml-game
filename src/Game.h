#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Game {
protected:
  sf::Texture playerTexture_;
  sf::Sprite player_;

public:
  explicit Game(sf::Texture playerTexture, sf::Sprite player)
      : playerTexture_(std::move(playerTexture)), player_(std::move(player)) {};

  virtual ~Game() {

  };

  Game() = delete;
  Game(const Game &) = delete;
  Game(Game &&) = delete;
  Game &operator=(const Game &) = delete;
  Game &operator=(Game &&) = delete;
};
