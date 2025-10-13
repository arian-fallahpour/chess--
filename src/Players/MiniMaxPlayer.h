#ifndef _MINIMAXPLAYER_H
#define _MINIMAXPLAYER_H

#include "../Game.h"
#include "Player.h"

class MiniMaxPlayer : public Player {
 public:
  using Player::Player;

  void makeMove(Board& board) const override;

 private:
  int maxDepth = 4;

  int minimax(Board& board, int depth, int alpha, int beta, bool isMaximizingPlayer) const;
  int evaluate(const Board& board) const;
};

#endif