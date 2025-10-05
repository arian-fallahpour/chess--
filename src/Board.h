#ifndef _BOARD_H
#define _BOARD_H

#include "Square.h"

constexpr int BOARD_SIZE = 8;

class Board {
 public:
  Board();

 private:
  Square grid[BOARD_SIZE][BOARD_SIZE];
};

#endif
