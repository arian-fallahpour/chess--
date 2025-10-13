#include "Boards/BasicBoard.h"
#include "Boards/ProtectedCheckBoard.h"
#include "Boards/Situation1Board.h"
#include "Boards/StalemateBoard.h"
#include "Game.h"
#include "Players/HumanPlayer.h"
#include "Players/MiniMaxPlayer.h"

int main() {
  Game* game = Game::getInstance();

  HumanPlayer player1{Color::Value::WHITE};
  MiniMaxPlayer player2{Color::Value::BLACK};

  Situation1Board board;

  game->setPlayer(&player1, player1.getColor());
  game->setPlayer(&player2, player2.getColor());
  game->setBoard(&board);

  game->start();

  return 0;
}