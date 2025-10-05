#include "Queen.h"

#include "../Color.h"

void Queen::print(std::ostream& os) const {
  os << (color.get() == Color::WHITE ? "Q" : "q");
};
