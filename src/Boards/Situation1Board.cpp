#include "Situation1Board.h"

#include "../Pieces/Bishop.h"
#include "../Pieces/King.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Pawn.h"
#include "../Pieces/Queen.h"
#include "../Pieces/Rook.h"

Situation1Board::Situation1Board() : Board() { this->init(); };

void Situation1Board::init() {
  // Minimax test position: King and Queen endgame with pawns
  // This creates tactical opportunities for both sides

  // Black pieces
  this->initPiece(0, 4, new King(Color::BLACK, 0, 4));   // Black king on e8
  this->initPiece(2, 3, new Queen(Color::BLACK, 2, 3));  // Black queen on d6
  this->initPiece(3, 1, new Pawn(Color::BLACK, 3, 1));   // Black pawn on b5
  this->initPiece(4, 6, new Pawn(Color::BLACK, 4, 6));   // Black pawn on g4

  // White pieces
  this->initPiece(7, 4, new King(Color::WHITE, 7, 4));   // White king on e1
  this->initPiece(5, 2, new Queen(Color::WHITE, 5, 2));  // White queen on c3
  this->initPiece(4, 3, new Pawn(Color::WHITE, 4, 3));   // White pawn on d4
  this->initPiece(6, 5, new Pawn(Color::WHITE, 6, 5));   // White pawn on f2

  // Additional tactical pieces
  this->initPiece(1, 7, new Rook(Color::BLACK, 1, 7));  // Black rook on h7
  this->initPiece(6, 0, new Rook(Color::WHITE, 6, 0));  // White rook on a2
};