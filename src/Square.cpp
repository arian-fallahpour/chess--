#include "Square.h"

#include <iostream>
#include <ostream>

Square::Square() : Square{Color::WHITE, nullptr} {};
Square::Square(Color color) : Square{color, nullptr} {};
Square::Square(Color color, Piece* piece = nullptr)
    : color(color), piece(piece) {};

void Square::placePiece(Piece* piece) { this->piece = piece; };

Piece* Square::removePiece() { return std::exchange(this->piece, nullptr); }

Piece* Square::getPiece() const { return this->piece; };

std::ostream& operator<<(std::ostream& os, const Square& square) {
  if (square.piece != nullptr) {
    os << *(square.piece);
  } else {
    if (square.color.get() == Color::WHITE)
      os << "■";
    else {
      os << "□";
    }
  }

  return os;
}