#include "Game.h"

#include <iostream>

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
}

Game::State Game::getGameState() {
  // Check for checkmate
  for (Piece* piece : this->board.getAlivePieces(this->turn)) {
    // For each move, simulate the move and check if the king is still in check
    // If there's at least one move that gets the king out of check, return PLAY
  }

  // Check for stalemate

  // Check for draw

  return Game::State::PLAY;
}

void Game::makeTurn() {
  std::cout << "It is now " << this->turn.get() << "'s turn." << std::endl;

  short int moveFromX, moveFromY, moveToX, moveToY;

  std::cout << "Enter the coordinates of the piece you want to move with a space "
               "between them (e.g. '0 1'): "
            << std::endl;
  std::cin >> moveFromX >> moveFromY;

  std::cout << "Enter the coordinates of where you want to move the piece to "
               "with a space between them (e.g. '0 1'): "
            << std::endl;
  std::cin >> moveToX >> moveToY;

  this->turn = this->turn.flipped();
}
