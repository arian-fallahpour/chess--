#ifndef _PLAYER_H
#define _PLAYER_H

#include "../Board.h"

class Player {
 public:
  Player();

  virtual void makeMove(Board& board) = 0;
};

#endif