#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <map>
#include <stack>

#include "Square.h"

class Piece;
class Move;

using std::map;
using std::stack;
using std::vector;

constexpr int BOARD_SIZE = 8;

class Board {
 public:
  Board();

  Square* getSquare(int row, int col) const;
  Piece* getPiece(int row, int col) const;
  void movePiece(int fromRow, int fromCol, int toRow, int toCol);
  void undoLastMove();
  vector<Piece*> getAlivePieces(Color::Value color) const;
  vector<Piece*> getDeadPieces(Color::Value color) const;
  void addAlivePiece(Color::Value color, Piece* piece);
  void addDeadPiece(Color::Value color, Piece* piece);
  void removeAlivePiece(Color::Value color, Piece* piece);
  void removeDeadPiece(Color::Value color, Piece* piece);

  bool isInBoard(int row, int col) const;

  friend std::ostream& operator<<(std::ostream& os, const Board& board);

 private:
  map<Color::Value, vector<Piece*>> deadPiecesByColor;
  map<Color::Value, vector<Piece*>> alivePiecesByColor;
  Square* grid[BOARD_SIZE][BOARD_SIZE];
  stack<Move*> moveHistory;

  void initPiece(int row, int col, Piece* piece);
};

#endif
