#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>

#include "Pieces/Piece.h"
#include "Square.h"

using std::vector;

constexpr int BOARD_SIZE = 8;

class Board {
 public:
  Board();

  friend std::ostream& operator<<(std::ostream& os, const Board& board);

 private:
  vector<Piece*> deadPieces;
  Square grid[BOARD_SIZE][BOARD_SIZE];
};

#endif
