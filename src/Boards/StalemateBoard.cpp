#include "StalemateBoard.h"

#include "../Pieces/Bishop.h"
#include "../Pieces/King.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Pawn.h"
#include "../Pieces/Queen.h"
#include "../Pieces/Rook.h"

StalemateBoard::StalemateBoard() : Board() { this->init(); };

void StalemateBoard::init() {
  this->initPiece(0, 6, new Rook(Color::BLACK, 0, 6));
  this->initPiece(6, 0, new Rook(Color::BLACK, 6, 0));

  this->initPiece(0, 0, new King(Color::BLACK, 0, 0));
  this->initPiece(7, 7, new King(Color::WHITE, 7, 7));
};