#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include <map>
#include <stack>

#include "../Square.h"

class Piece;
class Move;
class King;

using std::map;
using std::stack;
using std::vector;

constexpr int BOARD_SIZE = 8;

class Board {
 public:
  Board();

  Square* getSquare(int row, int col) const;
  Piece* getPiece(int row, int col) const;
  King* getKing(Color::Value color) const;
  vector<Piece*> getAlivePieces(Color::Value color) const;
  vector<Piece*> getDeadPieces(Color::Value color) const;
  bool isSquareAttacked(int row, int col, Color::Value attackingColor) const;
  bool isInBoard(int row, int col) const;

  void movePiece(int fromRow, int fromCol, int toRow, int toCol);
  void undoLastMove();
  void addAlivePiece(Color::Value color, Piece* piece);
  void addDeadPiece(Color::Value color, Piece* piece);
  void removeAlivePiece(Color::Value color, Piece* piece);
  void removeDeadPiece(Color::Value color, Piece* piece);

  friend std::ostream& operator<<(std::ostream& os, const Board& board);

 protected:
  Square* grid[BOARD_SIZE][BOARD_SIZE];

  virtual void init() = 0;
  void initPiece(int row, int col, Piece* piece);

 private:
  map<Color::Value, King*> kingsByColor;
  map<Color::Value, vector<Piece*>> deadPiecesByColor;
  map<Color::Value, vector<Piece*>> alivePiecesByColor;
  stack<Move*> moveHistory;
};

#endif
