#ifndef _QUEEN_H
#define _QUEEN_H

#include <iostream>

#include "Piece.h"

class Queen : public Piece {
 public:
  using Piece::Piece;

  void print(std::ostream& os) const override;
};

#endif