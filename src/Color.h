#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>

class Color {
 public:
  enum Value { WHITE, BLACK };

  Color(Value value) : value(value) {};

  static Color::Value flipped(Color::Value color);

  friend std::ostream& operator<<(std::ostream& os, const Color& color);

 private:
  Value value;
};

#endif