#include "King.h"

void King::print(std::ostream& os) const {
  os << (color.get() == Color::WHITE ? "K" : "k");
};

std::vector<std::array<int, 2>> King::getValidMoves(const Board& board) const {
  std::vector<std::array<int, 2>> moves;

  const std::array<std::array<int, 2>, 8> directions = {
      {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}}};

  for (const std::array<int, 2>& direction : directions) {
    int r = this->row + direction[0];
    int c = this->col + direction[1];

    if (board.isInBoard(r, c)) {
      if (!board.getPiece(r, c)) {
        moves.push_back({r, c});
      } else {
        if (board.getPiece(r, c)->getColor().get() != this->color.get()) {
          moves.push_back({r, c});
        }
      }
    }
  };

  // Determine which moves would place the king in check and remove them from
  // the list Loop over all alivePieces

  return moves;
};
