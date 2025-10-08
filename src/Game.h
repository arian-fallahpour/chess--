#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Board.h"
#include "Color.h"
#include "Players/Player.h"

class Game {
 public:
  enum State { PLAY, CHECKMATE, STALEMATE, DRAW };

  Game();

  void start();
  Game::State getGameState();

 private:
  Board board;
  Color turn{Color::WHITE};
  Player* players[2];

  void makeTurn();
};

#endif