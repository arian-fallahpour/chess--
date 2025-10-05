#include "Piece.h"

#include <iostream>

#include "../Color.h"

Piece::Piece() : Piece{Color::WHITE} {}
Piece::Piece(Color color) : color(color) {}

void Piece::print(std::ostream& os) const { os << "?"; }
std::ostream& operator<<(std::ostream& os, const Piece& piece) {
  piece.print(os);
  return os;
}