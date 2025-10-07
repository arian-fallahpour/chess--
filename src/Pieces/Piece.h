#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>

#include "../Color.h"

class Board;
class Piece {
 public:
  Piece(Color color, int row, int col);

  void moveTo(int row, int col);
  Color getColor() const;

  virtual std::vector<std::array<int, 2>> getValidMoves(
      const Board& board) const = 0;
  bool isValidMove(int row, int col, const Board& board) const;
  virtual void print(std::ostream& os) const = 0;

  friend std::ostream& operator<<(std::ostream& os, const Piece& piece);

 protected:
  Color color;
  int movesCount = 0;
  int row;
  int col;
};

#endif