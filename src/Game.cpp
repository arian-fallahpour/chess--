#include "Game.h"

#include <iostream>

#include "Pieces/King.h"

using std::array;
using std::vector;

Game* Game::instance = nullptr;

void Game::start() {
  // Optional: Check if certain conditions are met before starting the game

  std::cout << std::endl;

  std::cout << "Game started!" << std::endl;

  while (this->getGameState() == Game::State::PLAY) {
    std::cout << *this->board << std::endl;

    std::cout << "It is now " << Color(this->turn) << "'s turn." << std::endl << std::endl;

    Player* currentPlayer = this->getCurrentPlayer();
    currentPlayer->makeMove(*this->board);

    this->turn = Color::flipped(this->turn);
  }

  std::cout << *this->board << std::endl;

  Game::State finalState = this->getGameState();
  if (finalState == Game::State::CHECKMATE) {
    std::cout << "Checkmate!" << std::endl;
    std::cout << std::endl;
    std::cout << Color(Color::flipped(this->turn)) << " wins!" << std::endl;
  } else if (finalState == Game::State::STALEMATE) {
    std::cout << "Stalemate! It's a draw!" << std::endl;
  } else if (finalState == Game::State::DRAW) {
    std::cout << "It's a draw!" << std::endl;
  }

  std::cout << std::endl;
};

void Game::setPlayer(Player* player, Color::Value color) { this->playersByColor[color] = player; };

void Game::setBoard(Board* board) { this->board = board; };

Player* Game::getCurrentPlayer() const { return this->playersByColor.at(this->turn); };

Game::State Game::getGameState() {
  if (this->isInCheckmate()) {
    return Game::State::CHECKMATE;
  }

  if (this->isInStalemate()) {
    return Game::State::STALEMATE;
  }

  if (this->isInDraw()) {
    return Game::State::DRAW;
  }

  return Game::State::PLAY;
};

bool Game::isInCheckmate() {
  King* king = this->board->getKing(this->turn);
  vector<Piece*> pieces = this->board->getAlivePieces(this->turn);

  if (king->isInCheck(*this->board)) {
    bool canEscapeCheck = false;

    for (Piece* piece : pieces) {
      vector<array<int, 2>> possibleMoves = piece->getPossibleMoves(*this->board);

      for (array<int, 2> possibleMove : possibleMoves) {
        this->board->movePiece(piece->getRow(), piece->getCol(), possibleMove[0], possibleMove[1]);
        bool stillInCheck = king->isInCheck(*this->board);
        this->board->undoLastMove();

        if (!stillInCheck) {
          canEscapeCheck = true;
          break;
        }
      }
    }

    if (!canEscapeCheck) {
      return true;
    }
  }

  return false;
};

bool Game::isInStalemate() {
  vector<Piece*> pieces = this->board->getAlivePieces(this->turn);

  vector<array<int, 2>> allValidMoves;
  for (Piece* piece : pieces) {
    vector<array<int, 2>> possibleMoves = piece->getPossibleMoves(*this->board);

    King* king = static_cast<King*>(piece);
    if (king != nullptr) {
      for (array<int, 2> possibleMove : possibleMoves) {
        if (!this->board->isSquareAttacked(
                possibleMove[0], possibleMove[1], Color::flipped(this->turn)
            )) {
          allValidMoves.push_back(possibleMove);
        }
      }
    } else {
      allValidMoves.insert(allValidMoves.end(), possibleMoves.begin(), possibleMoves.end());
    }
  };

  return allValidMoves.size() == 0;
};

bool Game::isInDraw() {
  return this->board->getAlivePieces(Color::WHITE).size() == 1 &&
         this->board->getAlivePieces(Color::BLACK).size() == 1;
};
