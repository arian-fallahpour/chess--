#ifndef _PAWN_H
#define _PAWN_H

#include <iostream>

#include "../Boards/Board.h"
#include "Piece.h"

class Pawn : public Piece {
 public:
  using Piece::Piece;

  vector<array<int, 2>> getPossibleMoves(const Board& board) const override;
  int getValue() const override;

  void print(std::ostream& os) const override;
};

#endif