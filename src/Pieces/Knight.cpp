
#include "Knight.h"

#include "../Color.h"

void Knight::print(std::ostream& os) const {
  os << (color.get() == Color::WHITE ? "N" : "n");
};
