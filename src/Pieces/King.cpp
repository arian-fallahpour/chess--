#include "King.h"

void King::print(std::ostream& os) const { os << (this->color == Color::WHITE ? "♚" : "♔"); };

vector<array<int, 2>> King::getPossibleMoves(const Board& board) const {
  vector<array<int, 2>> moves;

  const array<array<int, 2>, 8> directions = {
      {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}}
  };

  for (const array<int, 2>& direction : directions) {
    int r = this->row + direction[0];
    int c = this->col + direction[1];

    if (!board.isInBoard(r, c)) continue;
    if (board.getPiece(r, c) && board.getPiece(r, c)->getColor() == this->color) continue;

    moves.push_back({r, c});
  };

  return moves;
};

bool King::isInCheck(const Board& board) const {
  return board.isSquareAttacked(this->row, this->col, Color::flipped(this->color));
}

int King::getValue() const { return 1'000'000; };