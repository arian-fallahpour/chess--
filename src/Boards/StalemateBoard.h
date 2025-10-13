#ifndef _STALEMATEBOARD_H
#define _STALEMATEBOARD_H

#include "Board.h"

class StalemateBoard : public Board {
 public:
  StalemateBoard();

 protected:
  void init() override;
};

#endif