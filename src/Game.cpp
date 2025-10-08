#include "Game.h"

#include <iostream>

Game::Game() {};

// Game::Game(Player* whitePlayer, Player* blackPlayer)
//     : players{whitePlayer, blackPlayer} {};

void Game::start() {
  std::cout << "Game started!" << std::endl;

  while (!this->gameEnded) {
    // Get current player to make a move

    // Check for game end conditions (checkmate, stalemate, etc.)
  }
}

bool Game::hasGameEnded() { return this->gameEnded; }

std::string Game::getGameState() { return "play"; }

void Game::makeTurn() {
  std::cout << "It is now " << this->turn.get() << "'s turn." << std::endl;

  short int moveFromX, moveFromY, moveToX, moveToY;

  std::cout
      << "Enter the coordinates of the piece you want to move with a space "
         "between them (e.g. '0 1'): "
      << std::endl;
  std::cin >> moveFromX >> moveFromY;

  std::cout << "Enter the coordinates of where you want to move the piece to "
               "with a space between them (e.g. '0 1'): "
            << std::endl;
  std::cin >> moveToX >> moveToY;

  this->turn = this->turn.flipped();
}
