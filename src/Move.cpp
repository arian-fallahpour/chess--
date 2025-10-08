#include "Move.h"

Move::Move(int fromRow, int fromCol, int toRow, int toCol, Piece* movedPiece)
    : Move{fromRow, fromCol, toRow, toCol, movedPiece, nullptr} {};
Move::Move(int fromRow, int fromCol, int toRow, int toCol, Piece* movedPiece, Piece* capturedPiece)
    : fromRow(fromRow),
      fromCol(fromCol),
      toRow(toRow),
      toCol(toCol),
      movedPiece(movedPiece),
      capturedPiece(capturedPiece) {};

void Move::undo(Board& board) {
  Square* fromSquare = board.getSquare(this->fromRow, this->fromCol);
  Square* toSquare = board.getSquare(this->toRow, this->toCol);

  toSquare->removePiece();
  fromSquare->placePiece(this->movedPiece);
  this->movedPiece->moveBackTo(this->fromRow, this->fromCol);

  if (this->capturedPiece != nullptr) {
    toSquare->placePiece(this->capturedPiece);
  }
}