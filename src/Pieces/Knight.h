#ifndef _KNIGHT_H
#define _KNIGHT_H

#include <iostream>

#include "Piece.h"

class Knight : public Piece {
 public:
  using Piece::Piece;

  void print(std::ostream& os) const override;
};

#endif