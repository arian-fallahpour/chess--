#include "ProtectedCheckBoard.h"

#include "../Pieces/Bishop.h"
#include "../Pieces/King.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Pawn.h"
#include "../Pieces/Queen.h"
#include "../Pieces/Rook.h"

ProtectedCheckBoard::ProtectedCheckBoard() : Board() { this->init(); };

void ProtectedCheckBoard::init() {
  this->initPiece(0, 5, new Rook(Color::BLACK, 0, 5));
  this->initPiece(6, 5, new Queen(Color::BLACK, 6, 5));

  this->initPiece(0, 4, new King(Color::BLACK, 0, 4));
  this->initPiece(7, 5, new King(Color::WHITE, 7, 5));
};