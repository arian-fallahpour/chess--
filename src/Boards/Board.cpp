#include "Board.h"

#include <iomanip>
#include <iostream>

#include "../Color.h"
#include "../Move.h"
#include "../Pieces/King.h"

Board::Board() {
  for (int r{0}; r < BOARD_SIZE; r++) {
    for (int c{0}; c < BOARD_SIZE; c++) {
      Color::Value color = (r + c) % 2 == 0 ? Color::WHITE : Color::BLACK;
      grid[r][c] = new Square(color);
    }
  }

  this->kingsByColor[Color::Value::WHITE] = nullptr;
  this->kingsByColor[Color::Value::BLACK] = nullptr;
  this->alivePiecesByColor[Color::Value::WHITE] = vector<Piece*>{};
  this->alivePiecesByColor[Color::Value::BLACK] = vector<Piece*>{};
  this->deadPiecesByColor[Color::Value::WHITE] = vector<Piece*>{};
  this->deadPiecesByColor[Color::Value::BLACK] = vector<Piece*>{};
};

void Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
  if (fromRow == toRow && fromCol == toCol) {
    throw std::invalid_argument("Please move piece to a different square. Please try again.");
  }

  Square* fromSquare = this->getSquare(fromRow, fromCol);
  Piece* piece = fromSquare->getPiece();

  if (piece == nullptr) {
    throw std::invalid_argument("Please select a square with a piece.");
  }

  if (!piece->isValidMove(toRow, toCol, *this)) {
    throw std::invalid_argument("Invalid move. Please try again.");
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

  if (King* kingPiece = dynamic_cast<King*>(piece)) {
    this->kingsByColor[kingPiece->getColor()] = kingPiece;
  }
};

Square* Board::getSquare(int row, int col) const { return grid[row][col]; };

Piece* Board::getPiece(int row, int col) const { return this->getSquare(row, col)->getPiece(); };

King* Board::getKing(Color::Value color) const { return this->kingsByColor.at(color); }

bool Board::isSquareAttacked(int row, int col, Color::Value attackingColor) const {
  for (Piece* piece : this->getAlivePieces(attackingColor)) {
    vector<array<int, 2>> possibleMoves = piece->getPossibleMoves(*this);

    for (array<int, 2> validMove : possibleMoves) {
      if (row == validMove[0] && col == validMove[1]) {
        return true;
      }
    }
  }

  return false;
};

bool Board::isInBoard(int row, int col) const {
  return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
};

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
  for (int r{0}; r < BOARD_SIZE; r++) {
    os << BOARD_SIZE - r << " ";

    for (int c{0}; c < BOARD_SIZE; c++) {
      os << *board.getSquare(r, c) << " ";
    }

    os << "\n";
  }

  os << "  ";
  for (int c = 0; c < BOARD_SIZE; c++) os << static_cast<char>(static_cast<int>('A') + c) << " ";
  os << "\n";

  return os;
};
