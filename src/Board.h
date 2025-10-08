#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>

#include "Square.h"

class Piece;
using std::vector;

constexpr int BOARD_SIZE = 8;

class Board {
 public:
  Board();

  Square* getSquare(int row, int col) const;
  Piece* getPiece(int row, int col) const;
  void movePiece(int fromRow, int fromCol, int toRow, int toCol);

  bool isInBoard(int row, int col) const;

  friend std::ostream& operator<<(std::ostream& os, const Board& board);

 private:
  vector<Piece*> deadPieces;
  vector<Piece*> alivePieces;
  Square* grid[BOARD_SIZE][BOARD_SIZE];

  void initPiece(int row, int col, Piece* piece);
  void removeAlivePiece(Piece* piece);
  void removeDeadPiece(Piece* piece);
};

#endif
