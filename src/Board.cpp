#include "Board.h"

#include <iostream>

#include "Color.h"
#include "Pieces/Bishop.h"
#include "Pieces/King.h"
#include "Pieces/Knight.h"
#include "Pieces/Pawn.h"
#include "Pieces/Piece.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"

Board::Board() {
  for (int r{0}; r < BOARD_SIZE; r++) {
    for (int c{0}; c < BOARD_SIZE; c++) {
      Piece* piece = nullptr;

      if (r == 1) {
        piece = new Pawn(Color::BLACK);
      } else if (r == 6) {
        piece = new Pawn(Color::WHITE);
      } else if (r == 0 && (c == 0 || c == 7)) {
        piece = new Rook(Color::BLACK);
      } else if (r == 7 && (c == 0 || c == 7)) {
        piece = new Rook(Color::WHITE);

      } else if (r == 0 && (c == 1 || c == 6)) {
        piece = new Knight(Color::BLACK);
      } else if (r == 7 && (c == 1 || c == 6)) {
        piece = new Knight(Color::WHITE);

      } else if (r == 0 && (c == 2 || c == 5)) {
        piece = new Bishop(Color::BLACK);
      } else if (r == 7 && (c == 2 || c == 5)) {
        piece = new Bishop(Color::WHITE);

      } else if (r == 0 && c == 3) {
        piece = new Queen(Color::BLACK);
      } else if (r == 7 && c == 3) {
        piece = new Queen(Color::WHITE);

      } else if (r == 0 && c == 4) {
        piece = new King(Color::BLACK);
      } else if (r == 7 && c == 4) {
        piece = new King(Color::WHITE);
      }

      Color* color = nullptr;
      if ((r + c) % 2 == 0) {
        color = new Color(Color::WHITE);
      } else {
        color = new Color(Color::BLACK);
      }

      grid[r][c] = Square(*color, piece);
    }
  }

  std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
  os << "  ";
  for (int c = 0; c < BOARD_SIZE; c++) {
    os << (c + 1) << " ";
  }
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
