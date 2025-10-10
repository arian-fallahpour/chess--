#ifndef _KING_H
#define _KING_H

#include "../Boards/Board.h"
#include "Piece.h"

class King : public Piece {
 public:
  using Piece::Piece;

  vector<array<int, 2>> getPossibleMoves(const Board& board) const override;
  bool isInCheck(const Board& board) const;

  void print(std::ostream& os) const override;
};

#endif