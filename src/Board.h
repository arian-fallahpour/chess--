#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <map>

#include "Square.h"

class Piece;

using std::map;
using std::vector;

constexpr int BOARD_SIZE = 8;

class Board {
 public:
  Board();

  Square* getSquare(int row, int col) const;
  Piece* getPiece(int row, int col) const;
  void movePiece(int fromRow, int fromCol, int toRow, int toCol);
  vector<Piece*> getAlivePieces(Color color) const;
  vector<Piece*> getDeadPieces(Color color) const;

  bool isInBoard(int row, int col) const;

  friend std::ostream& operator<<(std::ostream& os, const Board& board);

 private:
  map<Color::Value, vector<Piece*>> deadPiecesByColor;
  map<Color::Value, vector<Piece*>> alivePiecesByColor;
  Square* grid[BOARD_SIZE][BOARD_SIZE];

  void initPiece(int row, int col, Piece* piece);
  void addAlivePiece(Color color, Piece* piece);
  void addDeadPiece(Color color, Piece* piece);
  void removeAlivePiece(Color color, Piece* piece);
  void removeDeadPiece(Color color, Piece* piece);
};

#endif
