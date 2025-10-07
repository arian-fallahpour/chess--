#ifndef _PAWN_H
#define _PAWN_H

#include <iostream>

#include "../Board.h"
#include "Piece.h"

class Pawn : public Piece {
 public:
  using Piece::Piece;

  std::vector<std::array<int, 2>> getValidMoves(
      const Board& board) const override;

  void print(std::ostream& os) const override;
};

#endif