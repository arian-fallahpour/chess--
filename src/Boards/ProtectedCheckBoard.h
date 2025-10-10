#ifndef _PROTECTEDCHECKBOARD_H
#define _PROTECTEDCHECKBOARD_H

#include "Board.h"

class ProtectedCheckBoard : public Board {
 public:
  ProtectedCheckBoard();

 protected:
  void init() override;
};

#endif