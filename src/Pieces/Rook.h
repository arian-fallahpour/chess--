#ifndef _ROOK_H
#define _ROOK_H

#include <iostream>

#include "Piece.h"

class Rook : public Piece {
 public:
  using Piece::Piece;

  void print(std::ostream& os) const override;
};

#endif