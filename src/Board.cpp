#include "Board.h"

Board::Board() {
  for (int r{0}; r < BOARD_SIZE; r++) {
    for (int c{0}; c < BOARD_SIZE; c++) {
      grid[r][c] = Square(((r + c) % 2 == 0) ? Color::WHITE : Color::BLACK);
    }
  }
}