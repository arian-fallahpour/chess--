#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>

#include "../Color.h"

class Piece {
 public:
  Piece();
  Piece(Color color);

  virtual void print(std::ostream& os) const;
  friend std::ostream& operator<<(std::ostream& os, const Piece& piece);

 protected:
  Color color;
};

#endif