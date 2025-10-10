#ifndef _BASICBOARD_H
#define _BASICBOARD_H

#include "Board.h"

class BasicBoard : public Board {
 public:
  BasicBoard();

 protected:
  void init() override;
};

#endif