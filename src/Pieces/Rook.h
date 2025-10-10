#ifndef _ROOK_H
#define _ROOK_H

#include <iostream>

#include "../Boards/Board.h"
#include "Piece.h"

class Rook : public Piece {
 public:
  using Piece::Piece;

  vector<array<int, 2>> getPossibleMoves(const Board& board) const override;

  void print(std::ostream& os) const override;
};

#endif