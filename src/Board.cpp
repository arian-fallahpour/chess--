#include "Board.h"

#include <iomanip>
#include <iostream>

#include "Color.h"
#include "Move.h"
#include "Pieces/Bishop.h"
#include "Pieces/King.h"
#include "Pieces/Knight.h"
#include "Pieces/Pawn.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"

Board::Board() {
  for (int r{0}; r < BOARD_SIZE; r++) {
    for (int c{0}; c < BOARD_SIZE; c++) {
      Color::Value color = (r + c) % 2 == 0 ? Color::WHITE : Color::BLACK;
      grid[r][c] = new Square(color);
    }
  }

  this->alivePiecesByColor[Color::WHITE] = vector<Piece*>{};
  this->alivePiecesByColor[Color::BLACK] = vector<Piece*>{};
  this->deadPiecesByColor[Color::WHITE] = vector<Piece*>{};
  this->deadPiecesByColor[Color::BLACK] = vector<Piece*>{};

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

  std::cout << *this << std::endl;
};

void Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
  Square* fromSquare = this->getSquare(fromRow, fromCol);
  Piece* piece = fromSquare->getPiece();

  if (piece == nullptr) {
    throw std::invalid_argument("No piece at the source position.");
  }

  if (!piece->isValidMove(toRow, toCol, *this)) {
    throw std::invalid_argument("Invalid move for the piece.");
  }

  Square* toSquare = this->getSquare(toRow, toCol);
  Piece* capturedPiece = toSquare->getPiece();

  if (capturedPiece != nullptr) {
    this->removeAlivePiece(capturedPiece->getColor(), capturedPiece);
    this->addDeadPiece(capturedPiece->getColor(), capturedPiece);
    toSquare->removePiece();
  }

  fromSquare->removePiece();
  toSquare->placePiece(piece);
  piece->moveTo(toRow, toCol);

  Move* move = new Move(fromRow, fromCol, toRow, toCol, piece, capturedPiece);
  this->moveHistory.push(move);
};

void Board::undoLastMove() {
  Move* lastMove = this->moveHistory.top();
  this->moveHistory.pop();

  lastMove->undo(*this);
  delete lastMove;
};

void Board::initPiece(int row, int col, Piece* piece) {
  this->getSquare(row, col)->placePiece(piece);
  this->addAlivePiece(piece->getColor(), piece);
};

bool Board::isInBoard(int row, int col) const {
  return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
};

Square* Board::getSquare(int row, int col) const { return grid[row][col]; };

Piece* Board::getPiece(int row, int col) const { return this->getSquare(row, col)->getPiece(); };

vector<Piece*> Board::getAlivePieces(Color::Value color) const {
  return this->alivePiecesByColor.at(color);
};

vector<Piece*> Board::getDeadPieces(Color::Value color) const {
  return this->deadPiecesByColor.at(color);
};

void Board::addAlivePiece(Color::Value color, Piece* piece) {
  this->alivePiecesByColor.at(color).push_back(piece);
};

void Board::addDeadPiece(Color::Value color, Piece* piece) {
  this->deadPiecesByColor.at(color).push_back(piece);
};

void Board::removeAlivePiece(Color::Value color, Piece* piece) {
  vector<Piece*>& alivePieces = this->alivePiecesByColor.at(color);
  alivePieces.erase(std::remove(alivePieces.begin(), alivePieces.end(), piece), alivePieces.end());
};

void Board::removeDeadPiece(Color::Value color, Piece* piece) {
  vector<Piece*>& deadPieces = this->deadPiecesByColor.at(color);
  deadPieces.erase(std::remove(deadPieces.begin(), deadPieces.end(), piece), deadPieces.end());
};

std::ostream& operator<<(std::ostream& os, const Board& board) {
  os << "  ";
  for (int c = 0; c < BOARD_SIZE; c++) os << (c + 1) << " ";
  os << "\n";

  for (int r{0}; r < BOARD_SIZE; r++) {
    os << r + 1 << " ";

    for (int c{0}; c < BOARD_SIZE; c++) {
      os << *board.getSquare(r, c) << " ";
    }

    os << "\n";
  }

  return os;
};
