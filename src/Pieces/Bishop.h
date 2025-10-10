#ifndef _BISHOP_H
#define _BISHOP_H

#include <iostream>

#include "../Boards/Board.h"
#include "Piece.h"

class Bishop : public Piece {
 public:
  using Piece::Piece;

  vector<array<int, 2>> getPossibleMoves(const Board& board) const override;

  void print(std::ostream& os) const override;
};

#endif