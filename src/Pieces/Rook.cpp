#include "Rook.h"

void Rook::print(std::ostream& os) const {
  os << (color.get() == Color::WHITE ? "R" : "r");
};

std::vector<std::array<int, 2>> Rook::getValidMoves(const Board& board) const {
  std::vector<std::array<int, 2>> moves;

  const std::array<std::array<int, 2>, 4> directions = {
      {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

  for (const std::array<int, 2>& direction : directions) {
    int r = this->row + direction[0];
    int c = this->col + direction[1];

    while (board.isInBoard(r, c)) {
      if (!board.getPiece(r, c)) {
        moves.push_back({r, c});
      } else {
        if (board.getPiece(r, c)->getColor().get() != this->color.get()) {
          moves.push_back({r, c});
        }
        break;
      }

      r += direction[0];
      c += direction[1];
    }
  };

  return moves;
};
