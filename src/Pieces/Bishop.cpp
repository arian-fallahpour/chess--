
#include "Bishop.h"

#include "../Color.h"

void Bishop::print(std::ostream& os) const {
  os << (color.get() == Color::WHITE ? "B" : "b");
};
