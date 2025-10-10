#ifndef _PLAYER_H
#define _PLAYER_H

#include "../Boards/Board.h"
#include "../Color.h"

class Player {
 public:
  Player(Color::Value color);

  virtual void makeMove(Board& board) const = 0;
  Color::Value getColor() const;

 protected:
  Color::Value color;
};

#endif