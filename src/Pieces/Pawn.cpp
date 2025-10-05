#include "Pawn.h"

#include "../Color.h"

void Pawn::print(std::ostream& os) const {
  os << (color.get() == Color::WHITE ? "P" : "p");
}
