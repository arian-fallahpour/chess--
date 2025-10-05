#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Board.h"
#include "Color.h"

class Game {
 public:
  void start();
  bool hasGameEnded();
  std::string getGameState();

 private:
  Board board;
  Color turn{Color::WHITE};
  bool gameEnded{false};

  void makeTurn();
};

#endif