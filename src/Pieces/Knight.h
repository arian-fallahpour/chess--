#ifndef _KNIGHT_H
#define _KNIGHT_H

#include <iostream>

#include "../Boards/Board.h"
#include "Piece.h"

class Knight : public Piece {
 public:
  using Piece::Piece;

  vector<array<int, 2>> getPossibleMoves(const Board& board) const override;
  int getValue() const override;

  void print(std::ostream& os) const override;
};

#endif