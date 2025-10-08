#ifndef _KING_H
#define _KING_H

#include "../Board.h"
#include "Piece.h"

class King : public Piece {
 public:
  using Piece::Piece;

  vector<array<int, 2>> getValidMoves(const Board& board) const override;

  void print(std::ostream& os) const override;
};

#endif