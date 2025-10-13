#ifndef _SITUATION1_H
#define _SITUATION1_H

#include "Board.h"

class Situation1Board : public Board {
 public:
  Situation1Board();

 protected:
  void init() override;
};

#endif