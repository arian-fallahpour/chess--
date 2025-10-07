#include "Piece.h"

#include <iostream>

Piece::Piece(Color color, int row, int col)
    : color(color), row(row), col(col) {}

Color Piece::getColor() const { return this->color; }

bool Piece::isValidMove(int row, int col, const Board& board) const {
  std::vector<std::array<int, 2>> moves = this->getValidMoves(board);

  for (const std::array<int, 2>& move : moves) {
    if (row == move[0] && col == move[1]) return true;
  }

  return false;
}

void Piece::moveTo(int row, int col) {
  this->row = row;
  this->col = col;
  movesCount++;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
  piece.print(os);
  return os;
}