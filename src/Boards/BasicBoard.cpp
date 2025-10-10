#include "BasicBoard.h"

#include "../Pieces/Bishop.h"
#include "../Pieces/King.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Pawn.h"
#include "../Pieces/Queen.h"
#include "../Pieces/Rook.h"

BasicBoard::BasicBoard() : Board() { this->init(); };

void BasicBoard::init() {
  for (int c{0}; c < BOARD_SIZE; c++) {
    this->initPiece(1, c, new Pawn(Color::BLACK, 1, c));
    this->initPiece(6, c, new Pawn(Color::WHITE, 6, c));
  }
  this->initPiece(0, 0, new Rook(Color::BLACK, 0, 0));
  this->initPiece(0, 7, new Rook(Color::BLACK, 0, 7));
  this->initPiece(7, 0, new Rook(Color::WHITE, 7, 0));
  this->initPiece(7, 7, new Rook(Color::WHITE, 7, 7));
  this->initPiece(0, 1, new Knight(Color::BLACK, 0, 1));
  this->initPiece(0, 6, new Knight(Color::BLACK, 0, 6));
  this->initPiece(7, 1, new Knight(Color::WHITE, 7, 1));
  this->initPiece(7, 6, new Knight(Color::WHITE, 7, 6));
  this->initPiece(0, 2, new Bishop(Color::BLACK, 0, 2));
  this->initPiece(0, 5, new Bishop(Color::BLACK, 0, 5));
  this->initPiece(7, 2, new Bishop(Color::WHITE, 7, 2));
  this->initPiece(7, 5, new Bishop(Color::WHITE, 7, 5));
  this->initPiece(0, 3, new Queen(Color::BLACK, 0, 3));
  this->initPiece(7, 3, new Queen(Color::WHITE, 7, 3));
  this->initPiece(0, 4, new King(Color::BLACK, 0, 4));
  this->initPiece(7, 4, new King(Color::WHITE, 7, 4));
};