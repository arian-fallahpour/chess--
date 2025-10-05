#include "King.h"

#include "../Color.h"

void King::print(std::ostream& os) const {
  os << (color.get() == Color::WHITE ? "K" : "k");
};