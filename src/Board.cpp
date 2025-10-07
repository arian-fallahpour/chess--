#include "Board.h"

#include <iomanip>
#include <iostream>

#include "Color.h"
#include "Pieces/Bishop.h"
#include "Pieces/King.h"
#include "Pieces/Knight.h"
#include "Pieces/Pawn.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"

Board::Board() {
  for (int r{0}; r < BOARD_SIZE; r++) {
    for (int c{0}; c < BOARD_SIZE; c++) {
      Color* color = new Color((r + c) % 2 == 0 ? Color::WHITE : Color::BLACK);
      grid[r][c] = Square(*color);
    }
  }

  for (int c{0}; c < BOARD_SIZE; c++) {
    grid[1][c].placePiece(new Pawn(Color::BLACK, 1, c));
    grid[6][c].placePiece(new Pawn(Color::WHITE, 6, c));
  }
  grid[0][0].placePiece(new Rook(Color::BLACK, 0, 0));
  grid[0][7].placePiece(new Rook(Color::BLACK, 0, 7));
  grid[7][0].placePiece(new Rook(Color::WHITE, 7, 0));
  grid[7][7].placePiece(new Rook(Color::WHITE, 7, 7));
  grid[0][1].placePiece(new Knight(Color::BLACK, 0, 1));
  grid[0][6].placePiece(new Knight(Color::BLACK, 0, 6));
  grid[7][1].placePiece(new Knight(Color::WHITE, 7, 1));
  grid[7][6].placePiece(new Knight(Color::WHITE, 7, 6));
  grid[0][2].placePiece(new Bishop(Color::BLACK, 0, 2));
  grid[0][5].placePiece(new Bishop(Color::BLACK, 0, 5));
  grid[7][2].placePiece(new Bishop(Color::WHITE, 7, 2));
  grid[7][5].placePiece(new Bishop(Color::WHITE, 7, 5));
  grid[0][3].placePiece(new Queen(Color::BLACK, 0, 3));
  grid[7][3].placePiece(new Queen(Color::WHITE, 7, 3));
  grid[0][4].placePiece(new King(Color::BLACK, 0, 4));
  grid[7][4].placePiece(new King(Color::WHITE, 7, 4));

  std::cout << *this << std::endl;

  // std::vector<std::array<int, 2>> moves =
  //     grid[0][0].getPiece()->getValidMoves(*this);

  // for (const auto& move : moves) {
  //   std::cout << "Move: (" << move[0] << ", " << move[1] << ")\n";
  // }
}

const Square* Board::getSquare(int row, int col) const {
  return &grid[row][col];
}

const Piece* Board::getPiece(int row, int col) const {
  return this->getSquare(row, col)->getPiece();
}

bool Board::isInBoard(int row, int col) const {
  return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
  os << "  ";
  for (int c = 0; c < BOARD_SIZE; c++) os << (c + 1) << " ";
  os << "\n";

  for (int r{0}; r < BOARD_SIZE; r++) {
    os << r + 1 << " ";

    for (int c{0}; c < BOARD_SIZE; c++) {
      os << board.grid[r][c] << " ";
    }

    os << "\n";
  }

  return os;
}
