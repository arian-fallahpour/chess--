#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Board.h"
#include "Color.h"
#include "Players/Player.h"

class Game {
 public:
  Game();

  void start();
  bool hasGameEnded();
  std::string getGameState();

 private:
  Board board;
  Color turn{Color::WHITE};
  Player* players[2];
  bool gameEnded{false};

  void makeTurn();
};

#endif