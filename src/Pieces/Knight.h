#ifndef _KNIGHT_H
#define _KNIGHT_H

#include <iostream>

#include "../Board.h"
#include "Piece.h"

class Knight : public Piece {
 public:
  using Piece::Piece;

  std::vector<std::array<int, 2>> getValidMoves(
      const Board& board) const override;

  void print(std::ostream& os) const override;
};

#endif