#include "Bishop.h"

void Bishop::print(std::ostream& os) const { os << (color.get() == Color::WHITE ? "B" : "b"); };

vector<array<int, 2>> Bishop::getValidMoves(const Board& board) const {
  vector<array<int, 2>> moves;

  const array<array<int, 2>, 4> directions = {{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}};

  for (const array<int, 2>& direction : directions) {
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
}
