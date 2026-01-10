#include <SFML/Graphics.hpp>
#include <sstream>

namespace eld {

template <typename T> std::string toString(sf::Vector2<T> v) {
  std::ostringstream ss;
  ss << "Vector{x: " << v.x << ", y: " << v.y << "}\n";
  return ss.str();
}

} // namespace eld
