#include "Color.h"

Color::Value Color::get() const { return this->value; }

Color::Value Color::flipped() const {
  return this->value == Color::WHITE ? Color::BLACK : Color::WHITE;
}