#ifndef _KING_H
#define _KING_H

#include "Piece.h"

class King : public Piece {
 public:
  using Piece::Piece;

  void print(std::ostream& os) const override;
};

#endif