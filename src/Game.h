#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <map>

#include "Boards/Board.h"
#include "Color.h"
#include "Players/Player.h"

using std::map;

class Game {
 private:
  static Game *instance;

  Game() {};

  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;

 public:
  static Game *getInstance() {
    if (instance == nullptr) {
      instance = new Game;
    }
    return instance;
  }

 public:
  enum State { PLAY, CHECKMATE, STALEMATE, DRAW };

  void start();
  void setPlayer(Player *player, Color::Value color);
  void setBoard(Board *board);
  Game::State getGameState();
  Player *getCurrentPlayer() const;

 private:
  Board *board;
  map<Color::Value, Player *> playersByColor;
  Color::Value turn{Color::Value::WHITE};

  bool isInCheckmate();
  bool isInStalemate();
  bool isInDraw();
};

#endif