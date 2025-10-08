#ifndef _QUEEN_H
#define _QUEEN_H

#include <iostream>

#include "../Board.h"
#include "Piece.h"

class Queen : public Piece {
 public:
  using Piece::Piece;

  vector<array<int, 2>> getValidMoves(const Board& board) const override;

  void print(std::ostream& os) const override;
};

#endif