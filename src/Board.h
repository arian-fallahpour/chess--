#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>

#include "Square.h"

class Piece;
using std::vector;

constexpr int BOARD_SIZE = 8;

class Board {
 public:
  Board();

  const Square* getSquare(int row, int col) const;
  const Piece* getPiece(int row, int col) const;
  bool isInBoard(int row, int col) const;

  friend std::ostream& operator<<(std::ostream& os, const Board& board);

 private:
  vector<Piece*> deadPieces;
  Square grid[BOARD_SIZE][BOARD_SIZE];
};

#endif
