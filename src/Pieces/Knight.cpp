#include "Knight.h"

void Knight::print(std::ostream& os) const { os << (this->color == Color::WHITE ? "N" : "n"); };

vector<array<int, 2>> Knight::getValidMoves(const Board& board) const {
  vector<array<int, 2>> moves;

  const array<array<int, 2>, 8> offsets = {
      {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}}
  };

  for (const array<int, 2>& offset : offsets) {
    int r = this->row + offset[0];
    int c = this->col + offset[1];

    if (board.isInBoard(r, c) &&
        (!board.getPiece(r, c) || board.getPiece(r, c)->getColor() != this->color)) {
      moves.push_back({r, c});
    }
  }

  return moves;
};
