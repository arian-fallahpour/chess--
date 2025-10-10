#include "Boards/BasicBoard.h"
#include "Boards/ProtectedCheckBoard.h"
#include "Game.h"
#include "Players/HumanPlayer.h"

int main() {
  Game* game = Game::getInstance();

  HumanPlayer player1{Color::Value::WHITE};
  HumanPlayer player2{Color::Value::BLACK};

  ProtectedCheckBoard board;

  game->setPlayer(&player1, player1.getColor());
  game->setPlayer(&player2, player2.getColor());
  game->setBoard(&board);

  game->start();

  return 0;
}