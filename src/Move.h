#ifndef _MOVE_H
#define _MOVE_H

#include "Board.h"
#include "Pieces/Piece.h"

class Move {
 public:
  Move(int fromRow, int fromCol, int toRow, int toCol, Piece* movedPiece);
  Move(
      int fromRow, int fromCol, int toRow, int toCol, Piece* movedPiece,
      Piece* capturedPiece = nullptr
  );
  void undo(Board& board);

 private:
  int fromRow;
  int fromCol;
  int toRow;
  int toCol;
  Piece* movedPiece;
  Piece* capturedPiece;
};

#endif