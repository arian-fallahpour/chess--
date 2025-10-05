#ifndef _COLOR_H
#define _COLOR_H

class Color {
 public:
  enum Value { WHITE, BLACK };

  Color::Value get() const;
  Color::Value flipped() const;

  Color(Value value) : value(value) {};

 private:
  Value value;
};

#endif