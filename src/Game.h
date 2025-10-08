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

 private:
  Board board;
  Color::Value turn{Color::Value::WHITE};
  Player* players[2];

  void makeTurn();
  bool isInCheck(Color::Value color);
  Game::State getGameState();
};

#endif