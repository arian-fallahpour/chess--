# chessPlusPlus

A simple C++ console chess application featuring Human vs AI play. The AI uses a minimax algorithm with alpha–beta pruning.

- Game loop and state: [`Game::start`, `Game::getGameState`](src/Game.cpp)
- AI: [`MiniMaxPlayer`](src/Players/MiniMaxPlayer.h), implementation in [src/Players/MiniMaxPlayer.cpp](src/Players/MiniMaxPlayer.cpp)
- Boards: [src/Boards/Board.h](src/Boards/Board.h) and concrete boards like [src/Boards/BasicBoard.h](src/Boards/BasicBoard.h)
- Pieces: [src/Pieces](src/Pieces)
- Entry point: [src/main.cpp](src/main.cpp)

## Features

- Human vs AI gameplay in the terminal.
- Minimax with alpha–beta pruning for the AI search.
- Material-based evaluation and endgame detection (checkmate, stalemate, draw).
- Pluggable board setups (Basic, ProtectedCheck, Stalemate).

## How it works

- The main loop is driven by [`Game::start`](src/Game.cpp), which alternates turns and prints the board.
- The AI searches moves via [`MiniMaxPlayer::minimax`](src/Players/MiniMaxPlayer.cpp) and evaluates positions in [`MiniMaxPlayer::evaluate`](src/Players/MiniMaxPlayer.cpp).
- Moves are simulated using `Board::movePiece`/`Board::undoLastMove` (see [src/Boards/Board.h](src/Boards/Board.h), [src/Boards/Board.cpp](src/Boards/Board.cpp)).

## Build

From the project root:

```sh
g++ -std=c++17 -O2 -Isrc \
  src/*.cpp src/Boards/*.cpp src/Pieces/*.cpp src/Players/*.cpp \
  -o chesspp
```

## Run

```sh
./chesspp
```

## Configure

- Players and board are set in [src/main.cpp](src/main.cpp). By default:
  - White: `HumanPlayer`
  - Black: `MiniMaxPlayer`
  - Board: `BasicBoard`
- Change AI search depth by editing [`MiniMaxPlayer::maxDepth`](src/Players/MiniMaxPlayer.h).
- Try alternative boards such as [src/Boards/ProtectedCheckBoard.h](src/Boards/ProtectedCheckBoard.h) or [src/Boards/StalemateBoard.h](src/Boards/StalemateBoard.h).

Example: swap players or boards in [src/main.cpp](src/main.cpp):

```cpp
#include "Boards/BasicBoard.h"
#include "Boards/ProtectedCheckBoard.h"
#include "Game.h"
#include "Players/HumanPlayer.h"
#include "Players/MiniMaxPlayer.h"

int main() {
  Game* game = Game::getInstance();

  HumanPlayer white{Color::Value::WHITE};
  MiniMaxPlayer black{Color::Value::BLACK};

  ProtectedCheckBoard board; // or BasicBoard

  game->setPlayer(&white, white.getColor());
  game->setPlayer(&black, black.getColor());
  game->setBoard(&board);

  game->start();
}
```

## Input

`HumanPlayer` prompts for moves as integer coordinates (fromRow, fromCol, toRow, toCol). See [`HumanPlayer::makeMove`](src/Players/HumanPlayer.h).

## Project structure

- Core:
  - [src/Game.h](src/Game.h), [src/Game.cpp](src/Game.cpp)
  - [src/Color.h](src/Color.h), [src/Move.h](src/Move.h), [src/Square.h](src/Square.h)
- Boards:
  - [src/Boards/Board.h](src/Boards/Board.h), [src/Boards/Board.cpp](src/Boards/Board.cpp)
  - [src/Boards/BasicBoard.h](src/Boards/BasicBoard.h), [src/Boards/BasicBoard.cpp](src/Boards/BasicBoard.cpp)
  - [src/Boards/ProtectedCheckBoard.h](src/Boards/ProtectedCheckBoard.h), [src/Boards/ProtectedCheckBoard.cpp](src/Boards/ProtectedCheckBoard.cpp)
  - [src/Boards/StalemateBoard.h](src/Boards/StalemateBoard.h), [src/Boards/StalemateBoard.cpp](src/Boards/StalemateBoard.cpp)
- Pieces:
  - [src/Pieces/Piece.h](src/Pieces/Piece.h), [src/Pieces/Piece.cpp](src/Pieces/Piece.cpp)
  - [src/Pieces/King.h](src/Pieces/King.h), [src/Pieces/Queen.h](src/Pieces/Queen.h), [src/Pieces/Rook.h](src/Pieces/Rook.h)
  - [src/Pieces/Bishop.h](src/Pieces/Bishop.h), [src/Pieces/Knight.h](src/Pieces/Knight.h), [src/Pieces/Pawn.h](src/Pieces/Pawn.h)
- Players:
  - [src/Players/Player.h](src/Players/Player.h)
  - [src/Players/HumanPlayer.h](src/Players/HumanPlayer.h)
  - [src/Players/MiniMaxPlayer.h](src/Players/MiniMaxPlayer.h), [src/Players/MiniMaxPlayer.cpp](src/Players/MiniMaxPlayer.cpp)

## Notes

- The AI uses alpha–beta pruning to reduce the search space. Depth can be tuned for performance vs. strength.
- Game state resolution (checkmate, stalemate, draw) is queried via [`Game::getGameState`](src/Game.cpp).
