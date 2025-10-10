#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
 public:
  using Player::Player;

  void makeMove(Board& board) const override;

 private:
  void askForMove(int* fromRow, int* fromCol, int* toRow, int* toCol, const Board& board) const;
};

#endif