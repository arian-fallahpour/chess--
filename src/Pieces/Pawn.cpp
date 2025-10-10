#include "Pawn.h"

#include <iostream>

vector<array<int, 2>> Pawn::getPossibleMoves(const Board& board) const {
  vector<array<int, 2>> moves;

  int direction = (this->color == Color::WHITE) ? -1 : 1;

  if (board.isInBoard(this->row + direction, this->col) &&
      !board.getPiece(this->row + direction, this->col)) {
    moves.push_back({this->row + direction, this->col});
  }

  if (this->movesCount == 0 && board.isInBoard(this->row + direction * 2, this->col) &&
      !board.getPiece(this->row + direction * 2, this->col) &&
      !board.getPiece(this->row + direction, this->col)) {
    moves.push_back({this->row + direction * 2, this->col});
  }

  if (board.isInBoard(this->row + direction, this->col + 1) &&
      board.getPiece(this->row + direction, this->col + 1) &&
      board.getPiece(this->row + direction, this->col + 1)->getColor() != this->color) {
    moves.push_back({this->row + direction, this->col + 1});
  }

  if (board.isInBoard(this->row + direction, this->col - 1) &&
      board.getPiece(this->row + direction, this->col - 1) &&
      board.getPiece(this->row + direction, this->col - 1)->getColor() != this->color) {
    moves.push_back({this->row + direction, this->col - 1});
  }

  return moves;
}

void Pawn::print(std::ostream& os) const { os << (this->color == Color::WHITE ? "P" : "p"); }
