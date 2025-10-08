#include "Color.h"

#include <iostream>

Color::Value Color::flipped(Color::Value color) {
  return color == Color::WHITE ? Color::BLACK : Color::WHITE;
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
  os << (color.value == Color::WHITE ? "WHITE" : "BLACK");
  return os;
}
