#include "Rook.h"

#include "../Color.h"

void Rook::print(std::ostream& os) const {
  os << (color.get() == Color::WHITE ? "R" : "r");
};
