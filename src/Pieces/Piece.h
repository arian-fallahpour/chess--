#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>

#include "../Color.h"

using std::array;
using std::vector;

class Board;
class Piece {
 public:
  Piece(Color::Value color, int row, int col);

  Color::Value getColor() const;
  const int getRow();
  const int getCol();
  void moveTo(int row, int col);
  void moveBackTo(int row, int col);
  bool isValidMove(int row, int col, const Board &board) const;

  virtual vector<array<int, 2>> getValidMoves(const Board &board) const = 0;
  virtual void print(std::ostream &os) const = 0;

  friend std::ostream &operator<<(std::ostream &os, const Piece &piece);

 protected:
  Color::Value color;
  int movesCount = 0;
  int row;
  int col;
};

#endif