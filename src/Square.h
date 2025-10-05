#ifndef _SQUARE_H
#define _SQUARE_H

#include "Color.h"

class Square {
 public:
  Square();
  Square(Color color);

 private:
  Color color;
  // Piece piece;
};

#endif