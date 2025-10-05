#include "Color.h"

#include <iostream>

Color::Value Color::get() const { return this->value; }

Color::Value Color::flipped() const {
  return this->value == Color::WHITE ? Color::BLACK : Color::WHITE;
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
  os << (color.value == Color::WHITE ? "WHITE" : "BLACK");
  return os;
}
