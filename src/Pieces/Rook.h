#ifndef _ROOK_H
#define _ROOK_H

#include <iostream>

#include "../Board.h"
#include "Piece.h"

class Rook : public Piece {
 public:
  using Piece::Piece;

  std::vector<std::array<int, 2>> getValidMoves(
      const Board& board) const override;

  void print(std::ostream& os) const override;
};

#endif