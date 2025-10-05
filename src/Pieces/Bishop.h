#ifndef _BISHOP_H
#define _BISHOP_H

#include <iostream>

#include "Piece.h"

class Bishop : public Piece {
 public:
  using Piece::Piece;

  void print(std::ostream& os) const override;
};

#endif