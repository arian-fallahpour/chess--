#include "Game.h"

#include <iostream>

#include "Pieces/King.h"

using std::array;
using std::vector;

Game::Game() {};

// Game::Game(Player* whitePlayer, Player* blackPlayer)
//     : players{whitePlayer, blackPlayer} {};

void Game::start() {
  std::cout << "Game started!" << std::endl;

  while (this->getGameState() == Game::State::PLAY) {
    // Get current player to make a move

    // Check for game end conditions (checkmate, stalemate, etc.)
  }
};

void Game::makeTurn() {
  // Note: If player is in check, they must move out of check

  // Note: If player moves into check, move is invalid
};

bool Game::isInCheck(Color::Value color) {
  Color::Value enemyColor = Color::flipped(color);

  for (Piece* enemyPiece : this->board.getAlivePieces(enemyColor)) {
    vector<array<int, 2>> validMoves = enemyPiece->getValidMoves(board);

    for (array<int, 2> validMove : validMoves) {
      Piece* attackedPiece = board.getPiece(validMove[0], validMove[1]);

      if (attackedPiece != nullptr && typeid(*attackedPiece) == typeid(King) &&
          attackedPiece->getColor() == color) {
        return true;
      }
    }
  }

  return false;
};

// TEST
Game::State Game::getGameState() {
  // Check for checkmate
  if (this->isInCheck(this->turn)) {
    for (Piece* piece : this->board.getAlivePieces(this->turn)) {
      vector<array<int, 2>> validMoves = piece->getValidMoves(board);
      int fromRow = piece->getRow();
      int fromCol = piece->getCol();

      for (array<int, 2> validMove : validMoves) {
        board.movePiece(fromRow, fromCol, validMove[0], validMove[1]);
        bool stillInCheck = this->isInCheck(this->turn);
        board.undoLastMove();

        if (!stillInCheck) {
          return Game::State::PLAY;
        }
      }
    }
  }

  // Check for stalemate
  vector<array<int, 2>> allValidMoves;
  for (Piece* piece : this->board.getAlivePieces(this->turn)) {
    vector<array<int, 2>> validMoves = piece->getValidMoves(board);
    allValidMoves.insert(allValidMoves.end(), validMoves.begin(), validMoves.end());
  }

  if (allValidMoves.empty()) {
    return Game::State::STALEMATE;
  }

  // Check for draw (only kings left for now)
  if (this->board.getAlivePieces(Color::WHITE).size() == 1 &&
      this->board.getAlivePieces(Color::BLACK).size() == 1) {
    return Game::State::DRAW;
  }

  return Game::State::PLAY;
};
