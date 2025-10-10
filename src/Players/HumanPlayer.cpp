
#include "HumanPlayer.h"

#include <iostream>

#include "../Pieces/King.h"

using std::string;

void HumanPlayer::makeMove(Board& board) const {
  King* king = board.getKing(this->color);
  bool wasInCheck = king->isInCheck(board);

  bool isMoveValid = false;
  while (!isMoveValid) {
    try {
      int fromRow{-1}, fromCol{-1}, toRow{-1}, toCol{-1};

      this->askForMove(&fromRow, &fromCol, &toRow, &toCol, board);

      std::cout << std::endl;

      if (fromRow == toRow && fromCol == toCol) {
        throw std::invalid_argument("Please move piece to a different square. Please try again.");
      }

      if (!board.isInBoard(fromRow, fromCol) || !board.isInBoard(toRow, toCol)) {
        throw std::invalid_argument("Move is invalid. Please try again.");
      }

      Piece* piece = board.getPiece(fromRow, fromCol);

      if (piece == nullptr) {
        throw std::invalid_argument("No piece at the source position. Please try again.");
      }

      if (piece->getColor() != this->color) {
        throw std::invalid_argument("You can only move your own pieces. Please try again.");
      }

      board.movePiece(fromRow, fromCol, toRow, toCol);

      bool stillInCheck = king->isInCheck(board);

      if (wasInCheck && stillInCheck) {
        board.undoLastMove();
        throw std::invalid_argument("Move must get you out of check. Please try again.");
      }

      if (!wasInCheck && stillInCheck) {
        board.undoLastMove();
        throw std::invalid_argument("Move must not put you in check. Please try again.");
      }

      // TODO: Check if pawn promotion is needed

      isMoveValid = true;
    } catch (std::invalid_argument& e) {
      std::cout << e.what() << std::endl;
    }
  }
};

void HumanPlayer::askForMove(
    int* fromRow, int* fromCol, int* toRow, int* toCol, const Board& board
) const {
  string fromStr, toStr;

  std::cout << "Choose the piece you want to move (e.g. E2): ";
  std::cin >> fromStr;

  std::cout << "Choose the destination square (e.g. E4): ";
  std::cin >> toStr;

  std::cout << std::endl;

  std::cout << "Moving piece from " << fromStr << " to " << toStr << std::endl;

  *fromRow = BOARD_SIZE - (static_cast<int>(fromStr[1]) - static_cast<int>('0'));
  *fromCol = static_cast<int>(fromStr[0]) - static_cast<int>('A');
  *toRow = BOARD_SIZE - (static_cast<int>(toStr[1]) - static_cast<int>('0'));
  *toCol = static_cast<int>(toStr[0]) - static_cast<int>('A');
};
