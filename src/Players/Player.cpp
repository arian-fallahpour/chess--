#include "Player.h"

Player::Player(Color::Value color) : color(color) {}

Color::Value Player::getColor() const { return this->color; }