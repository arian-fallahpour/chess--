#ifndef _PAWN_H
#define _PAWN_H

#include <iostream>

#include "Piece.h"

class Pawn : public Piece {
 public:
  using Piece::Piece;

  void print(std::ostream& os) const override;
};

#endif