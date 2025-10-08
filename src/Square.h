#ifndef _SQUARE_H
#define _SQUARE_H

#include <iostream>

#include "Color.h"
#include "Pieces/Piece.h"

class Square {
 public:
  Square();
  Square(Color::Value color);
  Square(Color::Value color, Piece* piece);

  void placePiece(Piece* piece);
  Piece* removePiece();
  Piece* getPiece() const;

  friend std::ostream& operator<<(std::ostream& os, const Square& square);

 private:
  Color::Value color;
  Piece* piece = nullptr;
};

#endif